#include <COUNTER.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
int totalAll=0;
int count1All=0;
int count5All=0;
int count10All=0;
int sw = 5;
COUNTER c1;
COUNTER c2;
COUNTER c3;


void setup() {
  // put your setup code here, to run once:
  pinMode(sw, INPUT);
  Serial.begin(115200);
  c1.Init(2);
  c2.Init(3);
  c3.Init(4);
  lcd.begin();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  int num1 = c1.getSensor();
  int num5 = c2.getSensor();
  int num10 = c3.getSensor();
  int switch_1 = digitalRead(sw);
  delay(5);
  Serial.println(switch_1);
  if(switch_1==1){
    
    lcd.clear();
    count1All=0;
    count5All=0;
    count10All=0;
    totalAll=0;
    delay(1000);
  }
  if(num1==0){
    count1All += c1.processCount1();
    delay(10);
    lcd.setCursor(0, 0);
    lcd.print("Count1 = ");
    lcd.print(count1All);
  }
  if(num5==0){
    count5All += c2.processCount5();
    delay(10);
    lcd.setCursor(0, 1);
    lcd.print("Count5 = ");
    lcd.print(count5All);
  }
  if(num10==0){
    count10All += c3.processCount10();
    delay(10);
    lcd.setCursor(0, 2);
    lcd.print("Count10 = ");
    lcd.print(count10All);
  }
  totalAll = count1All + count5All + count10All;
  lcd.setCursor(0, 3);
  lcd.print("Total = ");
  lcd.print(totalAll);
}
