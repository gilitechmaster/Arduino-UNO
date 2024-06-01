#include <CapacitiveSensor.h>
CapacitiveSensor cs_2_3 = CapacitiveSensor(2, 3);

#define inLED A0 //수광부
#define outLED 11 //발광부

void setup(){
  pinMode(outLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int r = analogRead(inLED);
  Serial.println(r);
  //digitalWrite(outLED, LOW);
  delay(50);
}

void CSread(){
  unsigned long cs1 = cs_2_3.capacitiveSensor(50);
  cs_2_3.set_CS_AutocaL_Millis(50);
  cs_2_3.set_CS_Timeout_Millis(50);
        if(cs1 > 14000){
        analogWrite(outLED, 1);
        //LED를 미량만 방출한다.
      
    }
    if(cs1 < 14000){
        analogWrite(outLED, 0);
        //터치하면 LED 꺼짐
    }
}

//터치할 때 9~120
//터치 안할 때 0~130
