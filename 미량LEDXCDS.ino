#include <CapacitiveSensor.h>
CapacitiveSensor cs_2_3 = CapacitiveSensor(2, 3);

//2 = send, 3 = receive
//2, 3 = CDS를 장착한다.

int outled = A0;
int inled = 11;

void setup(){
  pinMode(outled, OUTPUT);
  pinMode(inled, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  analogWrite(inled, 5);
  //LED를 미량만 방출한다.
  //Capacitive에 2000이 나오므로
  //2500~1500 사이만 LED on
   CSread();
}

void CSread(){
  unsigned long cs = cs_2_3.capacitiveSensor(50);
  cs_2_3.set_CS_AutocaL_Millis(50);
  cs_2_3.set_CS_Timeout_Millis(50);

  Serial.println(cs);

  //if(cs > 1 && cs < 2000){
    //digitalWrite(outled, HIGH);
  //}
    if(cs > 1){
      digitalWrite(outled, LOW);
    }
     
    delay(100);
  
  digitalWrite(outled, HIGH);
}
