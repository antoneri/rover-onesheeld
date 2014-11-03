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

void Robot::set_direction(int l, int r) {
    left.direction(l);
    right.direction(r);
}

void Robot::turn_right() {
    set_direction(HIGH, LOW);
}

void Robot::turn_left() {
    set_direction(LOW, HIGH);
}

void Robot::go_forward() {
    set_direction(HIGH, HIGH);
}

void Robot::go_backward() {
    set_direction(LOW, LOW);
}

void Robot::stop() {
    set_direction(LOW, LOW);
    left.speed(0);
    right.speed(0);
}

