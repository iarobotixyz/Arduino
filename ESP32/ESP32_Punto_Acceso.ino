//RoboticaXYZ
#include <WiFi.h>

const char* ssid = "Mi_Red_ESP32_XYZ"; // Nombre de tu red hotspot
const char* password = "mi_contraseña"; // Contraseña de tu red hotspot

void setup() {
  Serial.begin(115200);
  Serial.println("Configurando ESP32 como Access Point...");

  // Iniciar el punto de acceso con el SSID y la contraseña
  WiFi.softAP(ssid, password);

  Serial.print("Punto de acceso creado: ");
  Serial.println(ssid);
  Serial.print("Dirección IP del ESP32: ");
  Serial.println(WiFi.softAPIP()); // Obtener la IP del ESP32
}

void loop() {
  // Código para el servidor web o la lógica de tu aplicación
}
