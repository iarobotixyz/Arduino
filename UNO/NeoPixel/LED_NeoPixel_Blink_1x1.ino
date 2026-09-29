#include <Adafruit_NeoPixel.h>

#define PIN 4
#define NUM_LEDS 10

Adafruit_NeoPixel tira(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  tira.begin();
  tira.show();
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    tira.clear();
    tira.setPixelColor(i, tira.Color(255, 0, 0)); // Rojo
    tira.show();
    delay(200);
  }
}