#include<LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define sensw 10
#define LED 13
#define check 8
#define s1 A0
#define s2 A1
#define s3 A2

float v1;
float v2;
float v3;
float t1;
float t2;
float t3;

void setup() {
  Serial.begin(9600);
  pinMode( sensw, OUTPUT);
  pinMode( LED, OUTPUT);
  pinMode( check, INPUT);
  pinMode( s1, INPUT);
  pinMode( s2, INPUT);
  pinMode( s3, INPUT);

}

void loop() {

  digitalWrite( LED, HIGH);
  digitalRead(check);
  if(check>0)
  {
    digitalWrite(sensw, HIGH);
    
    v1=analogRead(s1);
    v2=analogRead(s2);
    v3=analogRead(s3);

    t1=(v1*500)/1023;
    t2=(v2*500)/1023;
    t3=(v3*500)/1023;

    lcd.begin(20,4);
    lcd.print("Sensor1:");
    //lcd.setCursor(1,1);
    lcd.print(t1);
    lcd.setCursor(0,1);
    lcd.print("Sensor2:");
    lcd.print(t2);
    lcd.setCursor(0,2);
    lcd.print("Sensor3:");
    lcd.print(t3);
    delay(200);
    Serial.println(t1);
    Serial.println(t2);
    Serial.println(t3);
    
  }

  else
  {
    lcd.begin(20,4);
    lcd.print("LED not working");
  }

}
