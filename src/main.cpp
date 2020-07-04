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

double plotfunction(double x){
  if(x < 0 || x > 1){
    return 0;
  }
  double val = 0;
  if(x<0.1){
    val = 0.5;
  }else if(x < 0.2){
    val = 0.6;
  }else if(x<0.25){
    val = 0.4 + (x-0.2)*(0.1/0.05);
  }else if(x < 0.6){
    val = 0.5;
  }else if(x < 0.65){
    val = 0 + (x-0.6) * (0.5/0.05);
  }else if(x < 0.7){
    val = 0.5;
  }else if(x < 0.85){
    val = 0.6 +(x-0.7) * (0.1/0.15);
  }else if(x < 0.95){
    val = 0.8 + (x-0.85) * (0.1/0.1);
  }else{
    val = 1;
  }

  return constrain(val, 0, 1);
}


void loop() {
  // put your main code here, to run repeatedly:
  static double counter = 0; 
  plot(counter,plotfunction(counter));
  delay(100);
  if (counter > 1){
    counter = 0;
  }else{
    counter += 0.001;
  }

  digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN));
}
