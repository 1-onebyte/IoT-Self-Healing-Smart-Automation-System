#ifndef FAULT_DETECTOR_H
#define FAULT_DETECTOR_H

#include <Arduino.h>

enum FaultType {
  NO_FAULT,
  SENSOR_FAILURE,
  OVERLOAD_FAULT
};

class FaultDetector {
private:
  int minValid;
  int maxValid;
  int overloadThreshold;

public:
  FaultDetector(int minVal, int maxVal, int overloadVal) {
    minValid = minVal;
    maxValid = maxVal;
    overloadThreshold = overloadVal;
  }

  FaultType detectSensorFault(int sensorValue) {
    if (sensorValue < minValid || sensorValue > maxValid) {
      Serial.println("[FAULT] Sensor value out of range");
      return SENSOR_FAILURE;
    }
    return NO_FAULT;
  }

  FaultType detectOverload(int currentValue) {
    if (currentValue > overloadThreshold) {
      Serial.println("[FAULT] Overload condition detected");
      return OVERLOAD_FAULT;
    }
    return NO_FAULT;
  }
};

#endif
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
