#include <OneSheeld.h>
#include "robot.h"

#define SCALE_FACTOR 25
#define TURN_FACTOR 1.6

Robot robot;

void setup() {
    OneSheeld.begin();
}

void loop() {
    int x = ceil(AccelerometerSensor.getX());
    int y = ceil(AccelerometerSensor.getY());

    if (abs(x) > 1 || abs(y) > 1) {

        /*
         * Calculate the speed and direction from accelerometer data.
         * Negative "x" is forward, negative "y" is left.
         */
        if (x < -1 || x > 1) {
            /* Only the sign in "direction" is significant. */
            robot.leftDirection = x;
            robot.rightDirection = x;
            robot.leftSpeed = abs(x);
            robot.rightSpeed = abs(x);

            /*
             * Decrease "inner" track speed proportionally
             * to the inverse of "y".
             */
            if (y < -2) {
                /* Turn left */
                robot.leftSpeed *= TURN_FACTOR/abs(y);
                robot.rightSpeed += abs(y);
            } else if (y > 2) {
                /* Turn right */
                robot.leftSpeed += abs(y);
                robot.rightSpeed *= TURN_FACTOR/abs(y);
            }

        } else {
            /* Turn in place */
            robot.leftDirection = y;
            robot.rightDirection = -y;
            robot.leftSpeed = abs(y);
            robot.rightSpeed = abs(y);
        }

        /*
         * The Arduino takes values for motor speed in the
         * interval [0, 255] while AccelerometerSensor reports
         * values in [-9.8, 9.8], so we need to scale our input.
         */
        robot.leftSpeed *= SCALE_FACTOR;
        robot.rightSpeed *= SCALE_FACTOR;

        robot.run();

    } else {
        robot.stop();
    }
}
