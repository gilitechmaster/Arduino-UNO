#include <CapacitiveSensor.h>
CapacitiveSensor cs_8_9 = CapacitiveSensor(8, 9); //send, receive

void setup() {

  Serial.begin(9600);
}

void loop() {

  CSread();
}

void CSread() {
  unsigned long cs = cs_8_9.capacitiveSensor(250);
  cs_8_9.set_CS_AutocaL_Millis(50);
  cs_8_9.set_CS_Timeout_Millis(50);
  if(cs >= 0){
  Serial.println(cs);

  delay(100);
  }
}

//A0 = 8핀, G = 그라운드, + = 5V

//네오디뮴 자석 접촉시 값 0
//네오디뮴 자석 정성적으로 끌림이 느껴지며 정량으로 약 5cm부터 값 0
//네오디뮴 자석 없을시 값 O.L
