#include <COUNTER.h>
//Lcd Library
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
// Set variable for store 1, 5, 10 coin
int totalAll=0;
int count1All=0;
int count5All=0;
int count10All=0;
int sw = 5;

// Initial object for calling Library
COUNTER c1;
COUNTER c2;
COUNTER c3;


void setup() {
  // put your setup code here, to run once:
  // Set switch
  pinMode(sw, INPUT);
  Serial.begin(115200);
  // Set pin sensor from using .Init  
  c1.Init(2);
  c2.Init(3);
  c3.Init(4);
  // Start LCD
  lcd.begin();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  int num1 = c1.getSensor(); // get value from sensor and store in num1 to save 1 coin
  int num5 = c2.getSensor(); // get value from sensor and store in num1 to save 5 coin
  int num10 = c3.getSensor();  // get value from sensor and store in num1 to save 10 coin
  int switch_1 = digitalRead(sw); // get value from switch
  delay(5);
  Serial.println(switch_1);
  // check switch from user
  if(switch_1==1){
    lcd.clear();
    count1All=0;
    count5All=0;
    count10All=0;
    totalAll=0;
    delay(1000);
  }
  // check sensor that 1 coin though the sensor and store in count1All and print it to LCD
  if(num1==0){
    count1All += c1.processCount1();
    delay(10);
    lcd.setCursor(0, 0);
    lcd.print("Count1 = ");
    lcd.print(count1All);
  }
  // check sensor that 5 coin though the sensor and store in count5All and print it to LCD
  if(num5==0){
    count5All += c2.processCount5();
    delay(10);
    lcd.setCursor(0, 1);
    lcd.print("Count5 = ");
    lcd.print(count5All);
  }
  // check sensor that 10 coin though the sensor and store in count10All and print it to LCD
  if(num10==0){
    count10All += c3.processCount10();
    delay(10);
    lcd.setCursor(0, 2);
    lcd.print("Count10 = ");
    lcd.print(count10All);
  }
  // Sum all value from any sensor
  totalAll = count1All + count5All + count10All;
  lcd.setCursor(0, 3);
  lcd.print("Total = ");
  lcd.print(totalAll);
}
