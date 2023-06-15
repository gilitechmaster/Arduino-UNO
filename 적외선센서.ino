#define inLED A0 //수광부
#define outLED 13 //발광부

void setup(){
  pinMode(outLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int r = analogRead(inLED);
  Serial.println(r);
  digitalWrite(outLED, LOW);
  delay(100);
}
