#include <Adafruit_NeoPixel.h>

#define PIN 4
#define NUM_LEDS 10

Adafruit_NeoPixel tira(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  tira.begin();

  for(int i=0; i<NUM_LEDS; i++) {
    tira.setPixelColor(i, 0, 0, 255); // RGB
  }

  tira.show();
}

void loop() {
}