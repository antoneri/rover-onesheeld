#include <OneSheeld.h>
#include "robot.h"

#define SCALE_FACTOR 25
#define F_LEFT_Y_FAC 0.5
#define F_RIGHT_Y_FAC 1.6
#define B_LEFT_Y_FAC F_RIGHT_Y_FAC
#define B_RIGHT_Y_FAC F_LEFT_Y_FAC

Robot robot;
Robot::track left, right;

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

        /*
         * The Arduino takes values for motor speed in the
         * interval [0, 255] while AccelerometerSensor reports
         * values in [-9.8, 9.8], so we need to scale our input.
         */
        left.speed = abs(left.speed) * SCALE_FACTOR;
        right.speed = abs(right.speed) * SCALE_FACTOR;

        /* Set the speed and direction for each motor. */
        Robot::track tracks[2] = {left, right};
        robot.run(tracks);

    } else {
        robot.stop();
    }
}

