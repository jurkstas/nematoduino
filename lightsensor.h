#include "pin_config.h"

void LightSensorInit() {
  pinMode(LightSensorPin,  INPUT);
}

bool LightSensorActivated() {
  return (digitalRead(LightSensorPin) == 1);
}

