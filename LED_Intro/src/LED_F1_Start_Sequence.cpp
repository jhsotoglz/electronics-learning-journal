# include <Arduino.h>

const int LEDS[] = {2, 6, 8, 10, 13};
const int NUM_LEDS = 5;

void setup () {
    
    for (int i = 0; i < NUM_LEDS; i++){
        pinMode(LEDS[i], OUTPUT);
    }

    randomSeed(analogRead(A0));
}

void loop () {
    for (int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(LEDS[i], HIGH);
        delay(1000);
    }

    int random_start_time = random(700, 2500);
    delay(random_start_time);

    for (int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(LEDS[i], LOW);
    }

    delay(10000);
}