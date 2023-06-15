#include <CapacitiveSensor.h>
CapacitiveSensor cs_7_5 = CapacitiveSensor(7, 5);

//7 = send, 5 = receive
//7, 5 = CDS를 장착한다.

int led = A0;


void setup(){
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop(){
   CSread();
}

void CSread(){
  unsigned long cs = cs_7_5.capacitiveSensor(50);
  cs_7_5.set_CS_AutocaL_Millis(50);
  cs_7_5.set_CS_Timeout_Millis(50);
  
  if(cs > 1 && cs < 100){
    Serial.print("수신전류 = 15㎂ ~ 270㎂, 작동저항 = 300k옴 이하, Capacitive = ");
    Serial.println(cs);
    digitalWrite(led, HIGH);
  }
  if(cs > 100 && cs < 350){
    Serial.print("수신전류 = 1.5㎂ ~ 15㎂, 작동저항 = 300k ~ 1M옴, Capacitive = ");
    Serial.println(cs);
    digitalWrite(led, HIGH);
  }
  if(cs > 350 && cs < 3300){
    Serial.print("수신전류 = 150㎁ ~ 1.5㎂, 작동저항 = 1M옴 ~ 10M옴, Capacitive = ");
    Serial.println(cs);
    digitalWrite(led, HIGH);
  }
  if(cs > 3300 && cs < 6400){
    Serial.print("수신전류 = 150㎁ 이하, 작동저항 = 10M옴 ~ 20M옴, Capacitive = ");
    Serial.println(cs);
    digitalWrite(led, HIGH);
  }
  if(cs > 6400 && cs < 11000){
    Serial.print("수신전류 = 150㎁ 이하, 작동저항 = 20M옴 ~ 30M옴, Capacitive = ");
    Serial.println(cs);
    digitalWrite(led, HIGH);
  }
  if(cs > 11000 && cs < 15000){
    Serial.print("수신전류 = 150㎁ 이하, 작동저항 = 30M옴 ~ 40M옴, Capacitive = ");
    Serial.println(cs);
    digitalWrite(led, HIGH);
  }
  if(cs > 15000){
    Serial.print("수신전류 = 오버로드, 작동저항 = 50M옴 이상, Capacitive = ");
    Serial.println(cs);
    digitalWrite(led, HIGH);
  }
    
    delay(100);
  
  digitalWrite(led, LOW);
}


//탄소피막저항과 멀티미터로
//측정하였으므로 아래 값은 정확하다.

// 42억 = 오버로드 (OL)
// 15000 = 40M옴
// 11000 = 30M옴
// 6400 = 20M옴
// 3300 = 10M옴
// 350 = 1M옴
// 100 = 300k옴
// 0 = 100k옴
// 0 = 무저항

//물리에너지변화량 = 밝았다가 어두움
//반응이 있을시 = 물리에너지 변화량
//LED 켜짐 = 반응이 있을시
