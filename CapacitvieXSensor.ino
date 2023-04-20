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
//자작센서의 구조상 물 + 10M옴 = 2680 ~ 2880으로 센서마다 값이 약간 다르다.

//고은소금 1큰삽(7X7절반) = 190개 당 10mg, 1개당 0.05mg
//설탕 1큰삽(7X7절반) = 183개 당 10mg, 1개당 0.054mg

//10mg 포켓저울로 정량측정시
//7X7절반 큰삽에 고은소금 20mg = 190개, 0.1mg에 1개이다.
//1ml 물에 1큰삽 2큰삽 3큰삽까지 3번 혼합해서 측정해보았으나 값에 변화가 없다.
//전해질, 전류가 흐르는 물질을 좀 더 연구해야 한다.

//1ml 물에 설탕 3큰삽을 혼합해서 측정했으나 값에 변화가 없다.

//우유를 측정할시 물과 동일하였다.
//지방과의 관계를 좀 더 연구해야 한다.

//카놀라유 측정 = O.L
//카놀라유 + 물 = 물의 값으로 측정된다.
//물의 값으로 측정된건 물이 아래로 내려가서 일 수 있다.

//탄산음료 측정시 물에서 -280이다.
//물 = 2860 일 때, 탄산음료 = 2580이다.

//뜨거운 커피 측정시 물에서 -80이다.
//물 = 2860, 뜨거운 커피 = 2780이다.

//커피포트로 끓이고 식은 물은 -50이다.
//물 = 2870, 포트 식은 물 = 2820이다.
//물을 끓이면 구성성분이 파괴됨인지 연구해야 한다.

//물 = 2880, 소주 = 2870

//식용유와 다르게 탄산음료, 커피, 소주는 모두
//인체에 들어가는 용액이기 때문에 값이 물에서 큰 변동이 없을 수 있다.

=========================================================================

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
//박막이므로 휨이 발생할 경우 값이 가변된다.

//온도센서 NTC-10KD-5J
//기본 값 = 0

//Radial인덕터 10mH = 0
//Radial인덕터 1mH = 0

//Ceramic 0.1uF 50V = 0
//Ceramic 0.01uF 50V = 0
//전해콘덴서 E/C 10uF 50V = 0
//전해콘덴서 E/C 1uF 50V = 0
