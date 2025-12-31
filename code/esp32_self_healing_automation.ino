/*
  Self-Healing Smart Automation System
  Team - OneByte
  Platform: ESP32
  Prototype: Wokwi / Hardware
*/

// ---------------- PIN DEFINITIONS ----------------
#define PRIMARY_SENSOR_PIN   34   // Potentiometer 1
#define BACKUP_SENSOR_PIN    35   // Potentiometer 2
#define CURRENT_SENSOR_PIN   32   // Potentiometer 3 (Overload)
#define RELAY_PIN            26   // Relay IN
#define STATUS_LED_PIN       2    // LED + resistor

// ---------------- THRESHOLDS ----------------
#define SENSOR_MIN_VALID     200
#define SENSOR_MAX_VALID     3500
#define OVERLOAD_THRESHOLD  3000

// ---------------- VARIABLES ----------------
int healthScore = 100;
bool safeMode = false;
bool usingBackup = false;

// ---------------- SETUP ----------------
void setup() {
  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(STATUS_LED_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, LOW);      // Load ON
  digitalWrite(STATUS_LED_PIN, LOW); // LED OFF

  Serial.println("Self-Healing Automation System Started");
}

// ---------------- MAIN LOOP ----------------
void loop() {
  int primaryValue = analogRead(PRIMARY_SENSOR_PIN);
  int backupValue  = analogRead(BACKUP_SENSOR_PIN);
  int currentValue = analogRead(CURRENT_SENSOR_PIN);

  Serial.println("\n--- Monitoring Cycle ---");
  Serial.print("Primary Sensor: ");
  Serial.println(primaryValue);
  Serial.print("Backup Sensor: ");
  Serial.println(backupValue);
  Serial.print("Current Sensor: ");
  Serial.println(currentValue);

  evaluateHealth(primaryValue, currentValue);

  if (healthScore >= 70) {
    normalOperation();
  } else {
    handleFault(primaryValue, backupValue, currentValue);
  }

  delay(1000);
}

// ---------------- HEALTH EVALUATION ----------------
void evaluateHealth(int sensorVal, int currentVal) {
  healthScore = 100;

  if (sensorVal < SENSOR_MIN_VALID || sensorVal > SENSOR_MAX_VALID) {
    healthScore -= 40;
  }

  if (currentVal > OVERLOAD_THRESHOLD) {
    healthScore -= 60;
  }

  Serial.print("Health Score: ");
  Serial.println(healthScore);
}

// ---------------- NORMAL OPERATION ----------------
void normalOperation() {
  safeMode = false;
  usingBackup = false;

  digitalWrite(RELAY_PIN, LOW);      // Load ON
  digitalWrite(STATUS_LED_PIN, LOW); // LED OFF

  Serial.println("System State: NORMAL OPERATION");
}

// ---------------- FAULT HANDLING ----------------
void handleFault(int primaryVal, int backupVal, int currentVal) {
  Serial.println("System State: FAULT DETECTED");

  // SENSOR FAILURE
  if (primaryVal < SENSOR_MIN_VALID || primaryVal > SENSOR_MAX_VALID) {
    Serial.println("Primary Sensor Failure");

    if (backupVal >= SENSOR_MIN_VALID && backupVal <= SENSOR_MAX_VALID) {
      usingBackup = true;
      Serial.println("Backup Sensor Activated");
      digitalWrite(RELAY_PIN, LOW);   // Keep load ON
      digitalWrite(STATUS_LED_PIN, LOW);
      return;
    }
  }

  // OVERLOAD CONDITION
  if (currentVal > OVERLOAD_THRESHOLD) {
    Serial.println("Overload Detected");
  }

  enterSafeMode();
}

// ---------------- SAFE MODE ----------------
void enterSafeMode() {
  safeMode = true;

  digitalWrite(RELAY_PIN, HIGH);     // Load OFF
  digitalWrite(STATUS_LED_PIN, HIGH); // LED ON

  Serial.println("SAFE MODE ACTIVATED");
}
