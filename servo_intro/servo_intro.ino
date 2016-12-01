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
  servoLeft.attach(13);                      // Attach left signal to pin 13 
  servoLeft.writeMicroseconds(1500);         // hold still
  servoRight.attach(12);                     // Attach left signal to pin 12 
  servoRight.writeMicroseconds(1500);        // hold still 
}  

void increment_servo(int start, int stop, int step, int mydelay){
  for (int i=start; i<=stop; i+=step){
    Serial.print("i = ");
    Serial.println(i);
    servoRight.writeMicroseconds(i);
    delay(mydelay);
  }
}

void decrement_servo(int start, int stop, int step, int mydelay){
  for (int i=start; i>=stop; i-=step){
    Serial.print("i = ");
    Serial.println(i);
    servoRight.writeMicroseconds(i);
    delay(mydelay);
  }
}

void loop()                                  // Main loop auto-repeats
{                                            // Empty, nothing needs repeating
  int mydelay = 1000;
  int mystep = 25;
  Serial.println("clockwise");
  Serial.println("increasing speed");
  decrement_servo(1500, 1300, mystep, mydelay);
  Serial.println("decreasing speed");
  increment_servo(1300, 1500, mystep, mydelay);
  Serial.println("counter clockwise");
  Serial.println("increasing speed");
  increment_servo(1500, 1700, mystep, mydelay);
  Serial.println("decreasing speed");
  decrement_servo(1700, 1500, mystep, mydelay);
}

