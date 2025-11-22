// # include <Arduino.h>

// const int LEDS[] = {13, 4, 2}; // Red, Green, Yellow
// const int NUM_LEDS = 3;

// void blinkled (int pin, int ms);

// void setup () {
//     for (int i = 0; i < NUM_LEDS; i++){
//         pinMode(LEDS[i], OUTPUT);
//     }
// }

// void loop () {
//     // Forward sequence
//     for (int i = 0; i < NUM_LEDS; i++){
//         blinkled(LEDS[i], 100);
//     }

//     for (int i = NUM_LEDS - 2; i > 0; i--){
//         blinkled(LEDS[i], 100);
//     }
// }

// void blinkled (int pin, int ms) {
//     digitalWrite(pin, HIGH);
//     delay(ms);
//     digitalWrite(pin, LOW);
//     delay(ms);
// }