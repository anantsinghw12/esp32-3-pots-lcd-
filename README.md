# ESP32 Dual Display & Potentiometer Monitor

An ESP32-based embedded project built and simulated on Wokwi that reads analog values from three potentiometers and displays them simultaneously on an **I2C 16x2 LCD** and an **I2C SSD1306 OLED Display**.

## Simulation Link
- [Simulate on Wokwi](https://wokwi.com/projects/480604321866178561)

## Components Used
- ESP32 DevKit C v4
- 16x2 I2C LCD Display (Address: `0x27`)
- 0.96" SSD1306 I2C OLED Display (Address: `0x3C`)
- 3x Potentiometers

## Pin Configuration
| ESP32 Pin | Connected Component |
| :--- | :--- |
| **GPIO 21 (SDA)** | LCD & OLED SDA |
| **GPIO 22 (SCL)** | LCD & OLED SCL |
| **GPIO 34, 35, 32** | Potentiometers Signal (A, B, C) |
