## 🚗 Bluetooth Controlled Robot Car using ESP32

[cite_start]This project details the creation of a simple, low-cost **Bluetooth-controlled robot car** using an **ESP32 microcontroller** and a **single L298N motor driver**[cite: 3, 6, 8, 157]. [cite_start]The car can be wirelessly operated from a smartphone using a Bluetooth terminal application[cite: 3, 5, 55].

---

## ⚙️ Key Components

[cite_start]The system is built around minimal components to demonstrate wireless control and basic robotics[cite: 6, 160].

| Component | Role | Notes |
| :--- | :--- | :--- |
| **ESP32 Microcontroller** | [cite_start]The **control hub** (brains) of the car[cite: 42, 47]. | [cite_start]Its **integrated Bluetooth** allows it to receive commands from a smartphone without extra hardware[cite: 3, 47]. |
| **Single L298N Motor Driver** | [cite_start]Acts as the **power amplifier**[cite: 48]. | [cite_start]Takes low-power signals from the ESP32 and uses a separate battery to drive the motors[cite: 50]. |
| **Four DC Motors** | [cite_start]The wheels of the car[cite: 51]. | [cite_start]Wired in **two parallel pairs** (left and right sides) to be controlled by the L298N's two channels[cite: 45, 52, 53]. |
| **Motor Battery (7.4V-12V)** | [cite_start]Separate power source[cite: 54]. | [cite_start]Provides the **high current** required to run the motors[cite: 50, 54]. |
| **Smartphone** | [cite_start]The **remote control**[cite: 55]. | [cite_start]Runs a Bluetooth terminal app to send single-character commands (F, B, L, R, S)[cite: 5, 55]. |

---

## 🛠️ Design and Operation

[cite_start]The car is a 4-wheel mobile robotic system[cite: 8].

### Motor Control Strategy
* [cite_start]The system uses an L298N driver which has **only two output channels**[cite: 44, 45].
* [cite_start]The four DC motors are wired in **two parallel pairs** (two motors per side), with each pair acting as a single unit[cite: 45, 52, 53, 159].
* [cite_start]The motors are controlled directly through **direction pins only**, without using the enable (PWM) pins, meaning the car runs at **full speed** when activated[cite: 4, 9].
* [cite_start]**Caution**: The total current of the parallel motors must not exceed the L298N's **2A/channel limit**[cite: 33].

### System Operation Flow
The process involves three stages:
1.  [cite_start]**Command Reception**: The smartphone sends a single-character command via Bluetooth to the ESP32[cite: 58, 59].
2.  [cite_start]**Command Processing**: The ESP32's program monitors for incoming data and uses a `switch` statement (conditional logic) to match the character to a specific action[cite: 60, 61, 114].
3.  [cite_start]**Motor Control**: The ESP32 sends **HIGH/LOW digital signals** to the L298N's input pins, which controls the two motor pairs (left and right)[cite: 62].

### Bluetooth Commands and Logic

| Command | Action | Left Motors (IN1/IN2) | Right Motors (IN3/IN4) |
| :--- | :--- | :--- | :--- |
| **F** | Forward | HIGH/LOW | HIGH/LOW |
| **B** | Backward | LOW/HIGH | LOW/HIGH |
| **L** | Left Turn | LOW/HIGH | HIGH/LOW |
| **R** | Right Turn | HIGH/LOW | LOW/HIGH |
| **S** | Stop | LOW/LOW | LOW/LOW |
| **Default** | Stop | LOW/LOW | LOW/LOW |

---

## 💻 Program Highlights

[cite_start]The code initializes the serial monitor and Bluetooth connection, sets the motor control pins as outputs, and enters a main loop that processes incoming commands[cite: 99, 110].

* [cite_start]**Libraries**: Includes `"BluetoothSerial.h"`[cite: 93].
* [cite_start]**Bluetooth Name**: The ESP32 is initialized with the device name **"WRANGLER"**[cite: 72, 101].
* [cite_start]**Pin Definitions**: The motor driver input pins (IN1, IN2, IN3, IN4) are defined to specific ESP32 GPIO pins[cite: 95, 96, 97, 98].
* [cite_start]**Main Loop**: Continuously checks if a command is available using `SerialBT.available()`[cite: 79, 111]. [cite_start]If data is available, it reads the character (`SerialBT.read()`) and executes the corresponding motor control function via a `switch` statement[cite: 112, 114].

[cite_start]The project provides a practical foundation for future enhancements like obstacle avoidance or speed control (using PWM)[cite: 6, 11, 160].

