# Automatic Pet Feeder

## Overview

This project is an **Automatic Pet Feeder** built using the ESP32-WROOM-32 microcontroller. The feeder automatically opens its lid every 5 hours to dispense food for your pet. Additionally, the lid can be controlled remotely via the Blynk IoT app, allowing you to feed your pet at any time from your smartphone.

## Features

- **Automatic Feeding:** The lid opens automatically every 5 hours to feed your pet.
- **Remote Control:** You can open and close the lid remotely using the Blynk IoT app, providing flexibility in feeding times.
- **Blynk Integration:** The feeder is integrated with the Blynk platform, enabling remote control through a user-friendly mobile app.

## Hardware Components

- ESP32-WROOM-32
- Servo Motor
- Breadboard
- Jumper Wires
- Power Supply (e.g., USB or battery)

## Pin Configuration

- **Servo Motor:**
  - **GND:** Connect to ESP32's GND
  - **Power:** Connect to ESP32's 3V3
  - **Signal:** Connect to ESP32's GPIO D2

## Software Requirements

- Arduino IDE
- Blynk Library
- ESP32Servo Library

## Setup Instructions

1. **Hardware Setup:**
   - Connect the servo motor to the ESP32 as per the pin configuration mentioned above.
   - Ensure that all connections are secure and the power supply is stable.

2. **Software Setup:**
   - Install the Arduino IDE and necessary libraries (`Blynk`, `ESP32Servo`).
   - Load the provided Arduino code into the IDE.
   - Replace the `auth`, `ssid`, and `pass` variables with your Blynk Auth token, WiFi SSID, and WiFi password.
   - Upload the code to the ESP32 using the appropriate COM port.

3. **Blynk App Setup:**
   - Download the Blynk app from the App Store or Google Play.
   - Create a new project in the Blynk app and select the ESP32 device.
   - Add a Button widget in the Blynk app and link it to virtual pin V2 to control the servo.

## Usage

- **Automatic Mode:** The lid opens automatically every 5 hours to dispense food. You can adjust the timing interval in the code if necessary.
- **Manual Control:** Use the Blynk app to open or close the lid remotely by pressing the button linked to V2.

## Troubleshooting

- If the ESP32 fails to connect to WiFi, double-check the `ssid` and `pass` values.
- Ensure that the servo motor is properly powered. If it does not move, check the connections and power supply.
