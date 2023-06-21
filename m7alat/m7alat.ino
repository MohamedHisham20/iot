#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

String st = "BatMan Begins";
int del = 100;
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
  wrap(st,del);
}

void printit(String st,int del)
{
  int stop_at;
  if(st.length() > 16)
    stop_at = 16;
  else stop_at = st.length();
    
  for(int i = 0 ; i<stop_at; i++)
  {
  lcd.print(st[i]);
  delay(del);
}
}

void wrap(String st,int del)
{
  st.trim();
  lcd.clear();
  lcd.setCursor(0,0);
  String st1 = st;
  int f_line = 0;
  do
  {
    Serial.println(st1);
    if(f_line == 0)
    {
    lcd.clear();
    }
    
    lcd.setCursor(0,f_line);
    printit(st1,del);
    st1.remove(0,16);
    if(f_line == 0)
    f_line = 1;
    else f_line = 0;
    
  }while(st1.length() > 0);

  
}

//bool cur = false;
//while (strlen > 16)
//setcursor(0,cur)
//str.print ()
//remove 16
//cur =!cur;
//if(cur false)
//clear

//
// printit(st1);
//  st1.remove(0,16);
//  lcd.setCursor(0,1);
//  printit(st1);    
//    
//  delay(2000);
