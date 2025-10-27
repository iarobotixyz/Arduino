// ------------------------------------------------------------
// RoboticaXYZ - Monitor sísmico ESP32 (versión 2025)
// Ahora compara sismos por fecha/hora en lugar de título
// ------------------------------------------------------------
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "INFINITUMAF55";   // Cambia a tu red WiFi
const char* password = "4TKXHT3sYH";  // Cambia a tu contraseña
const char* url = "http://www.ssn.unam.mx/rss/ultimos-sismos.xml";

String ultimaFechaHora = "";   // <-- Ahora comparamos usando fecha/hora
unsigned long anteriorMillis = 0;
const unsigned long intervalo = 60000; // 1 minuto

const int led = 2;
const int rele = 26;

void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  pinMode(rele, OUTPUT);

  Serial.println("\n🌐 Conectando a WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(led, !digitalRead(led));
    delay(500);
    Serial.print(".");
  }

  digitalWrite(led, LOW);
  digitalWrite(rele, LOW);

  Serial.println("\n✅ Conectado a WiFi!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  unsigned long actualMillis = millis();
  if (actualMillis - anteriorMillis >= intervalo) {
    anteriorMillis = actualMillis;
    obtenerSismo();
  }
}

void obtenerSismo() {
  if (WiFi.status() == WL_CONNECTED) {

    HTTPClient http;
    http.begin(url);
    int code = http.GET();

    if (code == 200) {

      String xml = http.getString();

      // Tomar solo primer <item> (último sismo)
      int itemStart = xml.indexOf("<item>");
      int itemEnd   = xml.indexOf("</item>", itemStart);
      if (itemStart < 0 || itemEnd < 0) return;
      String item = xml.substring(itemStart, itemEnd);

      // ---- Extraer Título ----
      int t1 = item.indexOf("<title>");
      int t2 = item.indexOf("</title>", t1);
      String titulo = item.substring(t1 + 7, t2);
      titulo.trim();

      // ---- Extraer Descripción ----
      int d1 = item.indexOf("<description>");
      int d2 = item.indexOf("</description>", d1);
      String desc = item.substring(d1 + 13, d2);

      desc.replace("<![CDATA[", "");
      desc.replace("]]>", "");
      desc.replace("<p>", "");
      desc.replace("</p>", "");
      desc.replace("<br/>", "\n");

      // ---- Extraer Fecha/Hora ----
      // Ejemplo: Fecha:2025-10-26 14:06:05 (Hora de México)
      String fechaHora = desc.substring(desc.indexOf("Fecha:") + 6, desc.indexOf("\n"));
      fechaHora.trim();
      //Serial.println("Fecha/Hora  : " + fechaHora);
      //Serial.println("UFecha/Hora  : " + ultimaFechaHora);
      
      // ---- Si la fecha/hora es la misma → No hay nuevo sismo ----
      if (fechaHora == ultimaFechaHora) {
        Serial.println("⏳ Sin nuevos sismos...");
        http.end();
        return;
      }

      // ---- Extraer latitud y longitud ----
      int lat1 = item.indexOf("<geo:lat>");
      int lat2 = item.indexOf("</geo:lat>");
      String lat = item.substring(lat1 + 9, lat2);

      int lon1 = item.indexOf("<geo:long>");
      int lon2 = item.indexOf("</geo:long>");
      String lon = item.substring(lon1 + 10, lon2);

      // ---- Extraer profundidad ----
      String profundidad = desc.substring(desc.indexOf("Profundidad:") + 12);
      profundidad.trim();

      // ---- Mostrar datos ----
      Serial.println("\n===== NUEVO SISMO DETECTADO =====");
      Serial.println("Título      : " + titulo);
      Serial.println("Fecha/Hora  : " + fechaHora);
      Serial.println("Latitud     : " + lat);
      Serial.println("Longitud    : " + lon);
      Serial.println("Profundidad : " + profundidad);
      Serial.println("=================================\n");

      // Guardar fecha/hora para referencia futura
      ultimaFechaHora = fechaHora;

      // Activar alerta
      parpadear(5);

    } else {
      Serial.print("⚠️ Error HTTP: ");
      Serial.println(code);
    }

    http.end();

  } else {
    Serial.println("❌ WiFi desconectado, reconectando...");
    WiFi.reconnect();
  }
}

void parpadear(int veces) {
  for (int i = 0; i < veces; i++) {
    digitalWrite(led, HIGH);
    digitalWrite(rele, HIGH);
    delay(300);
    digitalWrite(led, LOW);
    digitalWrite(rele, LOW);
    delay(300);
  }
}
