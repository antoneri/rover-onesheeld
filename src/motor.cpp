#include "motor.h"

Motor::Motor(unsigned int analog, unsigned int digital)
    : analog_pin(analog), digital_pin(digital) {
    pinMode(analog, OUTPUT);
    pinMode(digital, OUTPUT);
}

void Motor::speed(unsigned int speed) {
    analogWrite(analog_pin, min(speed, 255));
}

void Motor::direction(unsigned int direction) {
    digitalWrite(digital_pin, direction);
}
