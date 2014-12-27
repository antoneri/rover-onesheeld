#ifndef __MOTOR_H__
#define __MOTOR_H__
#include <Arduino.h>

class Motor {
  private:
    unsigned int analog_pin;
    unsigned int digital_pin;

  public:
    Motor(unsigned int analog, unsigned int digital);
    void speed(unsigned int speed);
    void direction(unsigned int direction);
};

#endif
