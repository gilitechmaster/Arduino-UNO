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

//소금양이 증가할 수록 전류가 높게 활성됨을 조사하여 추가실험하였다.
//전기전도율은 총 수중염류농도와 비례한다.
//이온이 많으면 전기전도도가 증가하고 총 수중염류농도도 증가한다.
//온도가 높은 물은 전기전도율이 증가하게 된다.
  
//소금 1작은삽 = 10mg
//소금 1개 = 0.15mg
//액체적재센서 물 = 70mg
//농도 = 소금/(물+소금)*100

//실험 1.
//물 + 10M옴 = 3100
//물 + 10M옴 + 고은소금 1작은삽 = 2920

//실험 2.
//물 + 10M옴 = 2780
//물 + 10M옴 + 고은소금 1작은삽 = 2630
//물 + 10M옴 + 고은소금 2작은삽 = 2630
//물의 양에 비례해 2작은삽 소금이 제대로 모두 녹았는지?
  
//실험 3.
//물 70mg + 소금 0mg(0개) = 2199(값 변위 0) = 농도 0%
//물 70mg + 소금 1.5mg(10개) = 2100(값 변위 -100) = 농도 2.0%
//물 70mg + 소금 3mg(20개) = 2090(값 변위 -20) = 농도 4.1% 

//실험 4.
//물 70mg + 0mg(0개) = 2100(값 변위 0) = 농도 0%
//물 70mg + 2.25mg(15개) = 2090(값 변위 -10) = 농도 3.1%
//물 70mg + 4.5mg(30개) = 2060(값 변위 -30) = 농도 6.0%
  
//실험 5.
//물 610mg + 10M옴 + 고은소금 0mg = 3130
//물 610mg + 10M옴 + 고은소금 3작은삽 = 3130
  
//실험 6.
//물 700mg + 10M옴 = 3030 = 농도 0%
//물 700mg + 10M옴 + 고은소금 1작은삽 = 3010 (변위 0) = 1.4%
//물 700mg + 10M옴 + 고은소금 2작은삽 = 2980 (변위 -30) = 2.7%
//물 700mg + 10M옴 + 고은소금 3작은삽 = 2977 (변위 -3) = 4.1%
//물 700mg + 10M옴 + 고은소금 4작은삽 = 2977 (변위 0) = 5.4%
//물 700mg + 10M옴 + 고은소금 6작은삽 = 2980 (변위 +3) = 7.8%
//물 700mg + 물 50mg + 10M옴 + 고은소금 6작은삽 = 3030 (변위 +50)

//실험 6을 통해서 알게되었는데, 10mg 소금을 센서에 적재를 하면
//물 700mg에서 합을 이루지 않고 소금+물의 무게는 그대로 700mg이다.
//그러면 고찰할 것은
//1) 무게 변동 없으므로 값이 변하지 않는 상태?
//2) 농도는 증가하지 않은 것인가?
//2)에 따른다면 일반 물의 최대로 녹은양인가?
//1)최대로 녹은 양이기 때문에 값은 변하지 않았나?

//PLA벽면으로 습기가 찬 것을 볼 때
//벽을 통해 물이 약간 세는 것을 알 수 있다.

//물의 양이 많아서인지 실험 6에서는 전기전도가 약 5cm가량 원거리 되었다.
