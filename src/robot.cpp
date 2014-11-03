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

void Robot::turn_right(unsigned int l, unsigned int r) {
    set_direction(HIGH, LOW);
    speed(l, r);
}

void Robot::turn_left(unsigned int l, unsigned int r) {
    set_direction(LOW, HIGH);
    speed(l, r);
}

void Robot::go_forward(unsigned int l, unsigned int r) {
    set_direction(HIGH, HIGH);
    speed(l, r);
}

void Robot::go_backward(unsigned int l, unsigned int r) {
    set_direction(LOW, LOW);
    speed(l, r);
}

void Robot::stop() {
    set_direction(LOW, LOW);
    speed(0, 0);
}

