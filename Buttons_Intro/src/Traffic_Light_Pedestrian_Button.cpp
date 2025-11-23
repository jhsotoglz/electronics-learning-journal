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

void stoplight_sequence ();

void setup () {
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);

    pinMode(BUTTON_PIN, INPUT_PULLUP);

    Serial.begin(9600);
}

void loop () {
    stoplight_sequence();
}

void stoplight_sequence () {
    
    digitalWrite(GREEN_LED_PIN, HIGH);

    delay(GREEN_TIME);

    digitalWrite(GREEN_LED_PIN, LOW);

    digitalWrite(YELLOW_LED_PIN, HIGH);

    delay(YELLOW_TIME);

    digitalWrite(YELLOW_LED_PIN, LOW);

    digitalWrite(RED_LED_PIN, HIGH);

    delay(RED_TIME);

    digitalWrite(RED_LED_PIN, LOW);
}