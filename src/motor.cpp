#include "motor.h"

Motor::Motor(unsigned int analog, unsigned int digital)
    : analog_pin(analog), digital_pin(digital) {}

void Motor::speed(unsigned int speed) {
    speed = min(speed, 255);
    analogWrite(analog_pin, speed);
}

void Motor::direction(int direction) {
    if (direction != HIGH ||
        direction != LOW) {
        return;
    }
    digitalWrite(digital_pin, direction);
}
