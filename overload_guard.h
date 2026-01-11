#ifndef OVERLOAD_GUARD_H
#define OVERLOAD_GUARD_H

#include <Arduino.h>

class OverloadGuard {
private:
  int overloadThreshold;
  bool overloadActive;

public:
  OverloadGuard(int threshold) {
    overloadThreshold = threshold;
    overloadActive = false;
  }

  // Check for overload condition
  bool checkOverload(int currentValue) {
    if (currentValue > overloadThreshold) {
      overloadActive = true;
      Serial.println("[OVERLOAD] Overload detected!");
      return true;
    }
    return false;
  }

  // Handle overload safely
  void shutdownLoad(int relayPin) {
    digitalWrite(relayPin, HIGH); // Relay OFF
    Serial.println("[OVERLOAD] Load disconnected for safety");
  }

  // Reset overload condition
  void reset() {
    overloadActive = false;
    Serial.println("[OVERLOAD] Overload cleared");
  }

  bool isOverloaded() {
    return overloadActive;
  }
};

#endif
