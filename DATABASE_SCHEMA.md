erDiagram
    SENSOR_HEALTH {
        int sensor_id
        string status
        int health_score
        datetime last_updated
    }

    FAULT_LOGS {
        int fault_id
        string fault_type
        string severity
        datetime timestamp
    }

    SYSTEM_EVENTS {
        int event_id
        string event_name
        datetime timestamp
    }

    SENSOR_HEALTH ||--o{ FAULT_LOGS : generates
    FAULT_LOGS ||--o{ SYSTEM_EVENTS : triggers
