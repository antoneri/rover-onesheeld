#include "robot.h"

Robot::Robot()
    : left(M1_ANALOG_PIN, M1_DIGITAL_PIN),
      right(M2_ANALOG_PIN, M2_DIGITAL_PIN),
      leftDirection(0),
      rightDirection(0),
      leftSpeed(0),
      rightSpeed(0) {
}

void Robot::run() {

    if (Robot::leftDirection > 0 && Robot::rightDirection > 0) {
        drive<HIGH, HIGH>(Robot::leftSpeed, Robot::rightSpeed);
    } else if (Robot::leftDirection > 0 && Robot::rightDirection < 0) {
        drive<LOW, HIGH>(Robot::leftSpeed, Robot::rightSpeed);
    } else if (Robot::leftDirection < 0 && Robot::rightDirection > 0) {
        drive<HIGH, LOW>(Robot::leftSpeed, Robot::rightSpeed);
    } else if (Robot::leftDirection < 0 && Robot::rightDirection < 0) {
        drive<LOW, LOW>(Robot::leftSpeed, Robot::rightSpeed);
    }

}

void Robot::stop() {
    drive<LOW, LOW>(0, 0);
}
