#include <Arduino.h>
#include "parameter.h"

void setup() {
  pinMode(pinX,OUTPUT);
  pinMode(pinY,OUTPUT);
}

void plot(float x,float y){
  float outX = map(x*100,100,0,0,255);
  float outY = map(y*100,100,0,0,255);
  analogWrite(pinX,outX);
  analogWrite(pinY,outY);
}

void loop() {
  // put your main code here, to run repeatedly:
  plot(0.8,0.8);
}
