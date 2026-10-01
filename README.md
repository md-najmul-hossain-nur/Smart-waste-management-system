# ♻️ Smart Waste Management System

A smart robotic waste collection system that combines **robotics, Bluetooth communication, ultrasonic sensing, a robotic arm, and a mobile application** to support efficient waste collection.

The robot can be controlled through a mobile application developed using **MIT App Inventor** and communicates wirelessly using an **HC-05 Bluetooth module**. The project supports both manual operation and an autonomous waste-collection concept.

---

## ✨ Features

* 🤖 Bluetooth-controlled robotic vehicle
* 📱 Mobile application developed with MIT App Inventor
* 🦾 Six-servo robotic arm
* 🗜️ Gripper mechanism for waste collection
* 📡 HC-SR04 ultrasonic object/obstacle detection
* 🖥️ 16×2 LCD distance display
* 🔄 Manual robotic operation
* ♻️ Waste collection and sorting concept
* 🗺️ Map-based functionality in the mobile application

---

## 🏗️ System Overview

```text
        Mobile Application
        (MIT App Inventor)
                │
                │ Bluetooth
                ▼
          HC-05 Module
                │
                ▼
       Arduino Mega 2560
          Rev3 Controller
          ┌─────┴─────┐
          │           │
          ▼           ▼
       L298N       Robotic Arm
     Motor Driver   + Gripper
          │
          ▼
     DC Motors
      & Wheels

       HC-SR04 Sensor
              │
              ▼
        Distance Detection
              │
              ▼
          16×2 LCD
```

The Arduino Mega 2560 Rev3 manages the robotic platform, motor movement, ultrasonic sensing, robotic arm, and Bluetooth communication.

---

## 🔧 Hardware

| Component                   | Purpose                   |
| --------------------------- | ------------------------- |
| Arduino Mega 2560 Rev3      | Main controller           |
| HC-05 Bluetooth             | Wireless communication    |
| L298N                       | Motor control             |
| DC Motors & Wheels          | Robot movement            |
| HC-SR04                     | Object/obstacle detection |
| Servo Motors                | Robotic arm               |
| Gripper                     | Waste handling            |
| 16×2 I2C LCD                | Distance display          |
| Battery & Voltage Regulator | Power supply              |

The component list is based on the project report.

---

## 💻 Software

* **Arduino IDE**
* **MIT App Inventor**
* Arduino C/C++ sketch
* `Servo.h`
* `NewPing.h`
* `Wire.h`
* `LiquidCrystal_I2C.h`

---

## 🎮 Robot Control

The robotic vehicle supports Bluetooth commands:

```text
F → Forward
B → Backward
L → Left
R → Right
```

The robotic arm contains six controllable sections:

```text
Waist → Shoulder → Elbow → Wrist Roll → Wrist Pitch → Gripper
```

The current implementation controls the servo positions through Bluetooth commands.

---

## 📡 Ultrasonic Detection

The system uses an **HC-SR04 ultrasonic sensor** to measure the distance of nearby objects.

The current Arduino implementation uses:

```text
Maximum Distance: 200 cm
LCD: 16×2
I2C Address: 0x27
```

The measured distance is displayed on the LCD.

---

## 📱 Mobile Application & Map

The mobile application was developed using **MIT App Inventor**.

It provides an interface for:

* Robotic vehicle control
* Robotic arm control
* Gripper operation
* Bluetooth communication
* Waste collection activities

The application also includes a **map-based feature** for location-related waste-management activities.

> The project report does not specify the exact map API, mapping library, or GPS implementation, so those details are not claimed here.

---

## 🔄 How It Works

```text
User
 ↓
Mobile App
 ↓
Bluetooth Communication
 ↓
Arduino Mega 2560
 ↓
 ┌───────────────┬────────────────┐
 ▼               ▼                ▼
Robot         Robotic Arm      Ultrasonic
Movement      + Gripper          Sensor
                                  ↓
                               LCD Display
```

The system allows the user to operate the robot and robotic arm while ultrasonic sensing provides distance information.

---

## 📂 Project Structure

```text
Smart-waste-management-system/
│
└── rov.ino
```

`rov.ino` contains the main Arduino implementation for:

* Motor control
* Robotic arm control
* Ultrasonic sensing
* LCD display

---

## ⚙️ Installation

### 1. Clone the repository

```bash
git clone https://github.com/md-najmul-hossain-nur/Smart-waste-management-system.git
```

### 2. Open the project

Open `rov.ino` using **Arduino IDE**.

### 3. Install libraries

Install:

```text
Servo
NewPing
LiquidCrystal_I2C
Wire
```

### 4. Upload

Select the appropriate Arduino board and COM port, then upload the code to the **Arduino Mega 2560 Rev3**.

---

## 🚀 Future Improvements

* AI-based waste classification
* Autonomous navigation
* GPS-based robot tracking
* Improved map integration
* Cloud-based waste-management system
* Real-time robot monitoring
* Automated waste sorting

The project report identifies AI and machine learning as potential future improvements for intelligent waste differentiation.

---

## 📸 Screenshots

### Mobile Application

*Add mobile app screenshot here.*

### Map Interface

*Add map screenshot here.*

### Robotic Platform

*Add robot screenshot here.*

### Robotic Arm

*Add robotic arm screenshot here.*

---

## 🎥 Project Demo

**YouTube:**
https://youtu.be/vCm7lKVPt6s

---

## 👥 Team

* **Md. Najmul Hossain Nur**
* **Tamjid Alam Taj**
* **Md. Yasin**
* **Md. Refat Hossain Anik**
* **Tanjil Hasan Sawan**

**Department of Computer Science and Engineering**
**United International University, Dhaka, Bangladesh**

---

## 📌 Repository

**GitHub:**
https://github.com/md-najmul-hossain-nur/Smart-waste-management-system

---

## ⭐ Conclusion

The **Smart Waste Management System** demonstrates the integration of a robotic platform, Bluetooth communication, ultrasonic sensing, robotic arm, gripper, LCD monitoring, and a mobile application to support smarter waste collection.

The project provides a foundation for future development toward **autonomous navigation, intelligent waste classification, real-time tracking, and advanced waste-management automation**.
