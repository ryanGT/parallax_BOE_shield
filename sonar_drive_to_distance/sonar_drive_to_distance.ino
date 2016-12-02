/*
 Robotics with the BOE Shield – LeftServoClockwise
 Generate a servo full speed clockwise signal on digital pin 13.
 */

#include <Servo.h>                           // Include servo library

Servo servoLeft;                             // Declare left servo
Servo servoRight;                             // Declare left servo
int servoLpin = 12;
int servoRpin = 13;

#define trigPin 5
#define echoPin 6

float cm_per_microsecond = 0.03432;

void setup()                                 // Built in initialization block
{
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

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


void stop(){
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);

}

void loop()                                  // Main loop auto-repeats
{                                            // Empty, nothing needs repeating
  int mydelay = 50;
  long duration;
  float distance;
  float stopping_point1 = 21.0;//cm
  float stopping_point2 = 19.0;//cm

  digitalWrite(trigPin, LOW);
  // code from the internet has these fairly specific delays
  // they seem arbitrary; I have not read the spec on the sonar
  // sensor to know if they are required or if they are the best values
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  //  delayMicroseconds(1000);//<-- internet code said the author had
  //                                removed this line
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);//<-- this is a pretty cool Arduino function
  //                                       You may want to bring up it
  //                                       documentation from the Arduino website
  Serial.print("duration: ");
  Serial.println(duration);
  distance = (duration/2) * cm_per_microsecond;
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }

  if ( distance > stopping_point1 ){
    forward(200);
  }
  else if ( distance < stopping_point2 ){
    backwards(200);
  }
  else {
    stop();
  }
  delay(mydelay);
}

