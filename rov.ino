/*
  Combined Robot Sketch
  ---------------------
  Modules:
    1. Bluetooth Car (Motor) Control
    2. Bluetooth Servo Arm Control
    3. Ultrasonic Distance Sensor + LCD Display

  NOTE: All three modules currently read from Serial.read(),
  and two of them (motor + servo) use overlapping single-char
  commands. If you run all three together, you'll need to route
  commands (e.g. prefix bytes) so they don't collide. As written,
  each module is self-contained and can be used independently by
  calling its setupX()/loopX() from the main setup()/loop().
*/

#include <Servo.h>
#include <NewPing.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ============================================================
// MODULE 1: Motor Control (Bluetooth Car)
// ============================================================
int IN1 = 7; // Left motor forward
int IN2 = 6; // Left motor backward
int IN3 = 5; // Right motor forward
int IN4 = 4; // Right motor backward
int bukPower = 8; // Pin 8 controls the BUK transistor

void setupBluetoothWithMotorControl() {
  // Start serial communication for Bluetooth
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(bukPower, OUTPUT);
  digitalWrite(bukPower, HIGH); // Enable motor power
}

void loopBluetoothWithMotorControl() {
  // Car control via Bluetooth
  if (Serial.available() > 0) {
    char command = Serial.read();
    stopCar(); // Initialize with motors stopped
    switch (command) {
      case 'F':
        moveForward();
        break;
      case 'B':
        moveBackward();
        break;
      case 'L':
        turnLeft();
        break;
      case 'R':
        turnRight();
        break;
      default:
        stopCar(); // Stop the car if an invalid command is received
    }
  }
}

// Move the car forward
void moveForward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Move the car backward
void moveBackward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Turn the car left
void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Turn the car right
void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// Stop the car
void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}


// ============================================================
// MODULE 2: Servo Motor Control for Robotic Arm
// ============================================================
Servo s1; // Servo 1 - Waist
Servo s2; // Servo 2 - Shoulder
Servo s3; // Servo 3 - Elbow
Servo s4; // Servo 4 - Wrist Roll
Servo s5; // Servo 5 - Wrist Pitch
Servo s6; // Servo 6 - Gripper

int servo1 = 90;
int servo2 = 110;
int servo3 = 40;
int servo4 = 50;
int servo5 = 90;
int servo6 = 90;

void setupServoControl() {
  // Attach servos to their respective pins
  s1.attach(8);  // Waist
  s2.attach(9);  // Shoulder
  s3.attach(10); // Elbow
  s4.attach(11); // Wrist Roll
  s5.attach(12); // Wrist Pitch
  s6.attach(13); // Gripper

  s1.write(servo1);
  s2.write(servo2);
  s3.write(servo3);
  s4.write(servo4);
  s5.write(servo5);
  s6.write(servo6);
}

void loopServoControl() {
  // Arm Movement Control via Bluetooth
  if (Serial.available() > 0) {
    char command = Serial.read();
    switch (command) {
      case 'Z':
        if (servo1 < 180) servo1 += 5; // Waist move right
        s1.write(servo1);
        break;
      case 'z':
        if (servo1 > 0) servo1 -= 5; // Waist move left
        s1.write(servo1);
        break;
      case 'A':
        if (servo2 > 0) servo2 -= 5; // Shoulder down
        s2.write(servo2);
        break;
      case 'b':
        if (servo2 < 180) servo2 += 5; // Shoulder up
        s2.write(servo2);
        break;
      case 'C':
        if (servo3 > 0) servo3 -= 5; // Elbow down
        s3.write(servo3);
        break;
      case 'D':
        if (servo3 < 180) servo3 += 5; // Elbow up
        s3.write(servo3);
        break;
      case 'E':
        if (servo4 < 180) servo4 += 5; // Wrist roll clockwise
        s4.write(servo4);
        break;
      case 'f':
        if (servo4 > 0) servo4 -= 5; // Wrist roll counter-clockwise
        s4.write(servo4);
        break;
      case 'G':
        if (servo5 < 180) servo5 += 5; // Wrist pitch up
        s5.write(servo5);
        break;
      case 'H':
        if (servo5 > 0) servo5 -= 5; // Wrist pitch down
        s5.write(servo5);
        break;
      case 'I':
        if (servo6 < 180) servo6 += 5; // Gripper open
        s6.write(servo6);
        break;
      case 'J':
        if (servo6 > 0) servo6 -= 5; // Gripper close
        s6.write(servo6);
        break;
    }
  }
}


// ============================================================
// MODULE 3: Ultrasonic Distance Sensor + LCD Display
// ============================================================
#define TRIGGER_PIN 3   // Trigger and Echo on Pin 3 (as per your setup)
#define ECHO_PIN 3
#define VCC_PIN 0       // VCC on Pin 0
#define GND_PIN 1       // Ground on Pin 1
#define MAX_DISTANCE 200 // Maximum distance to ping for (in cm)

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD address 0x27, 16 chars, 2 lines

void setupUltrasonicSensor() {
  lcd.begin(16, 2); // Initialize LCD
  lcd.backlight();  // Turn on backlight
}

void loopUltrasonicSensor() {
  int distance = sonar.ping_cm(); // Get distance in cm
  lcd.clear();               // Clear the LCD display
  lcd.setCursor(0, 0);       // Set cursor to first row
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm");
  delay(100);
}


// ============================================================
// MAIN SETUP / LOOP
// ============================================================
void setup() {
  setupBluetoothWithMotorControl();
  setupServoControl();
  setupUltrasonicSensor();
}

void loop() {
  loopBluetoothWithMotorControl();
  loopServoControl();
  loopUltrasonicSensor();
}
