#include <Arduino.h>
// Device
const int supVoltage_mv = 3300;
const int pinX = 12;
const int pinY = 13;
const int pinReference = 14;
const int pwmResolution = 256;

// Oscilloscope
const int voltageScale_mv = 1000;
const int gridCnt = 10;
const int plotVoltageRange = voltageScale_mv * gridCnt;

// 
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

void plot(int x,int y){
  digitalWrite(pinX,x);
  digitalWrite(pinY,y);
}

void loop() {
  // put your main code here, to run repeatedly:
  plot(1,1);
}
