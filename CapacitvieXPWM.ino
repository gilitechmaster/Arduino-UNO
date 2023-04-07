#include <CapacitiveSensor.h>
#include <PWM.h>

int32_t frequency1 = 10; //10헤르츠
CapacitiveSensor cs_12_5 = CapacitiveSensor(12, 5); //send, receive
//PWM이 마이크로 암페어라서 합선될 수 있으므로 핀7과 핀12는 멀리한다.

void setup(){
  //InitTimerSafe();
  //bool success1 = SetPinFrequencySafe(9, frequency1);
  //SetPinFrequencySafe는 주파수 세팅인데 필요한지 모르겠다.
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
  unsigned long cs = cs_12_5.capacitiveSensor(50);
  cs_12_5.set_CS_AutocaL_Millis(50);
  cs_12_5.set_CS_Timeout_Millis(50);
  if(cs > 1){
    Serial.println(cs);
    delay(50);
  }
}
