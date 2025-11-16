#include <Arduino.h>

const int LED_RED_PIN    = 13;
const int LED_YELLOW_PIN = 2;
const int LED_GREEN_PIN  = 4;

void blinkLed(int pin, int ms);

void setup() {
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_YELLOW_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
}

void loop() {
  blinkLed(LED_RED_PIN, 200);
  blinkLed(LED_GREEN_PIN, 200);
  blinkLed(LED_YELLOW_PIN, 200);
}

void blinkLed(int pin, int ms) {
  digitalWrite(pin, HIGH);
  delay(ms);
  digitalWrite(pin, LOW);
  delay(ms);
}
