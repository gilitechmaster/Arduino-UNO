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

//자작센서 물 적재시 값 = 0
//자작센서 물 없을시 값 = O.L
//자작센서 물 + 10M옴 = 300

//S, A0 = 8핀
//gnd, G, - = 9핀
//vcc, + = 5V
//센서를 사용함에 따라 센서반응시 저항이 증가함을 알 수 있다.

//자석센서
//네오디뮴 자석 접촉시 = 0
//네오디뮴 자석 정성적으로 끌림이 느껴지며 정량으로 약 5cm부터 값 0
//네오디뮴 자석 없을시 = O.L

//수위센서 물 접촉 = O.L
//수위센서 물 비접촉 = 0
//Capacitive보다 아날로그(A0) 코드와 핀을 사용할시 더욱 미세하게 측정된다.

//기울기센서 AETHDX를 사용
//기본 값 = 0
//90도 회전시 값 = O.L

//압력센서 FSR 402
//기본 값 = O.L
//검지손가락으로 잡을시 = 0

//온도센서 NTC-10KD-5J
//기본 값 = 0

//Radial인덕터 10mH = 0
//Radial인덕터 1mH = 0

//Ceramic 0.1uF 50V = 0
//Ceramic 0.01uF 50V = 0
//전해콘덴서 E/C 10uF 50V = 0
//전해콘덴서 E/C 1uF 50V = 0
