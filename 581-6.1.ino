#include <Servo.h>

Servo motor;  // create servo object to control a servo

const int motor_pin = 9;
const int speed_potpin = A1;
const int angle_potpin = A0;




int val_speed;    // variable to read the value from the analog pin
int val_angle;

void setup() {
  motor.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  ///angle:
  val_angle = analogRead(angle_potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val_angle = map(val_angle , 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  motor.write(val_angle);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
  int pos = val_angle;    // variable to store the servo position
 ///speed:
  for(pos = val_angle ; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees
  {                                  // in steps of 1 degree
    motor.write(pos);              // tell servo to go to position in variable 'pos'
    val_speed = map(analogRead(speed_potpin), 0, 1023, 0, 50);
    delay(val_speed);                       // waits 15ms for the servo to reach the position
  }
  for(pos = 180; pos>= val_angle ; pos-=1)     // goes from 180 degrees to 0 degrees
  {                               
    motor.write(pos);              // tell servo to go to position in variable 'pos'
   val_speed = map(analogRead(speed_potpin), 0, 1023, 0, 50);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
