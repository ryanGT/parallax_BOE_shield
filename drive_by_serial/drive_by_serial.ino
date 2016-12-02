/*
 Robotics with the BOE Shield – LeftServoClockwise
 Generate a servo full speed clockwise signal on digital pin 13.
 */

#include <Servo.h>                           // Include servo library

Servo servoLeft;                             // Declare left servo
Servo servoRight;                             // Declare left servo
int servoLpin = 12;
int servoRpin = 13;

void setup()                                 // Built in initialization block
{
  Serial.begin(115200);
  servoLeft.attach(servoLpin);               // Attach left signal to pin
  servoLeft.writeMicroseconds(1500);         // hold still
  servoRight.attach(servoRpin);                     // Attach left signal to pin
  servoRight.writeMicroseconds(1500);        // hold still 
}  

void forward(int speed){
  if ( speed > 200 ){
    speed = 200;
  }
  else if ( speed < 0){
    speed = 0;
  }
  servoLeft.writeMicroseconds(1500-speed);
  servoRight.writeMicroseconds(1500+speed);

}

void backwards(int speed){
  if ( speed > 200 ){
    speed = 200;
  }
  else if ( speed < 0){
    speed = 0;
  }
  servoLeft.writeMicroseconds(1500+speed);
  servoRight.writeMicroseconds(1500-speed);

}

void turn(int speed){
  if ( speed > 200 ){
    speed = 200;
  }
  else if ( speed < -200){
    speed = -200;
  }
  servoLeft.writeMicroseconds(1500+speed);
  servoRight.writeMicroseconds(1500+speed);
}

void stop(){
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);

}

void loop()                                  // Main loop auto-repeats
{                                            // Empty, nothing needs repeating
  int mydelay1 = 1000;
  int mydelay2 = 1000;
  int inByte;
  Serial.println("Input command:");
  Serial.println("f - forward");
  Serial.println("b - backward");
  Serial.println("l - left");
  Serial.println("r - right");
  
  while (Serial.available() == 0){
    delay(10);
  }
  inByte = Serial.read();
  if ( inByte == 'f' ){
    Serial.println("going forward");
    forward(200);
    delay(mydelay1);
  }
  else if ( inByte == 'b' ){
    Serial.println("going backwards");
    backwards(200);
    delay(mydelay1);
  }
  else if ( inByte == 'r' ){
    Serial.println("turning right");
    turn(100);
    delay(mydelay2);
  }
  else if ( inByte == 'l' ){
    Serial.println("turning left");
    turn(-100);
    delay(mydelay2);
  }
  else{
    Serial.println("command not recognized:");
    Serial.println(inByte);
  }
  Serial.println("stopping");
  stop();
}

