/*
MIT License

Copyright (c) 2025 Webrobotix

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

 * Webrobotix 16-Channel RC Servo Controller with PIR Motion Detection
 * Version 1.6.0 - PIR Integration
 * Using Adafruit 16-channel 12-bit servo shield
 * Communicates with Processing for UI control
 * NEW: PIR sensor integration for motion-triggered sequences
 */

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// PWM servo driver instance
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Constants
const int NUM_SERVOS = 16;
const int SERVOMIN = 100;
const int SERVOMAX = 600;
const int SERVO_FREQ = 50;

// PIR Sensor Configuration
const int PIR_PIN = 2;  // Digital pin for PIR sensor (change as needed)
bool pirEnabled = false;
bool pirState = LOW;
bool lastPirState = LOW;
unsigned long pirTriggerTime = 0;
unsigned long pirCooldownPeriod = 5000;  // 5 seconds cooldown between triggers
bool pirSequencePlaying = false;

// Servo positions (0-180 degrees)
int servoPositions[NUM_SERVOS];

// Min/Max limits for each servo (0-180 degrees)
int servoMinLimits[NUM_SERVOS];
int servoMaxLimits[NUM_SERVOS];

// Center positions for each servo (0-180 degrees)
int servoCenterPositions[NUM_SERVOS];

// Active/Inactive state for each servo
bool servoActive[NUM_SERVOS];

// Command parsing
String inputString = "";
boolean stringComplete = false;

void setup() {
  Serial.begin(115200);
  
  // Initialize servo driver
  pwm.begin();
  pwm.setPWMFreq(SERVO_FREQ);
  
  // Initialize PIR sensor pin
  pinMode(PIR_PIN, INPUT);
  
  // Initialize with default values
  initializeDefaults();
  
  // Reserve memory for serial input
  inputString.reserve(50);
  
  Serial.println("Servo Controller with PIR Ready");
  Serial.print("PIR Sensor on Pin: ");
  Serial.println(PIR_PIN);
  
  // Send all current data to Processing on startup
  delay(1000);
  sendAllData();
}

void loop() {
  // Process any incoming commands
  if (stringComplete) {
    processCommand();
    inputString = "";
    stringComplete = false;
  }
  
  // Check PIR sensor if enabled
  if (pirEnabled) {
    checkPIRSensor();
  }
}

// Check PIR sensor for motion detection
void checkPIRSensor() {
  pirState = digitalRead(PIR_PIN);
  
  // Detect rising edge (motion detected)
  if (pirState == HIGH && lastPirState == LOW) {
    // Check if we're past the cooldown period
    if (millis() - pirTriggerTime > pirCooldownPeriod) {
      pirTriggerTime = millis();
      
      // Notify Processing that motion was detected
      Serial.println("PIR:MOTION_DETECTED");
      
      // Optionally trigger a sequence directly from Arduino
      // (or let Processing handle it via the PIR:MOTION_DETECTED message)
    }
  }
  
  lastPirState = pirState;
}

// Initialize all servos with default values
void initializeDefaults() {
  for (int i = 0; i < NUM_SERVOS; i++) {
    servoMinLimits[i] = 0;
    servoMaxLimits[i] = 180;
    servoCenterPositions[i] = 90;
    servoActive[i] = false;
    servoPositions[i] = 90;
    
    // Turn off all PWM outputs
    pwm.setPWM(i, 0, 0);
  }
}

// Function to update servo position
void updateServo(int servoNum) {
  if (servoNum < 0 || servoNum >= NUM_SERVOS) return;
  
  if (servoActive[servoNum]) {
    int pulseWidth = map(servoPositions[servoNum], 0, 180, SERVOMIN, SERVOMAX);
    pwm.setPWM(servoNum, 0, pulseWidth);
  } else {
    pwm.setPWM(servoNum, 0, 0);
  }
}

