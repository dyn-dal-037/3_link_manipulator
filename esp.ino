#include <HardwareSerial.h>

#define RXD2 16 // ESP32 RX pin
#define TXD2 17 // ESP32 TX pin

HardwareSerial mySerial(2); // Create a new hardware serial instance for the motor driver

// ST3215 Servo Motor Commands
#define SET_POSITION 0x01
#define SET_SPEED 0x03
#define READ_POSITION 0x02
#define SERVO_ID 1 // The ID of your servo motor, change if using multiple servos

void setup() {
  Serial.begin(115200);       // Initialize Serial Monitor
  mySerial.begin(115200, SERIAL_8N1, RXD2, TXD2); // Initialize communication with the servo driver
  
  delay(1000);
  setServoPosition(SERVO_ID, 512); // Move the servo to the middle position
}

void loop() {
  // You can add your control logic here, e.g., move the servo to different positions
  setServoPosition(SERVO_ID, 300); // Move the servo to position 300
  delay(1000);
  setServoPosition(SERVO_ID, 700); // Move the servo to position 700
  delay(1000);
}

// Function to set the servo position
void setServoPosition(uint8_t id, uint16_t position) {
  uint8_t checksum = ~(id + SET_POSITION + 2 + (position & 0xFF) + ((position >> 8) & 0xFF));
  uint8_t command[] = {0x55, 0x55, id, 0x03, SET_POSITION, (uint8_t)(position & 0xFF), (uint8_t)((position >> 8) & 0xFF), checksum};
  
  mySerial.write(command, sizeof(command));
}

// Function to read the servo position (example)
uint16_t readServoPosition(uint8_t id) {
  uint8_t checksum = ~(id + READ_POSITION + 0x02);
  uint8_t command[] = {0x55, 0x55, id, 0x02, READ_POSITION, checksum};
  
  mySerial.write(command, sizeof(command));
  
  delay(20); // Wait for the response
  
  if (mySerial.available()) {
    uint8_t response[8];
    mySerial.readBytes(response, 8);
    return (response[6] << 8) | response[5];
  }
  
  return 0; // Return 0 if no response
}
