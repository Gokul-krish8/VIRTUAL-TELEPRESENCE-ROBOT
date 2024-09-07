# VIRTUAL-TELEPRESENCE-ROBOT
# VIRTUAL TELEPRESENCE ROBOT

## Table of Contents
1. [Project Overview](#project-overview)
2. [Features](#features)
3. [Components Used](#components-used)
4. [Circuit Diagram](#circuit-diagram)
5. [Hardware Setup](#hardware-setup)
6. [Software Setup](#software-setup)
    - [ESP32 Code](#esp32-code)
    - [Raspberry Pi Code](#raspberry-pi-code)
    - [Raspberry Pi Commands](#raspberry-pi-commands)
7. [Usage](#usage)
8. [Challenges](#challenges)
9. [Future Improvements](#future-improvements)


---

## Project Overview

The **Virtual Telepresence Robot** allows for remote control of a robot using a web interface. It streams real-time video from a camera mounted on the robot and enables motor control for navigation using MQTT communication between a Raspberry Pi and an ESP32 microcontroller.

---

## Features

- Real-time video streaming from the robot’s camera.
- Remote control of motor movements (forward, backward, left, right, stop).
- Utilization of MQTT protocol for communication between Raspberry Pi and ESP32.
- Web interface for controlling the robot and viewing the video stream.

---

## Components Used

- **Raspberry Pi** (with camera module)
- **ESP32** (for motor control)
- **DC Motors** (4x)
- **L298N Motor Driver** (1x)
- **Joystick
- **GPIO Pins** for control connections
- **MQTT Broker** for communication
- **Flask** for the web interface

---

## Block Diagram

![Block diagram](It will be in same repository)

---

## Hardware Setup

1. **Raspberry Pi Setup**:
   - Connect the camera module to the Raspberry Pi.
   - Configure the GPIO pins for communication with the ESP32.

2. **ESP32 Setup**:
   - Connect the ESP32 to the L298N motor driver for controlling the motors.
   - Set up the necessary GPIO pins for motor control.

3. **Motor Driver & Motors**:
   - Connect the motors to the L298N motor driver.
   - Ensure correct wiring to the power supply and motor driver for efficient motor control.

---

## Software Setup

### ESP32 Code

The ESP32 code handles motor control through HTTP communication. This code is provided in the same repository.

### Raspberry Pi Code

The Raspberry Pi code handles video streaming and sends motor control commands to the ESP32 via MQTT. The code includes Flask for the web interface to stream video and control the motors. This code is also provided in the same repository.

### Raspberry Pi Commands

1. **Update and Upgrade Packages:**

    ```bash
    sudo apt-get update
    sudo apt-get upgrade
    ```

2. **Install Necessary Python Libraries:**

    ```bash
    sudo apt-get install python3-pip
    sudo pip3 install flask paho-mqtt
    ```

3. **Install and Configure OpenSSL for HTTPS:**

    ```bash
    sudo apt-get install openssl
    ```

4. **Run the Raspberry Pi Code:**

    Navigate to the directory where your Raspberry Pi code is located and run:

    ```bash
    python3 your_raspberry_pi_code.py
    ```

5. **Set Up the Camera Module (if not already set up):**

    ```bash
    sudo raspi-config
    ```
    - Go to "Interface Options"
    - Enable the camera
    - Reboot the Raspberry Pi

---

## Usage

1. Power on the robot and ensure both the Raspberry Pi and ESP32 are connected to the same network.
2. Access the web interface by navigating to the Raspberry Pi’s IP address on a browser.
3. Use the web interface to control the robot’s movements and view the live video stream.

---

## Challenges

- Implementing seamless communication between the ESP32 and Raspberry Pi.
- Optimizing video streaming performance for real-time control.

---

## Future Improvements

- Enhance video quality and reduce latency.
- Integrate obstacle detection using sensors.
- Add autonomous movement functionality.

---


*Note: The ESP32 and Raspberry Pi code can be found in the same repository and vr live stream will be viewed in the mobile browser and it should be connected
        on same network of the Rpi and esp32.*
