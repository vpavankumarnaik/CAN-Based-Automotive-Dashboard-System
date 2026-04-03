# CAN-Based-Automotive-Dashboard-System

An embedded systems project that demonstrates a Controller Area Network (CAN) based automotive dashboard system using a PIC18F4580 microcontroller. The system simulates communication between multiple Electronic Control Units (ECUs) to acquire vehicle parameters and display them on a central dashboard.

# 📌 Project Overview

Modern vehicles use the CAN bus to allow multiple ECUs to communicate efficiently.
This project implements a 3-ECU architecture where different nodes collect vehicle data and transmit it over the CAN network to a central display unit.

The system demonstrates real-time data acquisition, CAN communication, and embedded firmware development.

# 🏗 System Architecture

The system consists of three ECUs:

ECU1 – Sensor Node
Reads sensor data such as speed, RPM, and gear position.
Converts analog values using ADC.
Sends data to the CAN network.
ECU2 – Control/Input Node
Handles user input through a digital keypad.
Processes input commands and sends updates over CAN.
ECU3 – Display Node
Receives CAN messages from other ECUs.
Displays vehicle information on a CLCD display.

Communication between these ECUs occurs through the CAN protocol, enabling reliable real-time data exchange.

# ⚙️ Technologies Used
Embedded C
PIC18F4580 Microcontroller
CAN Protocol
ADC (Analog to Digital Converter)
Digital Keypad Interface
CLCD Display
MPLAB IDE
XC8 Compiler

# 🔑 Key Features
Multi-node CAN communication between ECUs
Real-time sensor data acquisition
ADC integration for reading analog inputs
Keypad interface for user interaction
CLCD dashboard display
Modular ECU-based embedded architecture

# 🧠 Key Learnings
Configuration of CAN communication (bit timing, message IDs, and data framing).
Implementation of inter-ECU communication using CAN bus.
Integration of multiple peripherals including ADC, keypad, and display.
Debugging hardware-software interaction issues in embedded systems.
Designing a modular automotive-style ECU architecture.

CAN-Based-Automotive-Dashboard-System
│
├── ECU1_Sensor_Node
│   ├── main.c
│   ├── adc.c
|   ├── digital_keypad.c
│   └── can.c
│
├── ECU2_Input_Node
│   ├── main.c
│   ├── adc.c
│   ├── digital_keypad.c
│   └── can.c
│
├── ECU3_Display_Node
│   ├── main.c
│   ├── clcd.c
│   ├── timer0.c
│   └── can.c
│
└── README.md

# 🚀 How to Run
Open the project in MPLAB IDE.
Compile using the XC8 compiler.
Program the firmware into the PIC18F4580 boards.
Connect the ECUs through a CAN bus network.
Run the system to observe real-time dashboard updates.

