
/*
 Stepper Motor Control -- Simple Reliability Test

 */

#include <Stepper.h>
#define SPEED 60
#define STEP 200
#define MAXSTEPCOUNT 400 //number of revolution * STEP
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
int stepCount = 0;         // number of steps the motor has taken
bool CW = false; 

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 4, 6, 5, 7);

void setup() {
  myStepper.setSpeed(SPEED);
  Serial.begin(9600); // initialize the serial port
}

void loop(){
  if (CW == false){
    counterclockwiseStep();
    stepCount = stepCount+STEP;
    //delay(500);
    if(stepCount >= MAXSTEPCOUNT){
      CW = true;
      stepCount = 0;

    }
  }
  else if (CW == true){
    clockwiseStep();
    stepCount = stepCount+STEP;
    //delay(500);
    if(stepCount >= MAXSTEPCOUNT){
      CW = false;
      stepCount = 0;
    }
  }
}

void clockwiseStep(){
  myStepper.step(STEP);
  Serial.print("steps:");
  Serial.println(stepCount);
}

void counterclockwiseStep(){
  myStepper.step(-STEP);
  Serial.print("steps:");
  Serial.println(stepCount);
}

