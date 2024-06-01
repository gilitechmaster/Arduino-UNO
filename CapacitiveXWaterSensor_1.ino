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

//10M옴 값 = 3070

//10M옴 + 자작센서 물 적재시 값 = 3010
//10M옴 + 자작센서 물 없을시 값 = O.L
//10M옴 + 자작센서의 구조상 물 + 10M옴 = 2880 ~ 3000으로 센서마다 값이 약간 다르다.

//아래 측정값은 모두 10M옴을 추가한 상태이다.

//고은소금 1큰삽(7X7절반) = 190개 당 30mg, 1개당 0.157mg = 0.00 015g
//설탕 1작은삽(5X5절반) = 120개 당 10mg, 1개당 0.083mg = 0.00 008g
//물방울 액체적재센서 1개, 스포이드 양 = 70mg(포켓저울로 측정함)

//10mg 포켓저울로 정량측정시
//7X7절반 큰삽에 고은소금 30mg = 190개, 0.15mg에 1개이다.
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