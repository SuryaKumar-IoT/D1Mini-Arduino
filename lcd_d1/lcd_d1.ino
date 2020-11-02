#include <LiquidCrystal.h>

LiquidCrystal lcd(D8,D7,D6,D5,D4,D1);//d1-d6
void setup() 
{
  lcd.begin(20,4);
  delay(200);
  lcd.print("HELLO");
  
}

void loop()
{
  lcd.print("HELLO Surya...");
  delay(1000);
  lcd.clear();
  
}
