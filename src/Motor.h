#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"

class Motor {
public:
  void begin();
  void forward();
  void backward();
  void left();
  void right();
  void stop();
private:
  int pwm = 0;
};

extern Motor motor;

#endif // MOTOR_H
