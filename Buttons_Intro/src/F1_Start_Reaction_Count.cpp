#include <Arduino.h>

const int LEDS[] = {3, 6, 8, 10, 13};
const int NUM_LEDS = sizeof(LEDS) / sizeof(LEDS[0]);

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

    
    // LIGHTS ON ONE BY ONE
    for (int i = 0; i < NUM_LEDS; i++) {

        // False start detection during buildup
        if (digitalRead(BUTTON_PIN) == LOW) {
            Serial.println("FALSE START! (Pressed before lights out)");
            
            // Turn all lights OFF
            for (int j = 0; j < NUM_LEDS; j++) {
                digitalWrite(LEDS[j], LOW);
            }
            
            delay(3000);
            return; // restart loop()
        }

        digitalWrite(LEDS[i], HIGH);
        delay(1000);
    }

    // RANDOM DELAY BEFORE LIGHTS OFF
    int random_wait = random(700, 2500);

    unsigned long waitStart = millis();
    while (millis() - waitStart < random_wait) {

        // False start detection during random wait
        if (digitalRead(BUTTON_PIN) == LOW) {
            Serial.println("FALSE START! (Pressed before lights out)");

            // Turn off lights
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
    const unsigned long TIMEOUT = 10000; // 10 sec timeout

    // WAIT FOR PRESS OR TIMEOUT
    while (true) {

        if (digitalRead(BUTTON_PIN) == LOW) {
            unsigned long reactionTime = millis() - startTime;

            Serial.print("Reaction Time: ");
            Serial.print(reactionTime);
            Serial.println(" ms");
            break;
        }

        if (millis() - startTime >= TIMEOUT) {
            Serial.println("Reaction Time: 10000 ms (Timeout)");
            break;
        }
    }

    delay(3000); // Pause before next round
}
