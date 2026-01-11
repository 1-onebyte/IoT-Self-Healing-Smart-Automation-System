# Recovery Engine Module

## Purpose
The Recovery Engine is responsible for autonomous self-healing behavior in the IoT automation system. It ensures system reliability by responding to faults without human intervention.

## Responsibilities
- Detect sensor failures and switch to backup sensors
- Protect the system during overload conditions
- Enter safe mode when recovery is not possible
- Restore normal operation once stability is achieved

## Recovery Scenarios
1. Primary sensor failure → backup sensor activation
2. Overload detection → relay shutdown
3. Multiple faults → safe mode activation
4. Fault cleared → normal operation restored

## Design Approach
The module follows a state-based recovery approach with the following states:
- NORMAL
- SENSOR_FAILOVER
- OVERLOAD_SHUTDOWN
- SAFE_MODE

## Key Advantage
This modular recovery engine improves system reliability, maintainability, and scalability, making the automation system suitable for critical real-world applications.
