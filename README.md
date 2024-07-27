# ESP32 Radar System with Ultrasonic Sensor and LCD Display

This project is an ESP32-based radar system that uses a servo motor to rotate an ultrasonic sensor (HC-SR04) and measures the distance to objects. The distance and angle of detected objects are displayed on a 16x2 I2C LCD screen. The system can detect objects within a specified distance threshold and display the corresponding distance and angle information.

## Components

- **ESP32 Dev Kit**
- **HC-SR04 Ultrasonic Sensor**
- **16x2 I2C LCD Display**
- **Servo Motor (SG90 or similar)**
- **Breadboard and Jumper Wires**

## Features

- **Object Detection**: Detects objects using an ultrasonic sensor.
- **Distance and Angle Display**: Shows the distance and angle of detected objects on an LCD screen.
- **Real-Time Monitoring**: Continuously scans the surroundings and updates the display.

## Wiring

- **HC-SR04 Ultrasonic Sensor**
  - VCC to ESP32 5V
  - GND to ESP32 GND
  - TRIG to ESP32 GPIO 18
  - ECHO to ESP32 GPIO 19

- **Servo Motor**
  - PWM to ESP32 GPIO 26
  - VCC to ESP32 5V
  - GND to ESP32 GND

- **16x2 I2C LCD Display**
  - SDA to ESP32 GPIO 21
  - SCL to ESP32 GPIO 22
  - VCC to ESP32 5V
  - GND to ESP32 GND

## Software

### Dependencies

- `Wire.h` - For I2C communication
- `LiquidCrystal_I2C.h` - For controlling the LCD display
- `NewPing.h` - For interfacing with the HC-SR04 sensor
- `ESP32Servo.h` - For controlling the servo motor

### Installation

1. Install the necessary libraries in your Arduino IDE:
   - `ESP32Servo` by Kevin Harrington
   - `NewPing` by Tim Eckel
   - `LiquidCrystal_I2C` by Frank de Brabander

2. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/esp32-radar-system.git
   cd esp32-radar-system


Open the sketch.ino file in the Arduino IDE.

Upload the code to your ESP32 board.

## Usage
Connect all components according to the wiring diagram above.
Upload the code to the ESP32.
Open the Serial Monitor to view the angle and distance measurements.
The LCD screen will display the current angle and the distance to detected objects in centimeters.
License
This project is licensed under the MIT License. See the LICENSE file for more details.

### Contributing
Contributions are welcome! Please open an issue or submit a pull request for any improvements or new features.

### Acknowledgments
Special thanks to the open-source community and the creators of the libraries used in this project.

