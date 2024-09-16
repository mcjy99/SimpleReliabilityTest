# Stepper Motor Application for Simple Reliability Test of Flexible Electronics

## Hardware Used 
1. Arduino Uno
2. [Arduino 2A Motor Shield](https://my.cytron.io/p-0.8amp-5v-26v-dc-motor-driver-shield-for-arduino-2-channels?r=1) : [User Manual](https://docs.google.com/document/d/1EiQAE_9VpDDm4rjZrySAoGjQldJnTk6rJIsUkqCT37w/view)
3. [NEMA 17 Stepper Motor](https://www.alibaba.com/product-detail/42mm-stepper-motor-JK42HS40-1204D-NEMA17_60232212584.html)

## Wiring Configuration


## Software
The [Arduino Stepper library](https://www.arduino.cc/reference/en/libraries/stepper/) is used. The program is based off its inbuilt examples **stepper_oneRevolution** and **stepper_oneStepAtATime**. 

## Note: 
1. For the NEMA 17 Stepper Motor tested, the datasheet states that for one coil black is the coil end and yellow is the centre tap wire, but it was found that the opposite is true.
2. Select the number of revolutions per step based on the motor used
3. These examples use Signed Magnitude mode on the shield

