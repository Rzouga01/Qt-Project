#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

#define ACCEL_ADDRESS 0x53 // Example address for accelerometer
#define LCD_ADDRESS 0x27   // I2C address for LCD display

Adafruit_ADXL345_Unified accel;
LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2); // 16x2 LCD
SoftwareSerial BTSerial(9, 8);              // RX, TX pins for Bluetooth

const float accelerationThreshold = 10.0; // Adjust as needed for sensitivity
const int clientId = 81 ;//81,82,83,101;                  // Assuming constant client ID 
int locationId;
// Declare locationId variable

bool accidentDetected = false; // Flag to track accident state
bool showData = false;         // Flag to control client ID/location display

void setup()
{
    Wire.begin();                  // Initialize I2C communication
    randomSeed(analogRead(0));     // Seed the random number generator
    accel.begin();
    lcd.begin(16, 2); // Initialize LCD with 16 columns and 2 rows
    lcd.backlight();
    Serial.begin(9600); // Initialize Serial communication
    BTSerial.begin(9600); // Initialize Bluetooth communication
}

void loop()
{
    locationId = random(1, 25);
    sensors_event_t event;
    accel.getEvent(&event);

    // Calculate weighted delta acceleration
    float deltaAcceleration = abs(event.acceleration.x) + abs(event.acceleration.y) + abs(event.acceleration.z) - 10; // Adjust weight as needed

    accidentDetected = (deltaAcceleration > accelerationThreshold); // Set accident detected flag

    lcd.clear(); // Clear the LCD

    if (accidentDetected)
    {
        lcd.setCursor(0, 0);
        lcd.print("Accident Detected!");
        String dataToSend = String(clientId) + " " + String(locationId) + " " + String(deltaAcceleration);
        Serial.println(dataToSend);
        BTSerial.println(dataToSend);
        delay(1000);
    }
    else
    {
        lcd.print("Delta Accel:");
        lcd.print(deltaAcceleration);
    }

    String receivedData = Serial.readStringUntil('\n'); // Read data from serial until newline

    // Print received data for debugging
    Serial.println("Received data: " + receivedData);

    if (receivedData.startsWith("*"))
    {
        // Parse data
        int spaceIndex = receivedData.indexOf(' ');
        if (spaceIndex > 0 && spaceIndex < receivedData.length())
        {
            // Extract client ID
            String clientIdString = receivedData.substring(1, spaceIndex); // Remove leading/trailing spaces
            String parsedClientId = clientIdString;

            // Extract location
            String locationString = receivedData.substring(spaceIndex + 1);
            String parsedLocation = locationString;

            // Debugging output to verify parsed values
            Serial.println("Parsed Client ID: " + String(parsedClientId));
            Serial.println("Parsed Location: " + String(parsedLocation));

            // Update data for display
            showData = true;

            // Use parsed client ID and location for display
            lcd.clear();
            lcd.setCursor(0, 0); // Move cursor to first line
            lcd.print("Client: ");
            lcd.print(parsedClientId); // Use parsed client ID
            lcd.setCursor(0, 1);       // Move cursor to second line
            lcd.print("Loc: ");
            lcd.print(parsedLocation);

            delay(5000); // Optional delay to show data on LCD
        }
        else
        {
            showData = false; // No valid data parsed (handle invalid substring range)
        }
    }
    else
    {
        showData = false; // Clear flag if message doesn't start with "*"
    }

    delay(500); // Delay between loop iterations
}

