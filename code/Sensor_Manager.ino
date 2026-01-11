#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#include <Arduino.h>

class SensorManager {
private:
  int primaryPin;
  int backupPin;

public:
  SensorManager(int primary, int backup) {
    primaryPin = primary;
    backupPin = backup;
  }

  int readPrimary() {
    return analogRead(primaryPin);
  }

  int readBackup() {
    return analogRead(backupPin);
  }

  bool isValid(int value, int minVal, int maxVal) {
    return (value >= minVal && value <= maxVal);
  }
};

#endif
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
