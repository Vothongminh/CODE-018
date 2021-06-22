//#VTM https://www.youtube.com/c/VTMVlogVoThongMinh
#include <Wire.h>
#include <LiquidCrystal_I2C.h>           //https://drive.google.com/file/d/1lpJyuODmZXfi7wwBM2B79BqBIBmBfanS/view?usp=sharing
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define sensor 8
#define relay 9
//.........................................
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();  
  pinMode(sensor, INPUT);
  pinMode(relay, OUTPUT);
}
//.........................................
void loop() {
  if(digitalRead(sensor) == 0) {
    Serial.println("sensor co tin hieu");
    digitalWrite(relay, HIGH);             //bật relay
    lcd.setCursor(0, 0);
    lcd.print("RUN MOTOR");
  }
  else {
   Serial.println(" KHONG co tin hieu");
   digitalWrite(relay, LOW);
   lcd.setCursor(0,0);
   lcd.print("STOP     "); 
  }
}
