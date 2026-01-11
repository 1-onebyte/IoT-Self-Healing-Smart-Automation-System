# IoT Self‑Healing Smart Automation System

**One‑line Description:**  
An ESP32‑based self‑healing IoT automation system that detects sensor faults and overload conditions locally, autonomously switches to backup logic, and safely maintains operation without human intervention.

---

## Overview

In typical automation systems, failures (sensor disconnection, overload, network loss) can halt operation and require manual intervention. This project implements a **local‑first, edge‑based self‑healing controller** using an ESP32, providing:
- Fault detection
- Redundant sensor failover
- Overload protection
- Local safe mode
- Recovery validation

This design ensures robust operation even under network loss.

---

## Key Features

- **Local‑first control:** Core logic runs on ESP32 without cloud dependency.
- **Redundant sensor failover**
- **Overload and safety management**
- **State validation and recovery**
- **Modular code and documentation**
- **DFD + Database schema included**

---
 
##  Repository Structure

code/

 ├── [Main.ino](<code/Main.ino>)

 ├── [sensor_manager.ino](<code/Sensor_Manager.ino>)
 
 ├── [Fault_detector.ino](<code/Fault_detector.ino>)
 
 ├── [recovery_engine.h.ino](<safety-logic/recovery_engine.h.ino>)
 
 ├── [overload_guard.h](<safety-logic/overload_guard.h>)
 
 ├── [network_manager.h.ino](<data-logging/network_manager.h.ino>)
 
 ├── [ESP32 Arduino Code](code/esp32_self_healing_automation.ino)
 
 diagrams/
 
 ├── [DFD_Level_0.jpeg](<core-architecture/DFD_Level_0.jpeg>)
 
 ├── [DFD_Level_1.jpeg](<core-architecture/DFD_Level_1.jpeg>)
 
 ├── [NORMAL MODE.jpeg](<data-logging/NORMAL MODE.jpeg>)
 
 ├── [SENSOR FAILURE.jpeg](<data-logging/SENSOR FAILURE.jpeg>)
 
 ├── [HEALTH SCORE.jpeg](<data-logging/HEALTH SCORE.jpeg>)
 
 ├── [System Flowchart](<diagrams/Logic flowchart.png>)
 
 ├── [DFD](<diagrams/DFD.png>)
 
 ├── [Logic flowchart.png](<diagrams/Logic flowchart.png>)

docs/

 ├── [SYSTEM_ARCHITECTURE_DIAGRAM..md](<core-architecture/SYSTEM_ARCHITECTURE_DIAGRAM..md>)
 
 ├── [DFD_level_0.md](<core-architecture/DFD_level_0.md>)
 
 ├── [DFD_level_1.md](<core-architecture/DFD_level_1.md>)
 
 ├── [DATABASE_SCHEMA.md](<core-architecture/DATABASE_SCHEMA.md>)
 
 ├── [System_Architecture.md](<core-architecture/System_Architecture.md>)
 
 ├── [network_handling.md](<data-logging/network_handling.md>)
 
 ├── [ Flowchart TB.md](<diagrams/Flowchart TB.md>)
 
 ├── [overload_protection.md](<safety-logic/overload_protection.md>)
 
 ├── [recovery_engine.md](<safety-logic/recovery_engine.md>)

Prototype/

 ├──[Wokwi Simulation](https://wokwi.com/projects/451695512973784065)

 ├── [NORMAL MODE.jpeg](<data-logging/NORMAL MODE.jpeg>)
 
 ├── [SENSOR FAILURE.jpeg](<data-logging/SENSOR FAILURE.jpeg>)
 
 ├── [HEALTH SCORE.jpeg](<data-logging/HEALTH SCORE.jpeg>)

---

## AI Usage Disclosure

AI tools were used only for documentation editing and formatting.
All core design and implementation were created by the team.

**Some of them where :**
- wokwi.com
- mermaid.live

---

## Team Contributions

| Member   | Role & Files                        |
| -------- | ----------------------------------- |
| Member 1 | System architecture, DFD, DB schema |
| Member 2 | Sensor & fault detection            |
| Member 3 | Recovery & safety logic             |
| Member 4 | Data logging & network handling     |

---

### Mapping to Code
- Sensor Input → sensor_manager.h
- Fault Detection → fault_detector.h
- Recovery Actions → recovery_engine.h
- Logging → data_logger.h

---

### Mapping Architecture to Implementation

Each architectural component directly maps to a source module.

- Fault Monitoring Unit → `fault_detector.h`
- Recovery Action Engine → `recovery_engine.h`
- Network Handling → `network_manager.ino`
- Safety Logic → `overload_guard.h`
  
This ensures traceability from design to code.

---

## How to Run the Project
1. Open the Wokwi simulation link
2. Start the simulation
3. Trigger faults by:
   - Disconnecting sensors
   - Simulating overload conditions
4. Observe autonomous recovery behavior in Serial Monitor

---

## How to Run

1. Clone the repository
2. Open code in **Arduino IDE**
3. Install ESP32 board support
4. Upload `main.ino` to ESP32
5. Open Serial Monitor at `115200`

---

## Recovery Mapping Table

| Fault Detected | Module | Recovery Action |
|---------------|--------|-----------------|
| Sensor timeout | fault_detector | Reinitialize sensor |
| Overload | overload_guard | Safe shutdown + restart |
| Network loss | network_manager | Local-only mode |

---

## Fault Handling Validation

| Fault Scenario | Expected Action | Result |
|---------------|----------------|--------|
| Sensor disconnect | Reinitialize sensor | Passed |
| Overload detected | Safe shutdown + restart | Passed |
| Network loss | Local-only mode | Passed |

---

## Design to Implementation Mapping

| Design Component | Source File |
|------------------|------------|
| Sensor Monitoring | sensor_manager.h |
| Fault Detection | fault_detector.h |
| Recovery Engine | recovery_engine.h |
| Overload Protection | overload_guard.h |
| Network Handling | network_manager.ino |

---

## Limitations & Future Work

- Currently uses rule‑based classification
- Can be extended with learning‑based fault prediction
- More hardware redundancy can be added

---

## Originality & Attribution

Inspired by fault‑tolerance principles, this system’s architecture, classification logic, and recovery strategy are **original and team‑designed**. No external implementation has been copied.

---




