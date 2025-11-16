#include <Arduino.h>

const int LED1_PIN = 2;
const int LED2_PIN = 3;

bool led1State = false;
bool led2State = false;

void setup() {
    pinMode(LED1_PIN, OUTPUT);
    pinMode(LED2_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    if (Serial.available() > 0) {
        char incoming = Serial.read();

        // Toggle LED #1 with SPACE
        if (incoming == ' ') {
            led1State = !led1State;
            digitalWrite(LED1_PIN, led1State ? HIGH : LOW);
            Serial.println(led1State ? "LED 1 ON" : "LED 1 OFF");
        }

        // Toggle LED #2 with 's'
        if (incoming == 's') {
            led2State = !led2State;
            digitalWrite(LED2_PIN, led2State ? HIGH : LOW);
            Serial.println(led2State ? "LED 2 ON" : "LED 2 OFF");
        }
    }
}