// Function to process incoming commands
void processCommand() {
  inputString.trim();
  
  if (inputString.startsWith("S:")) {
    // Servo position command: S:servoNum:position
    int firstColon = inputString.indexOf(':');
    int secondColon = inputString.indexOf(':', firstColon + 1);
    
    if (firstColon > 0 && secondColon > firstColon) {
      int servoNum = inputString.substring(firstColon + 1, secondColon).toInt();
      int position = inputString.substring(secondColon + 1).toInt();
      
      if (servoNum >= 0 && servoNum < NUM_SERVOS && position >= 0 && position <= 180) {
        if (servoActive[servoNum]) {
          position = constrain(position, servoMinLimits[servoNum], servoMaxLimits[servoNum]);
          servoPositions[servoNum] = position;
          updateServo(servoNum);
          
          Serial.print("PO:");
          Serial.print(servoNum);
          Serial.print(":");
          Serial.println(position);
        }
      }
    }
  }
  else if (inputString.startsWith("SETMINLIMIT:")) {
    int firstColon = inputString.indexOf(':');
    int secondColon = inputString.indexOf(':', firstColon + 1);
    
    if (firstColon > 0 && secondColon > firstColon) {
      int servoNum = inputString.substring(firstColon + 1, secondColon).toInt();
      int minLimit = inputString.substring(secondColon + 1).toInt();
      
      if (servoNum >= 0 && servoNum < NUM_SERVOS && minLimit >= 0 && minLimit <= 180) {
        servoMinLimits[servoNum] = minLimit;
        Serial.print("MI:");
        Serial.print(servoNum);
        Serial.print(":");
        Serial.println(minLimit);
      }
    }
  }
  else if (inputString.startsWith("SETMAXLIMIT:")) {
    int firstColon = inputString.indexOf(':');
    int secondColon = inputString.indexOf(':', firstColon + 1);
    
    if (firstColon > 0 && secondColon > firstColon) {
      int servoNum = inputString.substring(firstColon + 1, secondColon).toInt();
      int maxLimit = inputString.substring(secondColon + 1).toInt();
      
      if (servoNum >= 0 && servoNum < NUM_SERVOS && maxLimit >= 0 && maxLimit <= 180) {
        servoMaxLimits[servoNum] = maxLimit;
        Serial.print("MA:");
        Serial.print(servoNum);
        Serial.print(":");
        Serial.println(maxLimit);
      }
    }
  }
  else if (inputString.startsWith("SETCENTER:")) {
    int firstColon = inputString.indexOf(':');
    int secondColon = inputString.indexOf(':', firstColon + 1);
    
    if (firstColon > 0 && secondColon > firstColon) {
      int servoNum = inputString.substring(firstColon + 1, secondColon).toInt();
      int centerPos = inputString.substring(secondColon + 1).toInt();
      
      if (servoNum >= 0 && servoNum < NUM_SERVOS && centerPos >= 0 && centerPos <= 180) {
        servoCenterPositions[servoNum] = centerPos;
        Serial.print("CE:");
        Serial.print(servoNum);
        Serial.print(":");
        Serial.println(centerPos);
      }
    }
  }
  else if (inputString.startsWith("RESET:")) {
    int servoNum = inputString.substring(6).toInt();
    if (servoNum >= 0 && servoNum < NUM_SERVOS) {
      servoMinLimits[servoNum] = 0;
      servoMaxLimits[servoNum] = 180;
      servoCenterPositions[servoNum] = 90;
      
      Serial.print("RE:");
      Serial.print(servoNum);
      Serial.print(":");
      Serial.println("RESET");
    }
  }
  else if (inputString.startsWith("ACTIVE:")) {
    int firstColon = inputString.indexOf(':');
    int secondColon = inputString.indexOf(':', firstColon + 1);
    
    if (firstColon > 0 && secondColon > firstColon) {
      int servoNum = inputString.substring(firstColon + 1, secondColon).toInt();
      int state = inputString.substring(secondColon + 1).toInt();
      
      if (servoNum >= 0 && servoNum < NUM_SERVOS) {
        servoActive[servoNum] = (state == 1);
        updateServo(servoNum);
        
        Serial.print("AC:");
        Serial.print(servoNum);
        Serial.print(":");
        Serial.println(servoActive[servoNum] ? 1 : 0);
      }
    }
  }
  else if (inputString.equals("ALLACTIVE")) {
    for (int i = 0; i < NUM_SERVOS; i++) {
      servoActive[i] = true;
      updateServo(i);
      Serial.print("AC:");
      Serial.print(i);
      Serial.print(":");
      Serial.println(1);
    }
  }
  else if (inputString.equals("ALLINACTIVE")) {
    for (int i = 0; i < NUM_SERVOS; i++) {
      servoActive[i] = false;
      updateServo(i);
      Serial.print("AC:");
      Serial.print(i);
      Serial.print(":");
      Serial.println(0);
    }
  }
  else if (inputString.startsWith("PIR:")) {
    // PIR control commands
    if (inputString.equals("PIR:ENABLE")) {
      pirEnabled = true;
      Serial.println("PIR:ENABLED");
    }
    else if (inputString.equals("PIR:DISABLE")) {
      pirEnabled = false;
      Serial.println("PIR:DISABLED");
    }
    else if (inputString.startsWith("PIR:COOLDOWN:")) {
      // Set cooldown period: PIR:COOLDOWN:milliseconds
      int cooldown = inputString.substring(13).toInt();
      if (cooldown >= 0 && cooldown <= 60000) {  // Max 60 seconds
        pirCooldownPeriod = cooldown;
        Serial.print("PIR:COOLDOWN:");
        Serial.println(cooldown);
      }
    }
    else if (inputString.equals("PIR:STATUS")) {
      Serial.print("PIR:STATUS:");
      Serial.print(pirEnabled ? "ENABLED" : "DISABLED");
      Serial.print(":");
      Serial.print(pirCooldownPeriod);
      Serial.print(":");
      Serial.println(digitalRead(PIR_PIN) == HIGH ? "MOTION" : "CLEAR");
    }
  }
  else if (inputString.equals("SAVE")) {
    Serial.println("LI:ACKNOWLEDGED");
  }
  else if (inputString.equals("GETALL")) {
    sendAllData();
  }
}

// Function to send all servo data to Processing
void sendAllData() {
  for (int i = 0; i < NUM_SERVOS; i++) {
    Serial.print("PO:");
    Serial.print(i);
    Serial.print(":");
    Serial.println(servoPositions[i]);
    
    Serial.print("MI:");
    Serial.print(i);
    Serial.print(":");
    Serial.println(servoMinLimits[i]);
    
    Serial.print("MA:");
    Serial.print(i);
    Serial.print(":");
    Serial.println(servoMaxLimits[i]);
    
    Serial.print("CE:");
    Serial.print(i);
    Serial.print(":");
    Serial.println(servoCenterPositions[i]);
    
    Serial.print("AC:");
    Serial.print(i);
    Serial.print(":");
    Serial.println(servoActive[i] ? 1 : 0);
    
    delay(10);
  }
  
  // Send PIR status
  Serial.print("PIR:STATUS:");
  Serial.print(pirEnabled ? "ENABLED" : "DISABLED");
  Serial.print(":");
  Serial.print(pirCooldownPeriod);
  Serial.print(":");
  Serial.println(digitalRead(PIR_PIN) == HIGH ? "MOTION" : "CLEAR");
}

// Serial event handler
void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
