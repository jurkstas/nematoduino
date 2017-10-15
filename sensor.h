// Reference: http://www.instructables.com/id/Simple-Arduino-and-HC-SR04-Example/

#include "pin_config.h"
#include <NewPing.h>

void SensorInit() {
  //pinMode(tPin, OUTPUT);
  //pinMode(rPin, INPUT);
}

NewPing FrontSensor(tPin, rPin, 500);
NewPing FrontRSensor(tRPin, rRPin, 500);
NewPing FrontLSensor(tLPin, rLPin, 500);
NewPing TailLSensor(tTLPin, rTLPin, 500);
NewPing TailRSensor(tTRPin, rTRPin, 500);

long SensorDistance() {

  //  // Send sound pulse
  //  digitalWrite(tPin, LOW);
  //  delayMicroseconds(2);
  //  digitalWrite(tPin, HIGH);
  //  delayMicroseconds(10);
  //  digitalWrite(tPin, LOW);
  //
  //  // Read off length
  //  long pulseWidth = pulseIn(rPin, HIGH);
  //
  //  // Calculate distance
  //  long distance = (pulseWidth/29.1) / 2;

  long readDistance = FrontSensor.ping_cm();
  if (readDistance == 0) readDistance = 200;
  long distance = readDistance;
  readDistance = FrontRSensor.ping_cm();
  if (readDistance == 0) readDistance = 200;
  distance = (distance < readDistance) ? distance : readDistance;
  readDistance = FrontLSensor.ping_cm();
  if (readDistance == 0) readDistance = 200;
  distance = (distance < readDistance) ? distance : readDistance;
  return distance;
}

long SensorRDistance() {
  int16_t distance = FrontRSensor.ping_cm();
  if (distance == 0) distance = 200;
  return distance;
}

long SensorLDistance() {
  int16_t distance = FrontLSensor.ping_cm();
  if (distance == 0) distance = 200;
  return distance;
}

long SensorTailRightDistance() {
    int16_t distance = TailRSensor.ping_cm();
  if (distance == 0) distance = 200;
  return distance;
}

long SensorTailLeftDistance() {
    int16_t distance = TailLSensor.ping_cm();
  if (distance == 0) distance = 200;
  return distance;
}






