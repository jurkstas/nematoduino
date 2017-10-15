#include "pin_config.h"

const uint8_t spdBoost = 50;
const uint8_t turnTime = 0;

void MotorsInit() {
  pinMode(leftMotor1PinA, OUTPUT);
  pinMode(leftMotor1PinB, OUTPUT);
  pinMode(rightMotor1PinA, OUTPUT);
  pinMode(rightMotor1PinB, OUTPUT);
    pinMode(leftMotor2PinA, OUTPUT);
  pinMode(leftMotor2PinB, OUTPUT);
  pinMode(rightMotor2PinA, OUTPUT);
  pinMode(rightMotor2PinB, OUTPUT);
}

void rightMotorForward(uint8_t spd) {
  analogWrite(rightMotor1PinA, spd);
  digitalWrite(rightMotor1PinB, LOW);
   analogWrite(rightMotor2PinA, spd);
  digitalWrite(rightMotor2PinB, LOW); 
}

void rightMotorBackward(uint8_t spd) {
  digitalWrite(rightMotor1PinA, LOW);
  analogWrite(rightMotor1PinB, spd);
    digitalWrite(rightMotor2PinA, LOW);
  analogWrite(rightMotor2PinB, spd);
}

void rightMotorOff() {
  digitalWrite(rightMotor1PinA, LOW);
  digitalWrite(rightMotor1PinB, LOW);
    digitalWrite(rightMotor2PinA, LOW);
  digitalWrite(rightMotor2PinB, LOW);
}

void leftMotorForward(uint8_t spd) {
  analogWrite(leftMotor1PinA, spd);
  digitalWrite(leftMotor1PinB, LOW);
    analogWrite(leftMotor2PinA, spd);
  digitalWrite(leftMotor2PinB, LOW);
}

void leftMotorBackward(uint8_t spd) {
  digitalWrite(leftMotor1PinA, LOW);
  analogWrite(leftMotor1PinB, spd);
    digitalWrite(leftMotor2PinA, LOW);
  analogWrite(leftMotor2PinB, spd);
}

void leftMotorOff() {
  digitalWrite(leftMotor1PinA, LOW);
  digitalWrite(leftMotor1PinB, LOW);
    digitalWrite(leftMotor2PinA, LOW);
  digitalWrite(leftMotor2PinB, LOW);
}

void RunMotors(int16_t leftSpd, int16_t rightSpd) {
  int16_t speedDifference = leftSpd - rightSpd;
  leftSpd += speedDifference * 5;
  rightSpd -= speedDifference * 5;

  uint8_t leftSpdMotor;
  uint8_t rightSpdMotor;
  Serial.print(leftSpd);
  Serial.print(" ");
  Serial.println(rightSpd);
  // Left forward
  if(leftSpd >= 0) {
    leftSpd += spdBoost;
    
    if(leftSpd > 255) {
      leftSpdMotor = 255;
    }
    else {
      leftSpdMotor = leftSpd;
    }
    leftMotorForward(leftSpdMotor);
  }
  // Left backward
  else if(leftSpd < 0) {
    leftSpd -= spdBoost;
    if(abs(leftSpd) > 255) {
      leftSpdMotor = 255;
    }
    else {
      leftSpdMotor = abs(leftSpd);
    }
    leftMotorBackward(leftSpdMotor);
  }

    // Right forward
  if(rightSpd >= 0) {
    rightSpd += spdBoost;
    if(rightSpd > 255) {
      rightSpdMotor = 255;
    }
    else {
      rightSpdMotor = rightSpd;
    }
    rightMotorForward(rightSpdMotor);
  }
  // Right backward
  else if(rightSpd < 0) {
    rightSpd -= spdBoost;
    if(abs(rightSpd) > 255) {
      rightSpdMotor = 255;
    }
    else {
      rightSpdMotor = abs(rightSpd);
    }
    rightMotorBackward(rightSpdMotor);
  }

  if((rightSpd > 0) && (leftSpd < 0)) {
    delay(turnTime);
  }
  else if((rightSpd < 0) && (leftSpd > 0)) {
    delay(turnTime);
  }
}

void MotorsOff() {
  leftMotorOff();
  rightMotorOff();
}

