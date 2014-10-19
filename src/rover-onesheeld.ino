#include <OneSheeld.h>

#define MAX(a,b) (((a)>(b))?(a):(b))

int M1 = 4; // motor 1 direction
int E1 = 5; // motor 1 speed
int E2 = 6; // motor 2 speed
int M2 = 7; // motor 2 direction

void stop(void)
{
    digitalWrite(E1, LOW);
    digitalWrite(E2, LOW);
}

void setup()
{
    OneSheeld.begin();
    
    pinMode(M1, OUTPUT);
    pinMode(E1, OUTPUT);
    pinMode(E2, OUTPUT);
    pinMode(M2, OUTPUT);
}

void loop()
{
    if (abs(AccelerometerSensor.getX()) > 1 || abs(AccelerometerSensor.getY()) > 1) {
        int x = ceil(AccelerometerSensor.getX());
        int y = ceil(AccelerometerSensor.getY());

        int outputX = abs(x) * 27 + 8;
        int outputY = abs(y) * 27 + 8;
        
        outputX = MAX(outputX, 255);
        outputY = MAX(outputY, 255);
        
        if (outputX > outputY) {
            analogWrite(E1, outputX);
            analogWrite(E2, outputX);
            
            if (x < 0) {
                digitalWrite(M1, HIGH);
                digitalWrite(M2, HIGH);
            } else {
                digitalWrite(M1, LOW);
                digitalWrite(M2, LOW);
            }
          
        } else { // outputX < outputY
            analogWrite(E1, outputY);
            analogWrite(E2, outputY);
            
            if (y > 0) {
                digitalWrite(M1, HIGH);
                digitalWrite(M2, LOW);
            } else {
                digitalWrite(M1, LOW);
                digitalWrite(M2, HIGH);
            }

        }
      
    } else {
      stop();
    }
    
}

