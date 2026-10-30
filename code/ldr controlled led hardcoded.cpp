// LDR Sketch

#include <Arduino.h>
// Night light - step 3: LDR controls the LED

const int LDR_PIN = A0;
const int LED_PIN = 9;
const int DARK_THRESHOLD = 300;   // below this = dark

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(LDR_PIN);
  Serial.println(reading);

  if (reading < DARK_THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);   // dark: light on
  } 
  else {
    digitalWrite(LED_PIN, LOW);    // light: light off
  }

  delay(100);
}
