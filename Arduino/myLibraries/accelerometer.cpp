#include "components.h"

const int xInput = A0;
const int yInput = A1;
const int zInput = A2;

const int sampleSize = 10;



Acceleration Accelerometer::ReadAxis()
{
  float xReading = 0.0;
  float yReading = 0.0;
  float zReading = 0.0;

  for (int i = 0; i < sampleSize; i++)
  {
    xReading += analogRead(xInput);
    yReading += analogRead(yInput);
    zReading += analogRead(zInput);
  }

  int xValue = xReading / sampleSize;
  int yValue = yReading / sampleSize;
  int zValue = zReading / sampleSize;


    long xScaled = map(xValue, 272, 396, -100, 100);
    long yScaled = map(yValue, 262, 397, -100, 100);
    long zScaled = map(zValue, 265, 404, -100, 100);

    float xAccel = xScaled / 100.0;
    float yAccel = yScaled / 100.0;
    float zAccel = zScaled / 100.0;

  Acceleration accel;
  accel.x = xAccel;
  accel.y = yAccel;
  accel.z = zAccel;

  return accel;
}