#ifndef __ROBOT_H__
#define __ROBOT_H__
#include "motor.h"
#include "config.h"

class Robot {
  private:
    Motor left;
    Motor right;
    void set_direction(int l, int r);
    void speed(unsigned int l, unsigned int r);
  public:
    typedef struct track {
        int direction;
        int speed;
    };
    Robot();
    void turn_right(unsigned int l, unsigned int r);
    void turn_left(unsigned int l, unsigned int r);
    void go_forward(unsigned int l, unsigned int r);
    void go_backward(unsigned int l, unsigned int r);
    void run(track *tracks);
    void stop();
};

#endif
