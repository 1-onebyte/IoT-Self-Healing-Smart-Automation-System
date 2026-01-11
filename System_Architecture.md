## System Architecture

The IoT Self-Healing Smart Automation System follows a **local-first, fault-tolerant architecture** designed to ensure continuous operation even during sensor failures, overload conditions, or network loss.

At the core of the system is an ESP32 microcontroller that performs real-time monitoring, fault detection, and autonomous recovery at the edge. Sensors continuously send data to the ESP32, where health validation and threshold checks are performed locally without cloud dependency.

The system is modularly designed with separate components for sensor management, fault detection, recovery handling, overload protection, and network management. When a fault is detected, the system automatically switches to backup logic or enters a safe mode, ensuring reliability and safety.

Network connectivity is treated as an enhancement rather than a dependency. In the event of network failure, the system seamlessly switches to local-only control while continuing automation operations. Once connectivity is restored, data synchronization resumes.

This architecture makes the system suitable for real-world critical environments where uptime, safety, and autonomy are essential.
