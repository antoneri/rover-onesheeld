#include <OneSheeld.h>
#include "robot.h"

#define F_LEFT_Y_FAC 0.5
#define F_RIGHT_Y_FAC 1.6
#define B_LEFT_Y_FAC F_RIGHT_Y_FAC
#define B_RIGHT_Y_FAC F_LEFT_Y_FAC

Robot robot;

struct {
    int direction;
    int speed;
} left, right;

void setup() {
    OneSheeld.begin();
}

void loop() {
    int x = ceil(AccelerometerSensor.getX());
    int y = ceil(AccelerometerSensor.getY());

    if (abs(x) > 1 || abs(y) > 1) {
        /*
         * Calculate the speed and direction from accelerometer data.
         * Negative x is forward, negative y is left.
         */
        if (x < 0) {
            left.direction = x + y;
            right.direction = x - y;
            left.speed = x + y*F_LEFT_Y_FAC;
            right.speed = x - y*F_RIGHT_Y_FAC;
        } else if (x > 0) {
            left.direction = x - y;
            right.direction = x + y;
            left.speed = x - y*B_LEFT_Y_FAC;
            right.speed = x + y*B_RIGHT_Y_FAC;
        } else {
            /* Turn in place */
            left.direction = -y;
            right.direction = y;
            left.speed = y;
            right.speed = y;
        }

        left.speed = abs(left.speed) * 25;
        right.speed = abs(right.speed) * 25;

        /*
         * Set the speed and direction for each motor.
         */
        if (left.direction > 0 && right.direction > 0) {
            robot.go_forward(left.speed, right.speed);
        } else if (left.direction > 0 && right.direction < 0) {
            robot.turn_left(left.speed, right.speed);
        } else if (left.direction < 0 && right.direction > 0) {
            robot.turn_right(left.speed, right.speed);
        } else {
            robot.go_backward(left.speed, right.speed);
        }

    } else {
        robot.stop();
    }
}

