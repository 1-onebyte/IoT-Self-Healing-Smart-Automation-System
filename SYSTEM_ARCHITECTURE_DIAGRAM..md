flowchart TB
    subgraph Edge Device (ESP32)
        Sensors
        SensorManager
        FaultDetector
        RecoveryEngine
        NetworkManager
        OverloadGuard
    end

    Sensors --> SensorManager
    SensorManager --> FaultDetector
    FaultDetector --> RecoveryEngine
    RecoveryEngine --> OverloadGuard
    RecoveryEngine --> NetworkManager
    OverloadGuard --> Actuators

    NetworkManager --> Cloud
    Cloud --> Dashboard
