// https://iarobotxyz.blogspot.com/2026/04/robot-bluetooth-con-esp32.html
#include "BluetoothSerial.h"
BluetoothSerial SerialBT;

// Pines del ESP32 para puente H 
const int IN1 = 26;
const int IN2 = 27;
const int IN3 = 14;
const int IN4 = 12;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_CAR");

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  detener();

  Serial.println("Listo. Conecta por Bluetooth a ESP32_CAR");
}

// -------- FUNCIONES DE MOVIMIENTO --------

void adelante() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void atras() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void izquierda() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void derecha() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void detener() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// -------- LOOP --------

void loop() {
  if (SerialBT.available()) {
    char dato = SerialBT.read();

    Serial.print("Recibido: ");
    Serial.println(dato);

    switch (dato) {
      case 'F':
        adelante();
        break;

      case 'G':
        atras();
        break;

      case 'L':
        izquierda();
        break;

      case 'R':
        derecha();
        break;

      case 'S':
        detener();
        break;

      // Botones extra (opcional)
      case 'O':
        Serial.println("Triangulo presionado");
        break;

      case 'X':
        Serial.println("X presionado");
        break;

      case 'M':
        Serial.println("Cuadrado presionado");
        break;

      case 'N':
        Serial.println("Circulo presionado");
        break;
    }
  }
}