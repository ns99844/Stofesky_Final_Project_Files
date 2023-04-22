#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Initializes LCD Display
LiquidCrystal_I2C lcd(0x27, 16, 2);

int userInput = 0;  //User selected water level
int correctLevel = 0; //Indicated if water level is reached

//Setup
void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, INPUT);

  //Asks user which water level they want
  lcd.print("Select Water");
  lcd.setCursor(0,1);
  lcd.print("Level Input");
  
}

//Loop
void loop() {
  //Checks if user has entered an input
  userInput=analogRead(A0);

  if(userInput>50 && digitalRead(9)==HIGH)
  {
    lcd.clear();
    
    //User selects 10mL
    if(userInput<=200) 
    {
      //prints the user selected input water level
      lcd.print("10mL");  

      //For the mux
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
    }

    //User selects 20mL
    else if(userInput>200 && userInput<=300) //User selects 10mL
    {
      //prints the user selected input water level
      lcd.print("20mL");  

      //For the mux
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
    }

    //User selects 30mL
    else if(userInput>300 && userInput<=450)
    {
      //prints the user selected input water level
      lcd.print("30mL");  

      //For the mux
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
    }

    //User selects 40mL
    else if(userInput>450 && userInput<=575) 
    {
      //prints the user selected input water level
      lcd.print("40mL");  

      //For the mux
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
    }

    //User selects 50mL
    else if(userInput>575 && userInput<=700)
    {
      //prints the user selected input water level
      lcd.print("50mL");  

      //For the mux
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
    }

    //User selects 60mL
    else if(userInput>700 && userInput<=800)
    {
      //prints the user selected input water level
      lcd.print("60mL");  

      //For the mux
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
    }

    //User selects 70mL
    else if(userInput>800 && userInput<=975)
    {
      //prints the user selected input water level
      lcd.print("70mL");  

      //For the mux
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
    }

    //User selects 70mL
    else if(userInput>975)
    {
      //prints the user selected input water level
      lcd.print("80mL");  

      //For the mux
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
    }

    //Error Check
    else
    {
      lcd.print("Did Not Work");     
    }

    delay(2000);
    lcd.clear();

    //Turns on water pump
    digitalWrite(3, HIGH);

    //Turns on water pump as long as water level isn't reached
    lcd.print("Filling");

    while(correctLevel<300){
      correctLevel=analogRead(A1);
    }

    //Turns off water pump and mux pins when water level is reached
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);

    //Lets the user know that the water level has been reached
    lcd.clear();
    lcd.print("Water Level");
    lcd.setCursor(0,1);
    lcd.print("Reached");
    delay(5000);
    lcd.clear();
  }

}
