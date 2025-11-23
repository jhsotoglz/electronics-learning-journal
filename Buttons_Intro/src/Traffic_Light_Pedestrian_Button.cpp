# include <Arduino.h>

const int RED_LED_PIN = 13;
const int GREEN_LED_PIN = 8;
const int YELLOW_LED_PIN = 10;

const int BUTTON_PIN = 2;

const unsigned long RED_TIME = 10000;
const unsigned long GREEN_TIME = 10000;
const unsigned long  YELLOW_TIME = 3000;

const unsigned long WALK_TIME = 10000;

unsigned long phaseStartTime = 0;
unsigned long walkStartTime = 0;

bool pedestrianRequested = false;
int phase = 0;

void setup () {
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);

    pinMode(BUTTON_PIN, INPUT_PULLUP);

    Serial.begin(9600);
    phaseStartTime = millis();
}

void loop () {

    // Pedestrian requested crossing privilage
    if (digitalRead(BUTTON_PIN) == LOW) {
        pedestrianRequested = true;
    }

    // TRAFFIC LIGHT STATE MACHINE

    unsigned long now = millis();

    // Phase 0 - GREEN LIGHT
    if (phase == 0) {
        digitalWrite(GREEN_LED_PIN, HIGH);

            if (now - phaseStartTime >= GREEN_TIME || pedestrianRequested) {
                digitalWrite(GREEN_LED_PIN, LOW);
                phase = 1;
                phaseStartTime = now;
            }
    }

    // Phase 1 - YELLOW LIGHT
    if (phase == 1) {
        digitalWrite(YELLOW_LED_PIN, HIGH);

            if (now - phaseStartTime >= YELLOW_TIME) {
                digitalWrite(YELLOW_LED_PIN, LOW);
                phase = 2;
                phaseStartTime = now;
                walkStartTime = now;    // Crossing timer starts
            }
    }

    // Phase 2 - RED LIGHT
    if (phase == 2) {
        digitalWrite(RED_LED_PIN, HIGH);

        // Printing crossing countdown for pedestrian
        unsigned long elapsedWalked = now - walkStartTime;
        
        if (elapsedWalked <= WALK_TIME) {
            int secondsLeft = (WALK_TIME - elapsedWalked) / 1000;
            Serial.print("Crossing Time Remaining: ");
            Serial.print(secondsLeft);
            Serial.println("seconds");
            delay(250);
        }

        // After WALK_TIME passes, continue sequence and go back to green
        if (elapsedWalked >= WALK_TIME) {
            digitalWrite(RED_LED_PIN, LOW);
            phase = 0;
            phaseStartTime = now;
            pedestrianRequested = false; // Reset crossing button to not pressed
        }
    }


}
