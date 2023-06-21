#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

String st = "BatMan Begins";
void setup()
{
  Serial.begin(9600);
  lcd.init(); // initialize the lcd
  lcd.backlight();
} 

void loop()
{
  if(Serial.available() != 0)
  st = Serial.readString();
  st.trim();
  lcd.clear();
  lcd.setCursor(0,0);

    String st1 = st;
    lcd.print(st1);
    st1.remove(0,16);
    lcd.setCursor(0,1);
    lcd.print(st1);    
    
  delay(2000);
}
