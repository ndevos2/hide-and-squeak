/*
 * Mouse feeder thing
 * 
 * Set up: blah blah
 * 
 * Currently uses Arduino 101, two motors, and a button
 * Will use in the future: 
 * Likely will use in the future: 
 *
 * thing on pin thing
 *
 * Created Fen 2, 2019
 * Modified Feb 2, 209
 * Nicole Devos ndevos2@gmail.com
 *
 */

/* 
 * NOTES:
 * PWM on 3, 5, 6, 9
 */


 /* EDITS I NEED TO MAKE:
* 
*
*
*/

#include <Servo.h>

// define servos
//const int CCW = 85;
//const int CW = 100;

//Servo rightWheel;
//Servo leftWheel;

//const int rightWheelPin = ;

// define buttons
const int pounce = 2;
const int bumper = 3;

void setup() {
  // put your setup code here, to run once:

  pinMode(pounce, INPUT);
  //rightWheel.attach(rightWheelPin);

}

void loop() {
  if(digitalRead(pounce) == HIGH)
  {
    //something about releasing kibbles from the kibble container
    //rotate kibble pinwheel for random 1-4 seconds or something, test with kibbles and printed pinwheel part
    // delay is probably the best for this application, too
  }
  else if(digitalRead(bumper) == HIGH)
  {
    //reverse direction
  }
}

}
