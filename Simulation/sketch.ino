
#include <LiquidCrystal.h>

// LCD connections: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

// Pushbutton connection
const int buttonPin = 2;

void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);
  pinMode(buttonPin, INPUT_PULLUP);

  lcd.setCursor(0, 0);
  lcd.print("SMART HEALTH");
  lcd.setCursor(0, 1);
  lcd.print("MONITORING");
  
  Serial.println("Smart Wrist Device Started");
  delay(2000);
  lcd.clear();
}

void loop() {

  // Button pressed means finger is detected
  bool fingerDetected = (digitalRead(buttonPin) == LOW);

  if (fingerDetected) {

    // Simulated sensor readings
    int heartRate = 72;
    int spo2 = 98;
    float temperature = 36.5;

    lcd.setCursor(0, 0);
    lcd.print("HR:72  SpO2:98%");

    lcd.setCursor(0, 1);
    lcd.print("Temp:36.5 C     ");

    Serial.println("Finger Detected");
    Serial.println("Heart Rate: 72 BPM");
    Serial.println("SpO2: 98% (simulated)");
    Serial.println("Temperature: 36.5 C");

  } else {

    lcd.setCursor(0, 0);
    lcd.print("No finger?      ");

    lcd.setCursor(0, 1);
    lcd.print("Place finger    ");

    Serial.println("No finger detected");
  }

  delay(500);
}
