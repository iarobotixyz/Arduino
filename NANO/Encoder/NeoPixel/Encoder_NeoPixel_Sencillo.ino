//roboticaxyz
#include <Adafruit_NeoPixel.h>
#define PIN 4
#define NUM_LEDS 80

Adafruit_NeoPixel tira(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

// Encoder
const byte encoderPinA = 2;
const byte encoderPinB = 3;

volatile int posicion = 0;
bool lastStateA;

void setup() {
  Serial.begin(115200);

  tira.begin();
  tira.clear();
  tira.show();

  pinMode(encoderPinA, INPUT_PULLUP);
  pinMode(encoderPinB, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(encoderPinA), isr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderPinB), isr, CHANGE);

  lastStateA = digitalRead(encoderPinA);

  actualizarTira();
}

void loop() {
  static int ultimaPosicion = -1;

  if (posicion != ultimaPosicion) {

    if (posicion < 0)
      posicion = NUM_LEDS - 1;

    if (posicion >= NUM_LEDS)
      posicion = 0;

    Serial.print("Posicion: ");
    Serial.println(posicion);

    actualizarTira();
    ultimaPosicion = posicion;
  }
}

void actualizarTira() {
  tira.clear();

  tira.setPixelColor(posicion, tira.Color(0, 0, 255)); // Azul

  tira.show();
}

void isr() {
  bool stateA = digitalRead(encoderPinA);
  bool stateB = digitalRead(encoderPinB);

  if (stateA != lastStateA) {
    if (stateA == stateB) {
      posicion++;
    } else {
      posicion--;
    }
  }

  lastStateA = stateA;
}