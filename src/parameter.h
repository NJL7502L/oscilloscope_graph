#ifndef INCLUDE_GUARD_PARAMETER_H
#define INCLUDE_GUARD_PARAMETER_H

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

#endif
