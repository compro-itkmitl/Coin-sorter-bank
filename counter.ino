#include <COUNTER.h>
int totalAll=0;
int count1All=0;
int count5All=0;
int count10All=0;
COUNTER c1;
COUNTER c2;
COUNTER c3;


void setup() {
  Serial.begin(9600);
  c1.Init(2);
  c2.Init(3);
  c3.Init(4);
}

void loop() {
  // put your main code here, to run repeatedly:
  int num1 = c1.getSensor();
  int num5 = c2.getSensor();
  int num10 = c3.getSensor();
  delayMicroseconds(10);
  if(num1==0){
    count1All += c1.processCount1();
    delay(50);
    Serial.print("Coin 1 = ");
    Serial.println(count1All);
  }
  if(num5==0){
    count5All += c2.processCount5();
    delay(50);
    Serial.print("Coin 5 = ");
    Serial.println(count5All);
  }
  if(num10==0){
    count10All += c3.processCount10();
    totalAll += count10All;
    delay(50);
    Serial.print("Coin 10 = ");
    Serial.println(count10All);
  }
  totalAll = count1All + count5All + count10All;
  Serial.print("Total = ");
  Serial.println(totalAll);

}
