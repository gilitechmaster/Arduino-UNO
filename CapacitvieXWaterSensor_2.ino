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
  if(cs >= 0){
  Serial.println(cs);

  delay(100);
  }
}
