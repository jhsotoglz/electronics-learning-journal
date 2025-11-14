#include <Arduino.h>

const int LED_PIN = 13;
bool ledState = false;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    // Check if any serial data is available
    if (Serial.available() > 0) {
        char incoming = Serial.read();   // Read one character

        if (incoming == ' ') {           // If it's the spacebar
            ledState = !ledState;        // Toggle state
            digitalWrite(LED_PIN, ledState ? HIGH : LOW);
            Serial.println(ledState ? "LED ON" : "LED OFF");
        }
    }
}