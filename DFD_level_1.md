flowchart LR
    Sensors --> SensorValidation
    SensorValidation --> FaultDetection
    FaultDetection --> RecoveryEngine
    RecoveryEngine --> Actuators
    RecoveryEngine --> DataLogger
    DataLogger --> Cloud
    Cloud --> Dashboard
