# Refrigerator Monitoring System for Food Safety and Energy Efficiency

## Overview
This project develops a **sensor-based monitoring system** for refrigerators to enhance **food safety** and **energy efficiency**. It utilizes an **MQ-137 ammonia gas sensor** and an **HC-SR04 ultrasonic sensor**, controlled by an **Arduino Uno**, to detect food spoilage and monitor door closure. The system provides **auditory alerts** through a buzzer to warn users of unsafe conditions.

## Features
- **Ammonia Gas Detection**: The MQ-137 sensor detects ammonia levels to assess food spoilage.
- **Door Status Monitoring**: The HC-SR04 ultrasonic sensor determines whether the refrigerator door is left open.
- **Auditory Alerts**:
  - **1000 Hz**: Door open for more than 30 seconds.
  - **2000 Hz**: Ammonia levels exceed **15 ppm**.
  - **5000 Hz**: Both conditions occur simultaneously.
- **Battery-Powered & Portable**: Housed in a **compact enclosure**, the system operates autonomously without external power.

## System Components
- **Arduino Uno**: Microcontroller handling sensor data and alarms.
- **MQ-137 Ammonia Sensor**: Detects ammonia gas concentration.
- **HC-SR04 Ultrasonic Sensor**: Measures the distance to the refrigerator door.
- **Buzzer**: Provides audio alerts.
- **Power Source**: 9V KODAK Super Heavy Duty Zinc Battery.

## Circuit Design
The system integrates all components with the **Arduino Uno**, powered via **5V USB or a 9V battery**. The circuit ensures stable operation and low power consumption. The total **standby power** is **1.225W**, with an estimated battery life of **40 minutes** in real-world conditions.

## Installation & Usage
1. **Assembly**:
   - Mount the **MQ-137 sensor** inside the refrigerator.
   - Position the **HC-SR04** sensor to monitor the door's status.
   - Connect components to the **Arduino Uno** following the circuit diagram.
2. **Calibration**:
   - The **MQ-137** sensor requires **20 seconds** of preheating.
   - Establish **baseline resistance (R0)** in clean air before use.(use the **R0_fresh_air** test in the fresh air and get R0)
   - fill the **R0** in the **course_final** and run it ,the system can work 
3. **Operation**:
   - Place the **sensor enclosure** inside the refrigerator.
   - Power the system using a **9V battery**.
   - Alerts will sound when unsafe conditions are detected.

## Limitations & Future Improvements
- **Sensor Accuracy**:
  - The **MQ-137 calibration** depends on environmental conditions and manual interpolation.
  - **Ultrasonic sensor readings** may be affected by temperature fluctuations.
- **Enhancements**:
  - Replace **HC-SR04** with a **laser-based distance sensor** for improved accuracy.
  - Integrate **visual indicators** (LEDs or an LCD display) for better user feedback.
  - Improve **battery life** with rechargeable lithium-ion batteries.



Demo:
https://liveuclac-my.sharepoint.com/my?id=%2Fpersonal%2Fucfnfen%5Fucl%5Fac%5Fuk%2FDocuments%2FAttachments
