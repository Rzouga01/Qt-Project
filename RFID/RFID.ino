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

Servo servo;
LiquidCrystal_I2C lcd(0x27, 16, 2);
MFRC522 rfid(SS_PIN, RST_PIN);

byte lock = 0;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  Serial.begin(9600);
  servo.attach(3);
  servo.write(LOCKED_POSITION);
  lcd.init();
  lcd.backlight();
  SPI.begin();
  rfid.PCD_Init();
  playWelcomeSound();
}

void loop() {
  lcd.setCursor(4, 0);
  lcd.print("Welcome!");
  lcd.setCursor(1, 1);
  lcd.print("Put your card");

  if (!rfid.PICC_IsNewCardPresent())
    return;

  if (!rfid.PICC_ReadCardSerial())
    return;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scanning");
 String content= "";
  byte letter;
  for (byte i = 0; i < rfid.uid.size; i++) 
  {
     Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(rfid.uid.uidByte[i], HEX);
     content.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(rfid.uid.uidByte[i], HEX));
  }
  Serial.println();
 delay(3000);

  String command = Serial.readString();
  if (command[0] == '1' && lock == 0) {
    buzzerSignal(1);
    servo.write(UNLOCKED_POSITION);
    digitalWrite(GREEN_LED, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door is open");
    delay(1500);
    lcd.clear();
    digitalWrite(GREEN_LED, LOW);
    lock = 1;
  } else if (command[0] == '1' && lock == 1) {
    buzzerSignal(1);
    servo.write(LOCKED_POSITION);
    digitalWrite(RED_LED, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door is locked");
    delay(1500);
    lcd.clear();
    digitalWrite(RED_LED, LOW);
    lock = 0;
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

  int melody[] = {523, 392, 392, 440, 392, 493, 523};
  int noteDurations[] = {200, 100, 100, 200, 400, 200, 200};

  for (int j = 0; j < 7; j++) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, HIGH);

    tone(BUZZER_PIN, melody[j]);
    delay(noteDurations[j]);
    noTone(BUZZER_PIN);

    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, LOW);

    delay(50);
  }
}
