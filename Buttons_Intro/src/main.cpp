#include <Arduino.h>

const int BUTTON_PIN = 4;
const int LED_PIN = 13; 

bool ledState = false;
bool lastButtonState = HIGH;

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int currentState = digitalRead(BUTTON_PIN);

    if (currentState == LOW && lastButtonState == HIGH) {
        ledState = !ledState;          // toggle
        digitalWrite(LED_PIN, ledState);
        Serial.println(ledState ? "LED ON" : "LED OFF");
    }

    lastButtonState = currentState;
}



