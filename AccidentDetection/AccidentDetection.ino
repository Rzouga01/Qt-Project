#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

#define ACCEL_ADDRESS 0x53  // Example address for accelerometer
#define LCD_ADDRESS 0x27    // I2C address for LCD display

Adafruit_ADXL345_Unified accel;
LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);  // 16x2 LCD
SoftwareSerial BTSerial(9, 8);              // RX, TX pins for Bluetooth

const float accelerationThreshold = 15.0;  // Adjust as needed for sensitivity
const int clientId = 83;
const int locationId = 4;

void setup() {
  Wire.begin();  // Initialize I2C communication
  accel.begin();
  lcd.begin(16, 2);  // Initialize LCD with 16 columns and 2 rows
  lcd.backlight();

  Serial.begin(9600);    // Initialize Serial communication
  BTSerial.begin(9600);  // Initialize Bluetooth communication
}

void loop() {
  sensors_event_t event;
  accel.getEvent(&event);

  // Calculate weighted delta acceleration
  float deltaAcceleration = abs(event.acceleration.x) + abs(event.acceleration.y) + abs(event.acceleration.z);  // Adjust weight as needed

  lcd.clear();  // Clear the LCD

  if (deltaAcceleration > accelerationThreshold) {
    lcd.setCursor(0, 0);
    lcd.print("Accident Detected!");

    String dataToSend =  String(clientId) +"_" + String(locationId) + "_" + String(event.acceleration.x) + "_" + String(event.acceleration.y) + "_" + String(event.acceleration.z);
    Serial.println(dataToSend);
    BTSerial.println(dataToSend);

    delay(2000);  // Display the message for 2 seconds
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Delta Accel:");
    lcd.print(deltaAcceleration); 
  }

  delay(500);
}
