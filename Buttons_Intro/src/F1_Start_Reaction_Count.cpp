#include <Arduino.h>

const int LEDS[] = {3, 6, 8, 10, 13};
const int NUM_LEDS = 5;

const int BUTTON_PIN = 2;

void setup() {
    for (int i = 0; i < NUM_LEDS; i++) {
        pinMode(LEDS[i], OUTPUT);
    }

    pinMode(BUTTON_PIN, INPUT_PULLUP);

    Serial.begin(9600);
    randomSeed(analogRead(A0));
}

void loop() {

    // WAIT FOR BUTTON RELEASE BEFORE NEXT ROUND
    // (prevents holding the button down)
    while (digitalRead(BUTTON_PIN) == LOW) {
        // do nothing
    }

    // LIGHTS ON ONE BY ONE (with continuous check)
    for (int i = 0; i < NUM_LEDS; i++) {

        digitalWrite(LEDS[i], HIGH);

        // Stay on for 1000 ms but constantly check for false start
        unsigned long segmentStart = millis();
        while (millis() - segmentStart < 1000) {

            if (digitalRead(BUTTON_PIN) == LOW) {

                Serial.println("FALSE START! (Pressed before lights out)");

                // Turn all lights OFF
                for (int j = 0; j < NUM_LEDS; j++) {
                    digitalWrite(LEDS[j], LOW);
                }

                delay(3000);
                return;
            }
        }
    }

    // RANDOM WAIT BEFORE LIGHTS OFF
    int random_wait = random(700, 2500);
    unsigned long waitStart = millis();

    while (millis() - waitStart < random_wait) {

        if (digitalRead(BUTTON_PIN) == LOW) {
            Serial.println("FALSE START! (Pressed before lights out)");

            for (int j = 0; j < NUM_LEDS; j++) {
                digitalWrite(LEDS[j], LOW);
            }

            delay(3000);
            return;
        }
    }

    // LIGHTS OFF = GO!
    for (int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(LEDS[i], LOW);
    }

    unsigned long startTime = millis();
    const unsigned long TIMEOUT = 10000; // 10 seconds max

    // WAIT FOR BUTTON PRESS OR TIMEOUT
    while (true) {

        // BUTTON PRESSED WITH SUCCESSFUL REACTION
        if (digitalRead(BUTTON_PIN) == LOW) {
            unsigned long reactionTime = millis() - startTime;
            Serial.print("Reaction Time: ");
            Serial.print(reactionTime);
            Serial.println(" ms");
            break;
        }

        // TIMEOUT
        if (millis() - startTime >= TIMEOUT) {
            Serial.println("Reaction Time: 10000 ms (Timeout)");
            break;
        }
    }

    delay(3000); // pause before next round
}
