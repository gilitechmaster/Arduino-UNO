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

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(outled, OUTPUT);  //육안으로 정성확인할 외부 LED
  pinMode(inled, OUTPUT); //미시광파 발생 실험용 LED
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW); //아두이노 보드 LED OFF
  CSread();

}

void CSread() {

  long start = millis(); // 반응속도 체크

  unsigned long cs = cs_6_7.capacitiveSensor(50);  //분해능
  cs_6_7.set_CS_AutocaL_Millis(50); //자동으로 보정할 시간
  cs_6_7.set_CS_Timeout_Millis(500); // 반응속도 지연시 OL 설정
                                     // 500은 값 15만 부터 OL이다.
                                     // 42억 = 0L이다.

  unsigned long cs1 = cs_2_3.capacitiveSensor(50);
  cs_2_3.set_CS_AutocaL_Millis(50);
  cs_2_3.set_CS_Timeout_Millis(50); // 50은 값 1.5만부터 OL이다.

  bluetooth.print(millis() - start);
  bluetooth.print("ms");
  bluetooth.print("\t");
  bluetooth.print("CDS = ");
  bluetooth.println(cs);
  //bluetooth.print("터치 = ");
  //bluetooth.println(cs1);


  Serial.print(millis() - start);
  Serial.print("ms");
  Serial.print("\t");
  Serial.print("CDS = ");
  Serial.println(cs);
  //Serial.print("터치 = ");
  //Serial.println(cs1);


  if (cs > 100) {
    digitalWrite(outled, LOW);

  }

  if (cs < 100) {
    digitalWrite(outled, HIGH);
  }

  if (cs1 > 14000) {
    analogWrite(inled, 1);
    //LED를 미량만 방출한다.

  }
  if (cs1 < 14000) {
    analogWrite(inled, 0);
    //터치하면 LED 꺼짐
  }

  delay(1);
  //20ms 단위로 기록한다.
  //delayMicroseconds(10);
  //마이크로초 값 수집은 실패

}

  //값 380 = 10k옴
  //4500 = 10M옴
  //9800 = 20M옴
  //15000 = 30M옴
  //20000 = 40M옴
  //30000 = 50M옴
  //40000 = 60M옴
  //58000 = 70M옴
  //78000 = 80M옴
  //100000 = 90M옴
  //130000 = 100M옴
