// ------------------------------------------------------------
// RoboticaXYZ - Monitor sísmico ESP32 (versión funcional 2025)
// Basado en lector RSS del SSN (http://www.ssn.unam.mx/rss/ultimos-sismos.xml)
// ------------------------------------------------------------
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "INFINITUMAF55";         // 🔸 Cambia por tu red WiFi
const char* password = "4TKXHT3sYH"; // 🔸 Cambia por tu contraseña
const char* url = "http://www.ssn.unam.mx/rss/ultimos-sismos.xml";

String ultimoTitulo = "";
unsigned long anteriorMillis = 0;
const unsigned long intervalo = 60000; // 1 minuto
const int led = 2; // LED integrado en muchas placas ESP32
const int rele= 26; // Rele Manda la señal alerta, Sirena, Luz, Etc.


void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  pinMode(rele, OUTPUT);
  Serial.println("\n🌐 Conectando a WiFi...");

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(led, !digitalRead(led)); // parpadea mientras conecta
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

      // Tomar solo el PRIMER <item>
      int itemStart = xml.indexOf("<item>");
      int itemEnd   = xml.indexOf("</item>", itemStart);
      if (itemStart < 0 || itemEnd < 0) {
        Serial.println("⚠️ No se encontraron datos de sismo");
        return;
      }

      String item = xml.substring(itemStart, itemEnd);

      // Extraer título
      int t1 = item.indexOf("<title>");
      int t2 = item.indexOf("</title>", t1);
      String titulo = item.substring(t1 + 7, t2);
      titulo.trim();

      // Extraer descripción (en ella viene fecha, hora, profundidad)
      int d1 = item.indexOf("<description>");
      int d2 = item.indexOf("</description>", d1);
      String desc = item.substring(d1 + 13, d2);

      // Limpiar etiquetas HTML
      desc.replace("<![CDATA[", "");
      desc.replace("]]>", "");
      desc.replace("<p>", "");
      desc.replace("</p>", "");
      desc.replace("<br/>", "\n");

      // Extraer latitud y longitud de sus etiquetas geo:
      int lat1 = item.indexOf("<geo:lat>");
      int lat2 = item.indexOf("</geo:lat>");
      String lat = item.substring(lat1 + 9, lat2);

      int lon1 = item.indexOf("<geo:long>");
      int lon2 = item.indexOf("</geo:long>");
      String lon = item.substring(lon1 + 10, lon2);

      // Separar datos dentro de descripcion
      // Ejemplo:
      // Fecha:2025-10-26 14:06:05 (Hora de México)
      // Lat/Lon: 16.875/-100.059
      // Profundidad: 8.5 km
      String fechaHora = desc.substring(desc.indexOf("Fecha:" ) + 6, desc.indexOf("\n"));
      fechaHora.trim();

      String profundidad = desc.substring(desc.indexOf("Profundidad:") + 12);
      profundidad.trim();

      // Evitar repetir sismo
      if (titulo != ultimoTitulo) {

        Serial.println("\n===== NUEVO SISMO DETECTADO =====");
        Serial.println("Título      : " + titulo);
        Serial.println("Fecha/Hora  : " + fechaHora);
        Serial.println("Latitud     : " + lat);
        Serial.println("Longitud    : " + lon);
        Serial.println("Profundidad : " + profundidad);
        Serial.println("=================================\n");

        parpadear(5);
        ultimoTitulo = titulo;

      } else {
        Serial.println("⏳ Sin nuevos sismos...");
      }

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


void parpadear(int veces) 
{
  for (int i = 0; i < veces; i++) 
  {
    digitalWrite(led, HIGH);
    digitalWrite(rele, HIGH);
    delay(300);
    digitalWrite(led, LOW);
    digitalWrite(rele, LOW);
    delay(300);
  }
}
