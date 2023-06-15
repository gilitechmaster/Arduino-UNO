#define inLED A0 //수광부
#define outLED 13 //발광부

int val = 0;
void setup() {
  pinMode(outLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int r = analogRead(inLED);
  if(r > 999){
    digitalWrite(outLED, HIGH);
  }else{
    digitalWrite(outLED, LOW);
  }
  if( abs(r - val) > 0){
    Serial.println(r);
    val = r;
    delay(100);
  }
}

//https://blog.xcoda.net/78
