// ------------------------------------------------------------
// RoboticaXYZ - Monitor sísmico ESP32 (versión funcional 2025)
// Basado en lector RSS del SSN (http://www.ssn.unam.mx/rss/ultimos-sismos.xml)
// ------------------------------------------------------------
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "TU_WIFI";         // 🔸 Cambia por tu red WiFi
const char* password = "TU_PASSWORD"; // 🔸 Cambia por tu contraseña
const char* url = "http://www.ssn.unam.mx/rss/ultimos-sismos.xml";

String ultimoTitulo = "";
unsigned long anteriorMillis = 0;
const unsigned long intervalo = 60000; // 1 minuto
const int led = 2; // LED integrado en muchas placas ESP32

void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  Serial.println("\n🌐 Conectando a WiFi...");

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(led, !digitalRead(led)); // parpadea mientras conecta
    delay(500);
    Serial.print(".");
  }
  digitalWrite(led, LOW);
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
      Serial.println(xml);
      int titleStart = xml.indexOf("<title>");
      int titleEnd = xml.indexOf("</title>");

      if (titleStart > 0 && titleEnd > titleStart) {
        String titulo = xml.substring(titleStart + 7, titleEnd);
        titulo.trim();

        if (titulo != ultimoTitulo && titulo.length() > 5) {
          Serial.println("\n🌎 Nuevo Sismo Detectado:");
          Serial.println("-------------------------");
          Serial.println(titulo);
          Serial.println("-------------------------");
          parpadear(3);
          ultimoTitulo = titulo;
        } else {
          Serial.println("⏳ Sin nuevos sismos...");
        }
      } else {
        Serial.println("⚠️ No se encontró título en el XML");
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

void parpadear(int veces) {
  for (int i = 0; i < veces; i++) {
    digitalWrite(led, HIGH);
    delay(200);
    digitalWrite(led, LOW);
    delay(200);
  }
}
