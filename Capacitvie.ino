#include <CapacitiveSensor.h>
CapacitiveSensor cs_7_5 = CapacitiveSensor(7, 5);

void setup(){
  //InitTimerSafe();
  Serial.begin(9600);
}

void loop(){
  CSread();
}

void CSread(){
  unsigned long cs = cs_7_5.capacitiveSensor(50);
  cs_7_5.set_CS_AutocaL_Millis(50);
  cs_7_5.set_CS_Timeout_Millis(500); // 50 = 1.5만 OL, 500 = 15만 OL
  if(cs > 1){
    Serial.println(cs);
  }
  delay(50);
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
