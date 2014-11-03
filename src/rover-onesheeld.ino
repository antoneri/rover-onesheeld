#include <OneSheeld.h>
#include "robot.h"

#define NUM_ITERATIONS 10
#define FORWARD_LEFT_Y_FAC 0.5
#define FORWARD_RIGHT_Y_FAC 1.6
#define BACKWARD_LEFT_Y_FAC FORWARD_RIGHT_Y_FAC
#define BACKWARD_RIGHT_Y_FAC FORWARD_LEFT_Y_FAC

Robot robot;

void setup() {
    OneSheeld.begin();
}

int current_x = 0;
int i = 0;
int left_dir, right_dir, left_speed, right_speed;

void loop() {
    int x = ceil(AccelerometerSensor.getX());
    int y = ceil(AccelerometerSensor.getY());

    if (abs(x) <= 1 && abs(y) <= 1) {
        return robot.stop();
    }

    if (x == current_x) {
        if (++i > NUM_ITERATIONS) {
            /*
             * The same direction has been
             * recorded for NUM_ITERATIONS.
             */
            return robot.stop();
        }
    } else {
        current_x = x;
        i = 0;
    }


    if (x < 0) {
        left_dir = x + y;
        right_dir = x - y;
        left_speed = x + y*BACKWARD_LEFT_Y_FAC;
        right_speed = x - y*BACKWARD_RIGHT_Y_FAC;
    } else {
        left_dir = x - y;
        right_dir = x + y;
        left_speed = x - y*FORWARD_LEFT_Y_FAC;
        right_speed = x + y*FORWARD_RIGHT_Y_FAC;
    }

    if (left_dir > 0 && right_dir > 0) {
        robot.go_forward();
    } else if (left_dir < 0 && right_dir > 0) {
        robot.turn_left();
    } else if (left_dir > 0 && right_dir < 0) {
        robot.turn_right();
    } else {
        robot.go_backward();
    }

    left_speed = abs(left_speed) * 25;
    right_speed = abs(right_speed) * 25;
    robot.speed(left_speed, right_speed);
}

