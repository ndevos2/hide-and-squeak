/*
 * Mouse feeder thing
 * 
 * Set up: blah blah
 * 
 * Currently uses Arduino 101, nNO MOTORS, and a button (pounce)
 * Will use in the future: two stepper motors, a servo motor, reed switches?
 * Likely will use in the future: 
 *
 * Current:
 * Pounce button (top/case button) attached to pin 2
 * Bumper buttont attached to pin 3
 * 
 * Future:
 * Each stepper motor takes 4 pins - 3,4,5,6 (rightWheel) and 7,8,10,11 (leftWheel)
 * Servo motor (kibble motor) attached to pin 9
 * Bumper switches attached to 0, 1 (front, back) and 12, 13 (right, left)
 *
 * Created Fen 2, 2019
 * Modified Feb 3, 2019
 * Nicole Devos ndevos2@gmail.com
 *
 */

/* 
 * NOTES:
 * PWM on 3, 5, 6, 9
 */


 /* EDITS I NEED TO MAKE:
* 
* Change from motor commands to Serial, to motor commands to motor
* Test motor for min/max speeds
*
*/

#include <Stepper.h>

// define steppers

const int stepPin1 = 3;
const int stepPin2 = 4;
const int stepPin3 = 5;
const int stepPin4 = 6;
// pins for second stepper - 7,8,10,11

//Stepper rightWheel = Stepper(4096,stepPin1,stepPin2,stepPin3,stepPin4);
//Stepper leftWheel

// define buttons
const int pounce = 2;
const int bumper = 3;
//const int bumpers 0,1,12,13

// defin variables
int directionTime = 0;
int rightWheelSpeed = 0;
int rightWheelDirection = 0;
unsigned long currentMillis = 0;
unsigned long previousMillis = 0;
String directionString = "CW";
int kibbleDelay = 0;

void setup() {
  Serial.begin(9600);

  pinMode(pounce, INPUT);
  pinMode(bumper, INPUT);
  //pinModes for motors

  randomSeed(27051993);

}

void loop() {
  directionTime = random(1000,5001); // how long the mouse will traverse in the given direction - between half a second to 2 seconds
  rightWheelSpeed = random(100,2001); // Assuming min/max speeds for travelling are 100 RPM and 2000 RPM
  rightWheelDirection = random(1,3); // CW or CCW
  
  //rightWheel = setSpeed(rightWheelSpeed);

  if(rightWheelDirection==1)
  {directionString = "CW";}
  else {directionString = "CCW";}
  Serial.println("New speed and direction!");
  Serial.print("Travelling in the ");
  Serial.print(directionString);
  Serial.print(" direction at a speed of ");
  Serial.println(rightWheelSpeed);
  Serial.print("Travelling for ");
  Serial.print(directionTime);
  Serial.println(" milliseconds.");
  Serial.println();

  delay(10); //for serial stability

  
  
  while(currentMillis - previousMillis <= directionTime)
  {
    currentMillis = millis();
      if(rightWheelDirection == 1)
  {
    //rightWheel.step(5);
    //Serial.println("Driving in the CW direction");
  }
  else
  {
    //rightWheel.step(-5);
    //Serial.println("Driving in the CCW direction");
  }

    if(digitalRead(pounce) == HIGH)
    {
      //something about releasing kibbles from the kibble container
      //rotate kibble pinwheel for random 1-3 seconds or something, test with kibbles and printed pinwheel part
      // delay is probably the best for this application, too
      Serial.print("Dispensing kibbles for ");
      kibbleDelay = random(1000,3001);
      Serial.print(kibbleDelay);
      Serial.println(" milliseconds.");
      delay(kibbleDelay);
      Serial.println("Waiting to drive. 3...");
      delay(1000);
      Serial.println("2...");
      delay(1000);
      Serial.println("1...");
      Serial.println();
      delay(1000); // 3 second delay before continuing to drive
    }
    else if(digitalRead(bumper) == HIGH)
    {
      //reverse direction
      Serial.println("Reversing direction!");
      if(rightWheelDirection == 1)
      {
        rightWheelDirection = 2;
      }
      else
      {
        rightWheelDirection = 1;
      }
      if(rightWheelDirection==1)
  {directionString = "CW";}
  else {directionString = "CCW";}
      delay(500); // pause for half a second before reversing
      Serial.print("Reversing in the ");
      Serial.print(directionString);
      Serial.println(" direction.");
      Serial.println();
    }
    currentMillis = millis();
  }
  previousMillis = currentMillis;
}


