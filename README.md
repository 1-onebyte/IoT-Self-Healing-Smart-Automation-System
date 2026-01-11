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
 
## 📁 Repository Structure
├── code/
│ ├── main.ino
│ ├── config.h
│ ├── sensor_manager.h
│ ├── fault_detector.h
│ ├── recovery_engine.h
│ ├── overload_guard.h
│ ├── [network_manager.h.ino](<data-logging/network_manager.h.ino>)
| ├── [ESP32 Arduino Code](code/esp32_self_healing_automation.ino)
│ └── data_logger.h
├── diagrams/
│ ├── [DFD_Level_0.jpeg](<core-architecture/DFD_Level_0.jpeg>)
│ ├── [DFD_Level_1.jpeg](<core-architecture/DFD_Level_1.jpeg>)
│ ├── [NORMAL MODE.jpeg](<data-logging/NORMAL MODE.jpeg>)
│ ├── [SENSOR FAILURE.jpeg](<data-logging/SENSOR FAILURE.jpeg>)
│ ├── [HEALTH SCORE.jpeg](<data-logging/HEALTH SCORE.jpeg>)
| ├── [System Flowchart](<diagrams/Logic flowchart.png>)
| ├── [DFD](<diagrams/DFD.png>)
│ └── [Logic flowchart.png](<diagrams/Logic flowchart.png>)
├── docs/
│ ├── [SYSTEM_ARCHITECTURE_DIAGRAM..md](<core-architecture/SYSTEM_ARCHITECTURE_DIAGRAM..md>)
│ ├── [DFD_level_0.md](<core-architecture/DFD_level_0.md>)
│ ├── [DFD_level_1.md](<core-architecture/DFD_level_1.md>)
│ ├── [DATABASE_SCHEMA.md](<core-architecture/DATABASE_SCHEMA.md>)
| ├── [System_Architecture.md](<core-architecture/System_Architecture.md>)
| ├── [network_handling.md](<data-logging/network_handling.md>)
| ├── [ Flowchart TB.md](<diagrams/Flowchart TB.md>)
│ ├── [overload_protection.md](<safety-logic/overload_protection.md>)
│ └── [recovery_engine.md](<safety-logic/recovery_engine.md>)
├── Prototype/
| ├──[Wokwi Simulation](https://wokwi.com/projects/451695512973784065)
│ ├── [NORMAL MODE.jpeg](<data-logging/NORMAL MODE.jpeg>)
│ ├── [SENSOR FAILURE.jpeg](<data-logging/SENSOR FAILURE.jpeg>)
| └── [HEALTH SCORE.jpeg](<data-logging/HEALTH SCORE.jpeg>)


