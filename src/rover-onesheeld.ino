#include <OneSheeld.h>
#include "robot.h"

#define SCALE_FACTOR 25
#define F_LEFT_FAC 0.5
#define F_RIGHT_FAC 1.6
#define B_LEFT_FAC F_RIGHT_FAC // switch factors when going backwards
#define B_RIGHT_FAC F_LEFT_FAC

Robot robot;
Robot::track left, right;

void setup() {
    OneSheeld.begin();
}

void loop() {
    int x = ceil(AccelerometerSensor.getX());
    int turn = ceil(AccelerometerSensor.getY());

    if (abs(x) > 1 || abs(turn) > 1) {

        /*
         * Calculate the speed and direction from accelerometer data.
         * Negative "x" is forward, negative "turn" is left.
         */
        if (x < 0) {
            left.direction = x + turn;
            right.direction = x - turn;
            left.speed = x + turn*F_LEFT_FAC;
            right.speed = x - turn*F_RIGHT_FAC;
        } else if (x > 0) {
            left.direction = x - turn;
            right.direction = x + turn;
            left.speed = x - turn*B_LEFT_FAC;
            right.speed = x + turn*B_RIGHT_FAC;
        } else {
            /* Turn in place */
            left.direction = -turn;
            right.direction = turn;
            left.speed = turn;
            right.speed = turn;
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

