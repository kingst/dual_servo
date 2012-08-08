// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.

#include <Arduino.h>
#include <Servo.h> 

Servo servo0;
Servo servo1;
 
void setup()
{ 
    servo0.attach(10);
    servo1.attach(9);
    Serial.begin(9600);

    delay(15);

    servo0.write(90);
    servo1.write(75);

    Serial.println("ready");
}
 
 
void loop() 
{ 
    while(Serial.available() > 0) {
        int s0 = Serial.parseInt();
        int s1 = Serial.parseInt();

        if(Serial.read() == '\n') {
            servo0.write(s0);
            servo1.write(s1);
            Serial.println("ok");
        }
    }
} 

