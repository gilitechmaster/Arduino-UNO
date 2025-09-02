// 2와 HW 구조가 달라졌다.
// Top이 22 x 22 mm이며 정육면체 스타일이다.

#include <CapacitiveSensor.h>
CapacitiveSensor cs_7_6 = CapacitiveSensor(7, 6);
CapacitiveSensor cs_2_3 = CapacitiveSensor(2, 3);

int inled = 11;

void setup(){
  //InitTimerSafe();
  Serial.begin(9600);
  pinMode(inled, OUTPUT);
}

void loop(){
  CSread();
}

void CSread(){
  
  unsigned long cs = cs_2_3.capacitiveSensor(50);
  cs_2_3.set_CS_AutocaL_Millis(50);
  cs_2_3.set_CS_Timeout_Millis(50); // 50 = 1.5만 OL, 500 = 15만 OL

  unsigned long cs1 = cs_7_6.capacitiveSensor(50);
  cs_7_6.set_CS_AutocaL_Millis(50);
  cs_7_6.set_CS_Timeout_Millis(50);
  
  if(cs1 < 10){
    //Serial.println(cs1);
    analogWrite(inled, 0);
  }
  if(cs1 > 10){
    //Serial.println(cs1);
    analogWrite(inled, 1);
  }
  if (cs > 1) {
    //analogWrite(inled, 1);
    Serial.println(cs);
  }
  if (cs = 0) {
    //analogWrite(inled, 0);
    Serial.println(cs);
  }
    delay(100);
}

// 42억 = 오버로드 (OL)
// 15000 = 40M옴
// 11000 = 30M옴
// 6400 = 20M옴
// 3300 = 10M옴
// 700 = 2M옴
// 350 = 1M옴
// 100 = 300k옴
// 0 = 100k옴
// 0 = 무저항
