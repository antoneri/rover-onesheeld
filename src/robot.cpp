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

void Robot::direction(int l, int r) {
    left.direction(l);
    right.direction(r);
}

void Robot::turn_right(unsigned int l, unsigned int r) {
    direction(HIGH, LOW);
    speed(l, r);
}

void Robot::turn_left(unsigned int l, unsigned int r) {
    direction(LOW, HIGH);
    speed(l, r);
}

void Robot::go_forward(unsigned int l, unsigned int r) {
    direction(HIGH, HIGH);
    speed(l, r);
}

void Robot::go_backward(unsigned int l, unsigned int r) {
    direction(LOW, LOW);
    speed(l, r);
}

void Robot::run(track *tracks) {
    track left = tracks[0];
    track right = tracks[1];

    if (left.direction > 0 && right.direction > 0) {
        go_forward(left.speed, right.speed);
    } else if (left.direction > 0 && right.direction < 0) {
        turn_left(left.speed, right.speed);
    } else if (left.direction < 0 && right.direction > 0) {
        turn_right(left.speed, right.speed);
    } else {
        go_backward(left.speed, right.speed);
    }
}

void Robot::stop() {
    direction(LOW, LOW);
    speed(0, 0);
}

