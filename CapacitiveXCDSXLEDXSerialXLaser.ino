#include <CapacitiveSensor.h>
CapacitiveSensor cs_2_3 = CapacitiveSensor(2, 3);

//2 = send, 3 = receive
//2, 3 = CDS를 장착한다.

int outled = A0;
int inled = 11;
int i;

void setup(){
  pinMode(outled, OUTPUT);
  pinMode(inled, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  CSread();
   
  analogWrite(inled, 1);
  //LED를 미량만 방출한다.
  //Capacitive에 2000이 나오므로
  //2500~1500 사이만 LED on
  
  //for(i=0; i<90; i++){
    //analogWrite(inled, i);
    //delay(10);

    //LED에 파동을 구현한다.
    //최소 0 ~ 최대 90 이다.
    //0.01초에 1씩 증가, 1초 1주기
  //}
}

void CSread(){
  unsigned long cs = cs_2_3.capacitiveSensor(50);
  cs_2_3.set_CS_AutocaL_Millis(50);
  cs_2_3.set_CS_Timeout_Millis(50);

    //if(cs > 1 && cs < 2000){
    //digitalWrite(outled, HIGH);
  //}

  
  if(cs > 500){
    digitalWrite(outled, LOW);
      
    }
     
      if(cs < 1){
      digitalWrite(outled, HIGH);
    }

    //파동이 간섭되서 광-저항-전류가 변한다면
    //1000이상을 기록하면서 LED꺼짐
  

  Serial.println(cs);

  
    delay(10);
    //100으로 두면 0인데
    //10으로 두면 읽기가 0.01초로 정밀해져서
    //0~20까지 파동이 기록되기 시작한다.

    
}
