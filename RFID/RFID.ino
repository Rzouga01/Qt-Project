#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
#define BUZZER_PIN 2
#define RED_LED 5
#define GREEN_LED 6
#define LOCKED_POSITION 70
#define UNLOCKED_POSITION 160


const int MELODY_NOTES[] = {523, 392, 392, 440, 392, 493, 523};
const int MELODY_DURATIONS[] = {200, 100, 100, 200, 400, 200, 200};
const int DOOR_CLOSE_DELAY = 10000; 
// Pins
Servo doorLock;
LiquidCrystal_I2C lcd(0x27, 16, 2);
MFRC522 rfid(SS_PIN, RST_PIN);


byte doorLocked = 0;
unsigned long doorCloseTimer = 0;

void setup();
void loop();
void scanRFID();
void handleCommand(String command);
void buzzerSignal(int type);
void alert();
void playWelcomeSound();
void openDoor();
void closeDoor();
void updateLCDTimer();
void turnOffLEDs();

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  Serial.begin(9600);
  doorLock.attach(3);
  doorLock.write(LOCKED_POSITION);
  lcd.init();
  lcd.backlight();
  SPI.begin();
  rfid.PCD_Init();
  playWelcomeSound();
}

void loop() {
  static boolean timerDisplayed = false;

 
  scanRFID();
  if (doorCloseTimer > 0 && millis() >= doorCloseTimer) {
    closeDoor();
  }

  if (!timerDisplayed && doorLocked == 1) {
    updateLCDTimer();
    timerDisplayed = true;
  }

 
  if (doorLocked == 0) {
    turnOffLEDs();
  }
  
  
  if (doorLocked == 1) {
    updateLCDTimer();
  }
}

void scanRFID() {
  if (!rfid.PICC_IsNewCardPresent())
    return;

  if (!rfid.PICC_ReadCardSerial())
    return;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scanning");
  for (int i = 0; i < rfid.uid.size; i++) {
    lcd.print(".");
    delay(500);
  }

  String cardContent = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    cardContent += String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
    cardContent += String(rfid.uid.uidByte[i], HEX);
  }
  cardContent.toUpperCase();
  Serial.println(cardContent);
  delay(3000);

  String command = Serial.readString();
  handleCommand(command);
}

void handleCommand(String command) {
  if (command[0] == '1' && doorLocked == 0) {
    openDoor();
  } else if (command[0] == '1' && doorLocked == 1) {
    closeDoor();
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Wrong card!");
    buzzerSignal(2);
    alert();
    delay(1500);
    lcd.clear();
  }

  rfid.PICC_HaltA();
}

void buzzerSignal(int type) {
  if (type == 1) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100);
    digitalWrite(BUZZER_PIN, LOW);
  } else if (type == 2) {
    for (int i = 0; i < 3; i++) {
      digitalWrite(BUZZER_PIN, HIGH);
      digitalWrite(RED_LED, HIGH);
      delay(100);
      digitalWrite(BUZZER_PIN, LOW);
      digitalWrite(RED_LED, LOW);
      delay(100);
    }
  }
}

void alert() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100);
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    delay(100);
  }
}

void playWelcomeSound() {
  for (int j = 0; j < 7; j++) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, HIGH);

    tone(BUZZER_PIN, MELODY_NOTES[j]);
    delay(MELODY_DURATIONS[j]);
    noTone(BUZZER_PIN);

    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, LOW);

    delay(50);
  }
}

void openDoor() {
  buzzerSignal(1);
  doorLock.write(UNLOCKED_POSITION);
  digitalWrite(GREEN_LED, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Door is open");
  delay(500);
  doorLocked = 1;
  doorCloseTimer = millis() + DOOR_CLOSE_DELAY; 
}

void closeDoor() {
  buzzerSignal(1);
  doorLock.write(LOCKED_POSITION);
  digitalWrite(RED_LED, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Door is locked");
  delay(3000); 
  lcd.clear();
  doorLocked = 0;
  doorCloseTimer = 0;
}

void updateLCDTimer() {
  if (doorCloseTimer > 0) {
    unsigned long remainingTime = doorCloseTimer - millis();
    int seconds = remainingTime / 1000;
    lcd.setCursor(0, 1); 
    lcd.print("closing in ");
    lcd.print(seconds);
    lcd.print(" s");
  }
}

void turnOffLEDs() {
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
}
