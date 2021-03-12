#include <CapacitiveSensor.h>
CapacitiveSensor cs_2_3 = CapacitiveSensor(2, 3);

//2 = send, 3 = receive
//2, 3 = CDS를 장착한다.

int outled = A0;
int inled = 11;

void setup(){
  pinMode(outled, OUTPUT);
  pinMode(inled, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  analogWrite(inled, 1);
  //LED를 미량만 방출한다.
   CSread();
}

void CSread(){
  unsigned long cs = cs_2_3.capacitiveSensor(50);
  cs_2_3.set_CS_AutocaL_Millis(50);
  cs_2_3.set_CS_Timeout_Millis(50);
  
  if(cs > 1 && cs < 100){
    Serial.print("수신전류 = 15㎂ ~ 270㎂, 작동저항 = 300k옴 이하, Capacitive = ");
    Serial.println(cs);
    digitalWrite(outled, HIGH);
  }
  if(cs > 100 && cs < 350){
    Serial.print("수신전류 = 1.5㎂ ~ 15㎂, 작동저항 = 300k ~ 1M옴, Capacitive = ");
    Serial.println(cs);
    digitalWrite(outled, HIGH);
  }
  if(cs > 350 && cs < 3300){
    Serial.print("수신전류 = 150㎁ ~ 1.5㎂, 작동저항 = 1M옴 ~ 10M옴, Capacitive = ");
    Serial.println(cs);
    digitalWrite(outled, HIGH);
  }
  if(cs > 3300 && cs < 6400){
    Serial.print("수신전류 = 150㎁ 이하, 작동저항 = 10M옴 ~ 20M옴, Capacitive = ");
    Serial.println(cs);
    digitalWrite(outled, HIGH);
  }
  if(cs > 6400 && cs < 11000){
    Serial.print("수신전류 = 150㎁ 이하, 작동저항 = 20M옴 ~ 30M옴, Capacitive = ");
    Serial.println(cs);
    digitalWrite(outled, HIGH);
  }
  if(cs > 11000 && cs < 15000){
    Serial.print("수신전류 = 150㎁ 이하, 작동저항 = 30M옴 ~ 40M옴, Capacitive = ");
    Serial.println(cs);
    digitalWrite(outled, HIGH);
  }
  if(cs > 15000){
    Serial.print("수신전류 = 오버로드, 작동저항 = 50M옴 이상, Capacitive = ");
    Serial.println(cs);
    digitalWrite(outled, HIGH);
  }
    
    delay(100);
  
  digitalWrite(outled, LOW);
}
