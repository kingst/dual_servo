/*
 * University of Illinois/NCSA
 * Open Source License
 *
 *  Copyright (c) 2012,The Board of Trustees of the University of
 *  Illinois.  All rights reserved.
 *
 *  Copyright (c) 2012 Sam King
 *
 *  Developed by:
 *
 *  Professor Sam King in the Department of Computer Science
 *  The University of Illinois at Urbana-Champaign
 *      http://www.cs.uiuc.edu/homes/kingst/Research.html
 *
 *       Permission is hereby granted, free of charge, to any person
 *       obtaining a copy of this software and associated
 *       documentation files (the "Software"), to deal with the
 *       Software without restriction, including without limitation
 *       the rights to use, copy, modify, merge, publish, distribute,
 *       sublicense, and/or sell copies of the Software, and to permit
 *       persons to whom the Software is furnished to do so, subject
 *       to the following conditions:
 *
 *          Redistributions of source code must retain the above
 *          copyright notice, this list of conditions and the
 *          following disclaimers.
 *
 *          Redistributions in binary form must reproduce the above
 *          copyright notice, this list of conditions and the
 *          following disclaimers in the documentation and/or other
 *          materials provided with the distribution.
 *
 *          Neither the names of Sam King, the University of Illinois,
 *          nor the names of its contributors may be used to endorse
 *          or promote products derived from this Software without
 *          specific prior written permission.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT.  IN NO EVENT SHALL THE CONTRIBUTORS OR COPYRIGHT
 *  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *  DEALINGS WITH THE SOFTWARE.
*/

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

