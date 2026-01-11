#ifndef NETWORK_MANAGER_H
#define NETWORK_MANAGER_H

#include <Arduino.h>

class NetworkManager {
private:
  bool networkAvailable;

public:
  NetworkManager() {
    networkAvailable = true;   // assume connected at start
  }

  // Simulate network status (for Wokwi / demo)
  void updateNetworkStatus(bool status) {
    networkAvailable = status;

    if (networkAvailable) {
      Serial.println("[NETWORK] Network connected — Cloud services enabled");
    } else {
      Serial.println("[NETWORK] Network lost — Switching to LOCAL CONTROL");
    }
  }

  bool isNetworkAvailable() {
    return networkAvailable;
  }

  void handleOperation() {
    if (networkAvailable) {
      Serial.println("[NETWORK] Operating in CLOUD + LOCAL mode");
    } else {
      Serial.println("[NETWORK] Operating in LOCAL-ONLY mode");
    }
  }
};

#endif
