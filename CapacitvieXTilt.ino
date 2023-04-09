#include <CapacitiveSensor.h>
CapacitiveSensor cs_8_9 = CapacitiveSensor(8, 9); //send, receive

void setup() {

  Serial.begin(9600);
}

void loop() {

  CSread();
}

void CSread() {
  unsigned long cs = cs_8_9.capacitiveSensor(50);
  cs_8_9.set_CS_AutocaL_Millis(50);
  cs_8_9.set_CS_Timeout_Millis(50);
  //if(cs > 1){
  Serial.println(cs);

  delay(100);
}
}

//현재 코드는 CapacitiveXCDS와 동일하게 쓰인다.
//물리적 환경이 CDS=에너지, 전자제어가 아닌
//사람의 외력에 따름이므로 delay만 10에서 100으로 코드하였다.

//기울기 센서는 AETHDX를 사용한다.
//웹에는 AETHDX는 진동센서로 나오지만 기울기센서이다.
//기본이 0이며, 진동 혹은 기울임 발생시 값이 올라간다.

//센서를 90도 이상 뒤집으면 오버로드가 발생한다.
//혹은 아두이노 보드를 때리면 값이 올라간다.
