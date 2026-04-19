#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

const int ledPin = 2; // LED integrado en muchos ESP32

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_BT"); // Nombre del Bluetooth

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  Serial.println("Bluetooth listo. Conectate a ESP32_BT");
}

void loop() {
  if (SerialBT.available()) {
    char dato = SerialBT.read();

    Serial.print("Recibido: ");
    Serial.println(dato);

    if (dato == 'A') {
      digitalWrite(ledPin, HIGH);
      SerialBT.println("LED ENCENDIDO");
    } 
    else if (dato == 'B') {
      digitalWrite(ledPin, LOW);
      SerialBT.println("LED APAGADO");
    }
  }
}