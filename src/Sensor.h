#ifndef SENSOR_H
#define SENSOR_H

#include "Arduino.h"

class Sensor {
public:
  void begin();
  unsigned int readVL53(); // mm
  float readUltrasonicCM(); // single reading
  float sampleUltrasonicMedian(int samples); // median of N samples
};

extern Sensor sensor;

#endif // SENSOR_H
