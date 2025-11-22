// # include <Arduino.h>

// const int BUTTON_READ_PIN = 8;

// void setup () {

//   pinMode(BUTTON_READ_PIN, INPUT_PULLUP);

//   Serial.begin(9600); // Without initializing Serial, the Arduino won’t send anything to the Serial Monitor.

// }

// void loop () {

//   int buttonState = digitalRead(BUTTON_READ_PIN);

//   if (buttonState == LOW) {
//     Serial.println("Button Pressed!!!");
//   } else {
//     Serial.println("Button Released!!!");
//   }

//   delay(100);
// }