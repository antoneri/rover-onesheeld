#ifndef __ROBOT_H__
#define __ROBOT_H__
#include "motor.h"
#include "config.h"

class Robot {
  private:
    Motor left;
    Motor right;
    template <int L, int R>
    void drive(unsigned int l, unsigned int r) {
        left.direction(L);
        right.direction(R);
        left.speed(l);
        right.speed(r);
    }
  public:
    typedef struct track {
        int direction;
        int speed;
    };
    Robot();
    void run(track *tracks);
    void stop();
};

#endif
