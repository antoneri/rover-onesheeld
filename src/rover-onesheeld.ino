#include <OneSheeld.h>

int M1 = 4; // motor 1 direction
int E1 = 5; // motor 1 speed

int E2 = 6; // motor 2 speed
int M2 = 7; // motor 2 direction

void stop(void) {
    digitalWrite(E1, LOW);
    digitalWrite(E2, LOW);
}

void setup() {
    OneSheeld.begin();
    
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
}

void loop() {

    if (abs(AccelerometerSensor.getX()) > 1 || abs(AccelerometerSensor.getY()) > 1) {
        
        int x = ceil(AccelerometerSensor.getX());
        int y = ceil(AccelerometerSensor.getY());
        int outputX = abs(x) * 27 + 8;
        int outputY = abs(y) * 27 + 8;
        
        if (outputX > 255) {
            outputX = 255;
        }
        
        if (outputY > 255) {
            outputY = 255;
        }
        
        if (outputX > outputY) {
            
            if (x < 0) {
                digitalWrite(M1, HIGH);
                digitalWrite(M2, HIGH);
                analogWrite(E1, outputX);
                analogWrite(E2, outputX);
            } else {
                digitalWrite(M1, LOW);
                digitalWrite(M2, LOW);
                analogWrite(E1, outputX);
                analogWrite(E2, outputX);
            }
          
        } else { // outputX < outputY
            
            if (y > 0) {
                digitalWrite(M1, HIGH);
                digitalWrite(M2, LOW);
                analogWrite(E1, outputY);
                analogWrite(E2, outputY);
            } else {
                digitalWrite(M1, LOW);
                digitalWrite(M2, HIGH);
                analogWrite(E1, outputY);
                analogWrite(E2, outputY);
            }

        }
      
    } else {
      stop();
    }
    
}

