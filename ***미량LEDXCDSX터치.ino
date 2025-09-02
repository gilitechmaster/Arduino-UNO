#include <CapacitiveSensor.h>
CapacitiveSensor cs_7_6 = CapacitiveSensor(7, 6);
CapacitiveSensor cs_3_2 = CapacitiveSensor(3, 2);

int inled = 11;

void setup(){
  Serial.begin(9600);
  pinMode(inled, OUTPUT);
}

void loop(){
  CSread();
  
}

void CSread(){
  unsigned long cs1 = cs_7_6.capacitiveSensor(50);
  cs_7_6.set_CS_AutocaL_Millis(50);
  cs_7_6.set_CS_Timeout_Millis(500); // 오버로드에 도달하는 최대값이 증가한다.

  unsigned long cs = cs_3_2.capacitiveSensor(50);
  cs_3_2.set_CS_AutocaL_Millis(50);
  cs_3_2.set_CS_Timeout_Millis(50);

  if(cs < 14000){
    analogWrite(inled, 1);
  }
  if(cs > 14000){
    analogWrite(inled, 0);
  }

  Serial.println(cs1);
  delay(70);
}
