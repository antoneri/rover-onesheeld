#include "robot.h"

Robot::Robot()
    : left(M1_ANALOG_PIN, M1_DIGITAL_PIN),
      right(M2_ANALOG_PIN, M2_DIGITAL_PIN) {
    pinMode(M1_ANALOG_PIN, OUTPUT);
    pinMode(M1_DIGITAL_PIN, OUTPUT);
    pinMode(M2_ANALOG_PIN, OUTPUT);
    pinMode(M2_DIGITAL_PIN, OUTPUT);
}

void Robot::run(track *tracks) {
    track left = tracks[0];
    track right = tracks[1];

    if (left.direction > 0 && right.direction > 0) {
        drive<HIGH, HIGH>(left.speed, right.speed);
    } else if (left.direction > 0 && right.direction < 0) {
        drive<LOW, HIGH>(left.speed, right.speed);
    } else if (left.direction < 0 && right.direction > 0) {
        drive<HIGH, LOW>(left.speed, right.speed);
    } else {
        drive<LOW, LOW>(left.speed, right.speed);
    }
}

void Robot::stop() {
    drive<LOW, LOW>(0, 0);
}

