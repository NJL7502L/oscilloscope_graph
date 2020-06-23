#include <Arduino.h>
const int pinX = 12;
const int pinY = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinX,OUTPUT);
  pinMode(pinY,OUTPUT);
}

void plot(int x,int y){
  digitalWrite(pinX,x);
  digitalWrite(pinY,y);
}

void loop() {
  // put your main code here, to run repeatedly:
  plot(1,0);
}
