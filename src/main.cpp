#include <Arduino.h>
#include "parameter.h"

void setup() {
  // お城の描写可能領域から最大電圧/リファレンス電圧を設定
  if (supVoltage_mv > plotVoltageRange){
    referenceVoltage_mv = plotVoltageRange / 2;
    maximumVoltage_mv = plotVoltageRange;
  }else{
    referenceVoltage_mv = supVoltage_mv / 2;
    maximumVoltage_mv = supVoltage_mv;
  }

  pinMode(pinX,OUTPUT);
  pinMode(pinY,OUTPUT);
}

void plot(float x,float y){
  float outX_mv = map(x*100,originX_min*100,originX_max*100,0,maximumVoltage_mv);
  float outY_mv = map(y*100,originY_min*100,originY_max*100,0,maximumVoltage_mv);
  int outX = map(outX_mv*100,0,maximumVoltage_mv*100,0,pwmResolution);
  int outY = map(outY_mv*100,0,maximumVoltage_mv*100,0,pwmResolution);
  int outRef = map(referenceVoltage_mv*100,0,maximumVoltage_mv*100,0,pwmResolution);
  analogWrite(pinX,outX);
  analogWrite(pinY,outY);
  analogWrite(pinReference,outRef);
}

void loop() {
  // put your main code here, to run repeatedly:
  plot(1,-1);
}
