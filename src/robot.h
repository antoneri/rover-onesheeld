#ifndef __ROBOT_H__
#define __ROBOT_H__
#include "motor.h"
#include "config.h"

class Robot {
  private:
    Motor left;
    Motor right;
    void set_direction(int l, int r);
  public:
    Robot();
    void speed(unsigned int l, unsigned int r);
    void turn_right();
    void turn_left();
    void go_forward();
    void go_backward();
    void stop();
};

#endif
