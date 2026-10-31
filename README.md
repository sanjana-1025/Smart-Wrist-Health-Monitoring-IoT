# Smart Wrist Device for Real-Time Health Monitoring of Elders

An Arduino-based IoT prototype documented in the accompanying project report. The reported design uses an Arduino Uno, MAX30102 sensor module, 16x2 LCD, HC-05 Bluetooth module, RTC module, and a power supply.

## Repository contents

- `Arduino_Code/health_monitor.ino` — Arduino sketch transcribed from the source-code section of the submitted report.
- `Project_Report/Smart_Wrist_Device_Final_Report.docx` — original project report.
- `Images/` — images extracted from the report for project documentation.

## Hardware listed in the report

- Arduino Uno
- MAX30102 pulse/heart-rate sensor module
- 16x2 LCD
- HC-05 Bluetooth module
- RTC module
- Power supply and jumper wires

## Software

- Arduino IDE
- Arduino C/C++

## Current code status and limitations

The `.ino` file is transcribed from the report and has not yet been verified on physical hardware. The report lists an HC-05 Bluetooth module and RTC module, but the extracted sketch does not currently contain Bluetooth or RTC initialization/communication code.

The sketch reads the MAX30102 IR signal, uses the SparkFun MAX3010x `MAX30105` library and `heartRate.h` helper to estimate heart rate, reads the sensor's temperature value, and displays values on the LCD.

**Important measurement note:** In the report's sketch, the displayed `spo2` value is derived from a mapping based on the calculated heart-rate value. It is not a validated SpO2 calculation. Do not use this prototype for medical diagnosis or treatment decisions.

## Arduino IDE setup

1. Install Arduino IDE.
2. Open `Arduino_Code/health_monitor.ino`.
3. Install the required libraries:
   - SparkFun MAX3010x Pulse and Proximity Sensor Library (provides `MAX30105.h` and `heartRate.h`)
   - The built-in `Wire` and `LiquidCrystal` libraries are also used.
4. Select **Arduino Uno** under Tools → Board.
5. Select the correct serial port under Tools → Port.
6. Compile the sketch. Connect the circuit and upload only after checking the wiring and voltage requirements of each module.

## Pin information available from the report's sketch

- LCD: RS=8, EN=9, D4=10, D5=11, D6=12, D7=13.
- MAX30102: I2C connection through the Arduino Uno's I2C pins (SDA/SCL).

The report does not specify complete pin wiring for the HC-05 or RTC module, and the extracted sketch does not use them. Confirm the actual circuit before connecting hardware.

## Project evidence

See the original report and extracted images in this repository. Add any original `.ino` files, circuit diagrams, and demonstration videos if you have them.

## Disclaimer

This is an academic prototype, not a certified medical device. Sensor readings can be affected by wiring, placement, calibration, and environmental conditions.

## Wokwi Simulation

Explore the circuit and test the simulated Smart Wrist Health Monitoring System.

[Run Smart Wrist Device Simulation](https://wokwi.com/projects/479430785601511425)

Simulation source files are available in the [Simulation folder](Simulation/).
