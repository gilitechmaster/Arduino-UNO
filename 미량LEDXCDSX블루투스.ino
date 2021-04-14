#include <CapacitiveSensor.h>
CapacitiveSensor cs_6_7 = CapacitiveSensor(6, 7);
CapacitiveSensor cs_2_3 = CapacitiveSensor(2, 3);

//6 = send, 7 = receive
//6, 7 = CDS를 장착한다.
//2, 3 = 스위치를 장착한다.

#include <SoftwareSerial.h>
SoftwareSerial bluetooth(9, 10);
//9 = RX, 10 = TX
//HC06으로 값 모니터링

int outled = A0;
int inled = 11;
int i;

void setup(){
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(outled, OUTPUT);
  pinMode(inled, OUTPUT);
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop(){
  digitalWrite(LED_BUILTIN, LOW);
  CSread();
  
}

void CSread(){
  unsigned long cs = cs_6_7.capacitiveSensor(50);
  cs_6_7.set_CS_AutocaL_Millis(50);
  cs_6_7.set_CS_Timeout_Millis(50);

  unsigned long cs1 = cs_2_3.capacitiveSensor(50);
  cs_2_3.set_CS_AutocaL_Millis(50);
  cs_2_3.set_CS_Timeout_Millis(50);
  
  bluetooth.print("CDS = ");
  bluetooth.println(cs);
  //bluetooth.print("터치 = ");
  //bluetooth.println(cs1);

  Serial.print("CDS = ");
  Serial.println(cs);
  //Serial.print("터치 = ");
  //Serial.println(cs1);

  
  if(cs > 500){
    digitalWrite(outled, LOW);
      
    }
     
      if(cs < 1){
      digitalWrite(outled, HIGH);
    }

    //파동이 간섭되서 광-저항-전류가 변한다면
    //1000이상을 기록하면서 LED꺼짐


      if(cs1 > 14000){
        analogWrite(inled, 1);
        //LED를 미량만 방출한다.
      
    }
    if(cs1 < 14000){
        analogWrite(inled, 0);
        //터치하면 LED 꺼짐
    }
  
    delay(5);
    //100으로 두면 0인데
    //10이하 설정시 읽기가 0.01초로 정밀해져서
    //0~20까지 파동이 기록되기 시작한다.


    
}
