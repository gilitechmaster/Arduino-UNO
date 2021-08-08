//거시공간 어둠량 수집장치

#include <CapacitiveSensor.h>
CapacitiveSensor cs_6_7 = CapacitiveSensor(6, 7); //CDS
CapacitiveSensor cs_1_2 = CapacitiveSensor(1, 2); //Capa Switch
//CapacitiveSensor cs_1_3 = CapacitiveSensor(1, 3); //Capa Switch


int outled = A0;
int red = 9;
int green = 10;
int blue = 11;

void setup(){
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(outled, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  Serial.begin(9600);
}

void loop(){
   digitalWrite(LED_BUILTIN, LOW);
   CSread();
}

void CSread(){
  unsigned long cs = cs_6_7.capacitiveSensor(50);
  cs_6_7.set_CS_AutocaL_Millis(50);
  cs_6_7.set_CS_Timeout_Millis(500);

  unsigned long cs1 = cs_1_2.capacitiveSensor(50);
  cs_1_2.set_CS_AutocaL_Millis(50);
  cs_1_2.set_CS_Timeout_Millis(50);

  //unsigned long cs2 = cs_1_3.capacitiveSensor(50);
  //cs_1_3.set_CS_AutocaL_Millis(50);
  //cs_1_3.set_CS_Timeout_Millis(50);


  long start = millis(); // 반응속도 체크

    Serial.print(millis() - start);
    Serial.print("ms");
    Serial.print("\t");
    Serial.print("CDS = ");

    if (cs > 100) {
    digitalWrite(outled, LOW);
    }

    if (cs < 100) {
    digitalWrite(outled, HIGH);
    }

    if (cs1 > 14000) {
    analogWrite(blue, 1);
  }
  if (cs1 < 14000) {
    analogWrite(blue, 0);
    //터치하면 LED 꺼짐
  }
    
  //if(cs > 1){
    Serial.println(cs);
    Serial.println(cs1);
    //Serial.println(cs2);
    
    
    delay(5);
  //}
}
