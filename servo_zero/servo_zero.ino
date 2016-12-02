/*
 Robotics with the BOE Shield – LeftServoClockwise
 Generate a servo full speed clockwise signal on digital pin 13.
 */

#include <Servo.h>                           // Include servo library

Servo servoLeft;                             // Declare left servo
Servo servoRight;                             // Declare left servo

void setup()                                 // Built in initialization block
{
  Serial.begin(115200);
  Serial.println("this code is for zeroing your servos");
  servoLeft.attach(13);                      // Attach left signal to pin 13 
  servoLeft.writeMicroseconds(1500);         // hold still
  servoRight.attach(12);                     // Attach left signal to pin 12 
  servoRight.writeMicroseconds(1500);        // hold still 
}  

void loop()                                  // Main loop auto-repeats
{                                            // Empty, nothing needs repeating
}

