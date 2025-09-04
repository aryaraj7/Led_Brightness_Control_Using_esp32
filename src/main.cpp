#include <Arduino.h>

const int LED_PIN = 2;
const int CH = 0, FREQ = 5000, RES = 8;
const int MAX_DUTY = (1 << RES) - 1;

int duty = 0, dir = 1;
unsigned long prev;

void setup() {
  ledcSetup(CH, FREQ, RES);
  ledcAttachPin(LED_PIN, CH);
}

void loop() {
  if (millis() - prev >= 5) {
    prev = millis();
    duty += dir;
    if (duty <= 0 || duty >= MAX_DUTY) dir = -dir;
    ledcWrite(CH, duty);
  }
}
