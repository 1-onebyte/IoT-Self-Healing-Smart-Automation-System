#ifndef RECOVERY_ENGINE_H
#define RECOVERY_ENGINE_H

#include <Arduino.h>

/*
  Recovery Engine
  Handles:
  - Backup sensor failover
  - Overload shutdown
  - Safe mode activation
  - System recovery
*/

enum SystemState {
  NORMAL,
  SENSOR_FAILOVER,
  OVERLOAD_SHUTDOWN,
  SAFE_MODE
};

class RecoveryEngine {
private:
  SystemState currentState;

public:
  RecoveryEngine() {
    currentState = NORMAL;
  }

  // -------- SENSOR FAILURE HANDLING --------
  bool handleSensorFailure(int primaryVal, int backupVal,
                           int minValid, int maxValid,
                           bool &usingBackup) {

    if (primaryVal < minValid || primaryVal > maxValid) {
      Serial.println("[RECOVERY] Primary sensor failure detected");

      if (backupVal >= minValid && backupVal <= maxValid) {
        usingBackup = true;
        currentState = SENSOR_FAILOVER;
        Serial.println("[RECOVERY] Backup sensor activated");
        return true;
      } else {
        currentState = SAFE_MODE;
        Serial.println("[RECOVERY] No valid backup sensor available");
        return false;
      }
    }
    return true;
  }

  // -------- OVERLOAD HANDLING --------
  bool handleOverload(int currentVal, int overloadThreshold) {
    if (currentVal > overloadThreshold) {
      currentState = OVERLOAD_SHUTDOWN;
      Serial.println("[RECOVERY] Overload detected — shutting down load");
      return true;
    }
    return false;
  }

  // -------- SAFE MODE --------
  void enterSafeMode(int relayPin, int ledPin) {
    currentState = SAFE_MODE;
    digitalWrite(relayPin, HIGH);   // Load OFF
    digitalWrite(ledPin, HIGH);     // LED ON
    Serial.println("[RECOVERY] SAFE MODE ACTIVATED");
  }

  // -------- NORMAL OPERATION --------
  void restoreNormal(int relayPin, int ledPin, bool &usingBackup) {
    currentState = NORMAL;
    usingBackup = false;
    digitalWrite(relayPin, LOW);    // Load ON
    digitalWrite(ledPin, LOW);      // LED OFF
    Serial.println("[RECOVERY] System restored to NORMAL operation");
  }

  SystemState getState() {
    return currentState;
  }
};

#endif
