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
  unsigned long cs = cs_7_5.capacitiveSensor(55);
  cs_7_5.set_CS_AutocaL_Millis(50);
  cs_7_5.set_CS_Timeout_Millis(50);
  if(cs > 1){
    Serial.println(cs);
  }
}
