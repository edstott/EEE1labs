/*
EEEBug Servo Test Code
*/

#include <Servo.h>

//Pins
const int CH1in = A0;
const int CH2in = A1;
const int CH1out = 9;
const int CH2out = 11;

//Servo objects
Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
// twelve servo objects can be created on most boards

//Variables
int pos1 = 0;    // variable to store the servo position
int pos2 = 0;    // variable to store the servo position
int led = 0;    // led flash counter

void setup() {
  myservo1.attach(CH1out);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(CH2out);  // attaches the servo on pin 9 to the servo object
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
    digitalWrite(LED_BUILTIN,led++&0x10);
    pos1 = analogRead(CH1in)/6;
    pos2 = analogRead(CH2in)/6;
    myservo1.write(pos1);              // tell servo to go to position in variable 'pos'
    myservo2.write(pos2);              // tell servo to go to position in variable 'pos'
    delay(25);
}
