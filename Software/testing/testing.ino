#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Initializes LCD Display
LiquidCrystal_I2C lcd(0x27, 16, 2);

int userInput = 0;  //User selected water level

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);

}

void loop() {
  userInput=analogRead(A1);
  lcd.print(userInput);
  delay(500);
  lcd.clear();
}
