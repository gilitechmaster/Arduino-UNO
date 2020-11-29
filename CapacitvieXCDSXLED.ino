#include <CapacitiveSensor.h>
CapacitiveSensor cs_7_5 = CapacitiveSensor(7, 5); //send, receive
int led = A0;


void setup(){
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop(){
   CSread();
}

void CSread(){
  unsigned long cs = cs_7_5.capacitiveSensor(50);
  cs_7_5.set_CS_AutocaL_Millis(50);
  cs_7_5.set_CS_Timeout_Millis(50);
  if(cs > 1){
    Serial.println(cs);
    digitalWrite(led, HIGH);
    
    delay(100);
  }
  digitalWrite(led, LOW);
}


//저항이 증가하면 값이 증가한다.
//저항이 높아지면 LED는 켜진다
//저항이 낮아지면 LED는 꺼진다

//저항기


//분해능 50

//10M옴
//7 터치 3000
//5 터치 OL

//10k옴
//7 터치 0
//5 터치 0

//CDS사용

//분해능 10
//밝음 = 0
//어두움 = 70

//분해능 50
//밝음 = 0
//어두움 = 380

//분해능 250
//밝음 = 0
//어두움 = 1800

//물리에너지변화량 = 밝았다가 어두움
//반응이 있을시 = 물리에너지 변화량
//LED 켜짐 = 반응이 있을시
