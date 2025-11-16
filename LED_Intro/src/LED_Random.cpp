// # include <Arduino.h>

// const int LED_RED = 13;
// const int LED_YELLOW = 4;
// const int LED_GREEN = 2;

// void blinkled (int pin, int ms);
// void randLED ();

// void setup () {
//     pinMode(LED_RED, OUTPUT);
//     pinMode(LED_GREEN, OUTPUT);
//     pinMode(LED_YELLOW, OUTPUT);

//     randomSeed(analogRead(A0)); // nothing connected to pin 0, adds randomness by electrical noise
// }

// void loop () {
//     blinkled(LED_RED, 100);
//     blinkled(LED_GREEN, 100);
//     blinkled(LED_YELLOW, 100);

//     delay(500);

//     randLED();
// }

// void blinkled (int pin, int ms) {
//     digitalWrite(pin, HIGH);
//     delay(ms);
//     digitalWrite(pin, LOW);
//     delay(ms);
// }

// void randLED () {
//     int r = random(0, 3);
    
//     switch (r)
//     {
//     case 0:
//         blinkled(LED_RED, 1000);
//         break;
    
//     case 1:
//         blinkled(LED_GREEN, 1000);
//         break;

//     case 2:
//         blinkled(LED_YELLOW, 1000);
//     }
// }