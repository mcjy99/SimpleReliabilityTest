
/*
 Stepper Motor Control -- Simple Reliability Test
 Motor will rotate a certain number of revolutions in one direction and back to orignal position
 */

#include <Stepper.h>
#define SPEED 60 //motor speed
#define STEP 200 //number of steps in one revolution
#define MAXSTEPCOUNT 400 //used to count number of revolutions in each direction in one cycle, number of revolution * STEP 
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
int stepCount = 0;         // counter for the number of steps the motor has taken
bool CW = false;           //change this to true if want to start with clockwise 

// initialize the stepper library on pins 4 through 7 (Arduino Motor Shield):
Stepper myStepper(stepsPerRevolution, 4, 6, 5, 7);

void setup() {
  myStepper.setSpeed(SPEED); //set the speed of the motor
  Serial.begin(9600); // initialize the serial port
}

void loop(){
  if (CW == false){ //for counterclockwise
    counterclockwiseStep(); 
    stepCount = stepCount+STEP; //increments the counter for number of steps 
    //delay(500); //uncomment for the motor to pause every revolution
    if(stepCount >= MAXSTEPCOUNT){ //once the number of revolutions has reached the setpoint
      CW = true; //change direction
      stepCount = 0; //reset counter to 0 so it will turn same number of revolutions back to position

    }
  }
  else if (CW == true){ //for clockwise
    clockwiseStep();
    stepCount = stepCount+STEP;
    //delay(500);
    if(stepCount >= MAXSTEPCOUNT){
      CW = false;
      stepCount = 0;
    }
  }
}

void clockwiseStep(){ //motor turns clockwise in the defined number of steps 
  myStepper.step(STEP);
  Serial.print("steps:");
  Serial.println(stepCount);
}

void counterclockwiseStep(){
  myStepper.step(-STEP);
  Serial.print("steps:");
  Serial.println(stepCount);
}

