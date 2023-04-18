void setup() {
Serial.begin(9600);
}

void loop() {
  int sensor = analogRead(A0);
  Serial.println(sensor);
  delay(100);
}

//회로연결이 없을 경우 = 265

//압력센서 FSR 402
//평상시 = 220 ~ 290
//용기 = 235 ~ 250
//손가락으로 누를시 = 0
