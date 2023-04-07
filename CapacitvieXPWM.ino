#include <CapacitiveSensor.h>
#include <PWM.h>

int32_t frequency1 = 10; //10헤르츠
CapacitiveSensor cs_6_4 = CapacitiveSensor(6, 4); //send, receive

void setup(){
  //InitTimerSafe();
  //bool success1 = SetPinFrequencySafe(9, frequency1);
  //SetPinFrequencySafe는 주파수 세팅인데 필요한지 모르겠다.
  Serial.begin(9600);
}

void loop(){
  pwmWrite(6,150);  
  //1 = 36마이크로암페어출력
  //10 = 104마이크로암페어출력
  //30 = 182마이크로암페어출력
  //150 = 386마이크로암페어출력

  //1M옴을 사용할시 Capacitive 값
  //pwmwrite 1 = val 0
  //pwmwrite 10 = val 0
  //pwmwrite 150 = val 0

  //10M옴은 저항을 손으로 터치하면 값이 0에서 아래와 같아진다.
  //10M옴을 사용할시 Capacitive 값
  //pwmwrite 1 = val 0
  //pwmwrite 10 = val 3400
  //pwmwrite 100 = val 3400
  //pwmwrite 150 = val 350
  
  CSread();
}

void CSread(){
  unsigned long cs = cs_6_4.capacitiveSensor(50);
  cs_6_4.set_CS_AutocaL_Millis(50);
  cs_6_4.set_CS_Timeout_Millis(50);
  if(cs >= 0){
    Serial.println(cs);
    delay(50);
  }
}
