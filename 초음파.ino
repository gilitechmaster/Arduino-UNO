int trig = 8;
int echo = 9;

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  digitalWrite(echo, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  unsigned long duration = pulseIn(echo, HIGH);
  float distance = duration/29.0/2.0;
  Serial.print(distance);
  Serial.println("cm");
 
}

//https://kocoafab.cc/tutorial/view/757 에서 수정했다.
