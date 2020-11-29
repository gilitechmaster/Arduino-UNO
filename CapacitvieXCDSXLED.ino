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


//CDS사용
//CDS조도센서는 어두울 때 150k옴 밝을 때 70k옴이다.


//저항이 증가하면 값이 증가한다.
//저항이 높아지면 LED는 켜진다
//저항이 낮아지면 LED는 꺼진다

//CDS는 가변저항이므로
//Capacitive 라이브러리가
//50~150k옴 사이에서 동작함을
//이해할 수 있다.

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
