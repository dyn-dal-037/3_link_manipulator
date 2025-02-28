# **3-Link Robotic Manipulator using ESP32 & ST3215 Servos**

## **Overview**
This project is a **3-link robotic arm** controlled by an **ESP32 microcontroller**, utilizing **ST3215 serial bus servos** and a **Waveshare General Motor Driver**. The system reads **predefined joint angles from a CSV file** and employs **inverse kinematics** for precise movement. It is designed for **robotics research, automation, and motion control applications**.

## **Features**
- **ESP32-based Control** – Manages real-time servo movements efficiently.
- **Serial Bus Communication** – Ensures precise and coordinated actuation.
- **CSV-based Motion Planning** – Automates movements with precomputed angles.
- **Inverse Kinematics** – Calculates joint angles for accurate end-effector positioning.
- **Modular & Scalable** – Easily extendable for more complex robotic applications.

## **Hardware & Components**
- **Microcontroller**: ESP32
- **Servos**: 253 ST3215 Serial Bus Servos
- **Motor Driver**: Waveshare General Motor Driver
- **Power Supply**: 12V DC (Servos), 5V (ESP32)
- **Frame**: Custom-built 3-link robotic arm

## **Software & Technologies**
- **Languages**: C++ (ESP32 Firmware), Python (Data Processing & Kinematics)
- **Libraries & Frameworks**:
  - Arduino framework for ESP32
  - PySerial for serial communication
  - NumPy for inverse kinematics calculations

## **Installation & Usage**
1. **Upload the ESP32 firmware** to the microcontroller.
2. **Run the Python script** to generate or read CSV motion data.
3. **Execute movements** based on the CSV input.

For any questions or contributions, feel free to **open an issue** or **submit a pull request**! 🚀
