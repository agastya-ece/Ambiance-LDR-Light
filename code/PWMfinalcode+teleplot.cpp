//Note: Basically if you want teleplot to recognize variable to plot, specify it with ">" symbol inside Serial.println as shown

#include <Arduino.h>
// Night light - step 4: smooth LDR dimming with live graph

const int LDR_PIN = A0;
const int LED_PIN = 9;

const int BRIGHT_READING = 400;   // at or above this: LED off
const int DARK_READING = 100;     // at or below this: LED full

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(LDR_PIN);

  int brightness = map(reading, BRIGHT_READING, DARK_READING, 0, 255);
  brightness = constrain(brightness, 0, 255);

  analogWrite(LED_PIN, brightness);

  Serial.print(">LDR:"); // Action for teleplot
  Serial.println(reading);
  Serial.print(">Brightness:"); // Action for teleplot
  Serial.println(brightness);

  delay(50);
}
