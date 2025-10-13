#include "BluetoothSerial.h"   // Library for Bluetooth

BluetoothSerial SerialBT;

// Motor driver pins (L298N / L293D)
#define IN1 2
#define IN2 4
#define IN3 5
#define IN4 18

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void setup() {
  Serial.begin(115200);
  SerialBT.begin("WRANGLER");  // Bluetooth device name

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  stopCar();

  Serial.println("✅ Bluetooth Car Ready. Pair with ESP32-CAR");
}

void loop() {
  if (SerialBT.available()) {
    char command = SerialBT.read();  // Read incoming Bluetooth data
    Serial.println(command);

    switch (command) {
      case 'F': forward(); break;   // Forward
      case 'B': backward(); break;  // Backward
      case 'L': left(); break;      // Left
      case 'R': right(); break;     // Right
      case 'S': stopCar(); break;   // Stop
    }
  }
}
