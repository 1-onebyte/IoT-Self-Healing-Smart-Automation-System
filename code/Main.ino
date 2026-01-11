#include "recovery_engine.h"

RecoveryEngine recovery;

void setup() {
  Serial.begin(9600);
}

void loop() {
  bool sensorFailed = true;       // simulate failure
  bool backupAvailable = true;    // simulate backup

  if (sensorFailed) {
    recovery.handleSensorFailure(backupAvailable);
    delay(2000);
    recovery.attemptRecovery();
    delay(2000);
    recovery.restoreNormal();
  }

  delay(5000);
}
