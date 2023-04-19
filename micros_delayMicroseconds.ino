unsigned long time;

void setup(){
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}
void loop(){
  Serial.print("Time: ");
  time = micros();

  Serial.println(time);
  digitalWrite(13, HIGH);
  delay(50);
  //delayMicroseconds(50000);
  digitalWrite(13, LOW);
  delay(50);
  //delayMicroseconds(50000);
}

//핀13 = 아두이노 내장 LED
//50밀리초마다 LED를 껏다 킨다.
//delayMicroseconds는 50000(=50ms)까지
//테스트 했으나 핀13은 켜지지 않는다.

//micros 값은 1초 = 100만으로 기록된다.
