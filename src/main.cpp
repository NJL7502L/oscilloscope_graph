#include <Arduino.h>
const int pinX = 12;
const int pinY = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinX,OUTPUT);
  pinMode(pinY,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinX,1);
  digitalWrite(pinY,0);
  delay(10);
  digitalWrite(pinX,0);
  digitalWrite(pinY,1);
  delay(10);
}