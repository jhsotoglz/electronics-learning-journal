# include <Arduino.h>

const int RED_LED_PIN = 13;
const int GREEN_LED_PIN = 4;
const int YELLOW_LED_PIN = 2;

const int RED_TIME = 10000;
const int GREEN_TIME = 10000;
const int YELLOW_TIME = 3000;

void stoplight_sequence ();

void setup () {
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
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