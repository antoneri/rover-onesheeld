#include "robot.h"

Robot::Robot()
    : left(M1_ANALOG_PIN, M1_DIGITAL_PIN),
      right(M2_ANALOG_PIN, M2_DIGITAL_PIN) {
    pinMode(M1_ANALOG_PIN, OUTPUT);
    pinMode(M1_DIGITAL_PIN, OUTPUT);
    pinMode(M2_ANALOG_PIN, OUTPUT);
    pinMode(M2_DIGITAL_PIN, OUTPUT);
}

void Robot::speed(unsigned int l, unsigned int r) {
    left.speed(l);
    right.speed(r);
}

void Robot::turn_right() {
    left.direction(HIGH);
    right.direction(LOW);
}

void Robot::turn_left() {
    left.direction(LOW);
    right.direction(HIGH);
}

void Robot::go_forward() {
    left.direction(HIGH);
    right.direction(HIGH);
}

void Robot::go_backward() {
    left.direction(LOW);
    right.direction(LOW);
}

void Robot::stop() {
    left.speed(0);
    right.speed(0);
    left.direction(LOW);
    right.direction(LOW);
}

