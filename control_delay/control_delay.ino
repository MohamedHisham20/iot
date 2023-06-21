#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

String st = "BatMan Begins"; //initialize lcd word
int del = 100; //initialize delay time
void setup()
{
  Serial.begin(9600);
  lcd.init(); // initialize the lcd
  lcd.backlight();
  
} 

void loop()
{
  if(Serial.available() != 0){
  st = Serial.readString(); //read serial monitor input
  String del_time = st.substring(0,3); //get first 3 chars (delay)
  del = del_time.toInt(); // convert to int
  st.remove(0,3); // remove them to be string
  }
//  Serial.println(del);
//  Serial.println(st);
  wrap(st,del); // print wraped sentences
}

void printit(String st,int del) // print char by char
{
  int stop_at; //variable to stop printing at
  if(st.length() > 16)
    stop_at = 16;
  else stop_at = st.length();
    
  for(int i = 0 ; i<stop_at; i++)
  {
  lcd.print(st[i]); // print word by word
  delay(del);
}
}

void wrap(String st,int del)
{
  st.trim(); // remove weird char at the end of word
  lcd.clear();
  lcd.setCursor(0,0);
  String st1 = st; // copy the string to keep the original
  int f_line = 0; //is first line
  do
  {
//    Serial.println(st1);
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
