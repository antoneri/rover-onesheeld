#include <OneSheeld.h>
#include "robot.h"

#define F_LEFT_Y_FAC 0.5
#define F_RIGHT_Y_FAC 1.6
#define B_LEFT_Y_FAC F_RIGHT_Y_FAC
#define B_RIGHT_Y_FAC F_LEFT_Y_FAC

Robot robot;

void setup() {
    OneSheeld.begin();
}

void loop() {
    int x = ceil(AccelerometerSensor.getX());
    int y = ceil(AccelerometerSensor.getY());

    if (abs(x) > 1 || abs(y) > 1) {
        Robot::track left, right;

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

        /* Set the speed and direction for each motor. */
        Robot::track tracks[2] = {left, right};
        robot.run(tracks);

    } else {
        robot.stop();
    }
}

