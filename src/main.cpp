#include <Arduino.h>
// Device
const int supVoltage_mv = 3300;
const int pinX = 3;
const int pinY = 4;
const int pinReference = 5;
const int pwmResolution = 256;

// Oscilloscope
const int voltageScale_mv = 200;
const int gridCnt = 10;
const int plotVoltageRange = voltageScale_mv * gridCnt;

// Graph
const float originX_min = 0;
const float originX_max = 1;
const float originY_min = -1;
const float originY_max = 1;

// Internal
int referenceVoltage_mv = 0;
int maximumVoltage_mv = 0;
int minimumVoltage_mv = 0;

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
