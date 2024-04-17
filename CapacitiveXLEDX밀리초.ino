#include <CapacitiveSensor.h>
CapacitiveSensor cs_6_7 = CapacitiveSensor(6, 7); //send, receive
CapacitiveSensor cs_2_3 = CapacitiveSensor(2, 3);

int inled = 11;
long start;

void setup() {

  pinMode(inled, OUTPUT); //미시광파 발생 실험용 LED
  Serial.begin(9600);
}

void loop() {
  CSread();
  start = millis();
}
void CSread() {
  unsigned long cs = cs_6_7.capacitiveSensor(50);
  cs_6_7.set_CS_AutocaL_Millis(50);
  cs_6_7.set_CS_Timeout_Millis(500);

  unsigned long cs1 = cs_2_3.capacitiveSensor(50);
  cs_2_3.set_CS_AutocaL_Millis(50);
  cs_2_3.set_CS_Timeout_Millis(50);

  if(cs >= 0){
  Serial.print(millis() - start);
  Serial.print("ms");
  Serial.print("\t");
  Serial.print("CDS = ");
  Serial.println(cs);

  if (cs1 > 14000) {
    analogWrite(inled, 1);
    //analogWrite(inled, 10);
    //analogWrite(inled, 100);
    //LED를 미량만 방출한다.

  }
  if (cs1 < 14000) {
    analogWrite(inled, 0);
    //터치하면 LED 꺼짐
  }

  //delay(100);
  delay(1);
  }
}

