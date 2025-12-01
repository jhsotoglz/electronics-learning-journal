#include <Arduino.h>

const int POT_PIN = A0;
const int LED_PIN = 9; // Needs to be a PWM pin like 3, 5, 6, 9, 10, 11

void setup() {

  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);

}

void loop() {

  int sensorValue = analogRead(POT_PIN);  // from 0 - 1023
  int brightness = map(sensorValue, 0, 1023, 0, 255) ; // from 0 - 255

  analogWrite(LED_PIN, brightness);

  Serial.print("Potentiometer value: ");
  Serial.print(sensorValue);
  Serial.print("   LED brightness: ");
  Serial.print(brightness);

  delay(10);

}