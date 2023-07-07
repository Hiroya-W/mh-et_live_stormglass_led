extern "C" {
// https://github.com/FastLED/FastLED/issues/581
volatile unsigned long timer0_millis = 0;
}

#include <FastLED.h>

#define LED_PIN 14
#define NUM_LEDS 16
#define BRIGHTNESS 20
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

uint8_t gHue = 0;

void setup() {
    delay(1000);
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
    FastLED.clear();
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CHSV(gHue, 255, 255);
    }
    gHue++;
    FastLED.show();
    delay(50);
}
