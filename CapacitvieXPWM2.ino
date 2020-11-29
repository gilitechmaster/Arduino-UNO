#include <CapacitiveSensor.h>
#include <PWM.h>

int32_t frequency1 = 10; //10헤르츠
CapacitiveSensor cs_7_5 = CapacitiveSensor(7, 5); //send, receive


void setup(){
  //InitTimerSafe();
  bool success1 = SetPinFrequencySafe(9, frequency1);
  Serial.begin(9600);
}

void loop(){
  pwmWrite(7,1);  
  //1 = 36마이크로암페어출력
  //10 = 104마이크로암페어출력
  //30 = 182마이크로암페어출력
  //150 = 386마이크로암페어출력
  CSread();
}

void CSread(){
  unsigned long cs = cs_7_5.capacitiveSensor(50);
  cs_7_5.set_CS_AutocaL_Millis(50);
  cs_7_5.set_CS_Timeout_Millis(50);
  if(cs > 1){
    Serial.println(cs);
    delay(50);
  }
}
