#include <CapacitiveSensor.h>

CapacitiveSensor cs_2_3 = CapacitiveSensor(2, 3);
CapacitiveSensor cs_4_5 = CapacitiveSensor(4, 5);
CapacitiveSensor cs_6_7 = CapacitiveSensor(6, 7);
CapacitiveSensor cs_8_9 = CapacitiveSensor(8, 9);

void setup(){
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}
void setColor(int red, int green, int blue)
{
  digitalWrite(13, red);
  digitalWrite(12, green);
  digitalWrite(11, blue);
}


void loop(){
   CSread();
}

void CSread(){
  
  unsigned long cs1 = cs_2_3.capacitiveSensor(50);
  cs_2_3.set_CS_AutocaL_Millis(50);
  cs_2_3.set_CS_Timeout_Millis(50);
  
  unsigned long cs2 = cs_4_5.capacitiveSensor(50);
  cs_4_5.set_CS_AutocaL_Millis(50);
  cs_4_5.set_CS_Timeout_Millis(50);
  
  unsigned long cs3 = cs_6_7.capacitiveSensor(50);
  cs_6_7.set_CS_AutocaL_Millis(50);
  cs_6_7.set_CS_Timeout_Millis(50);

  unsigned long cs4 = cs_8_9.capacitiveSensor(50);
  cs_8_9.set_CS_AutocaL_Millis(50);
  cs_8_9.set_CS_Timeout_Millis(50);

if(cs4 < 15000){
    Serial.print("tilt = ");
    Serial.println(cs4);
    digitalWrite(12, HIGH);
  }
  if(cs4 > 15000){
    Serial.print("tilt = ");
    Serial.println(cs4);
    digitalWrite(12, LOW);
  }

if(cs3 < 15000){
    Serial.print("touch = ");
    Serial.println(cs3);
    digitalWrite(12, HIGH);
  }
  if(cs3 > 15000){
    Serial.print("touch = ");
    Serial.println(cs3);
    digitalWrite(12, LOW);
  }

if(cs2 < 1){
    Serial.print("liqiud = ");
    Serial.println(cs2);
    digitalWrite(11, HIGH);
  }
  if(cs2 > 1){
    Serial.print("liqiud = ");
    Serial.println(cs2);
    digitalWrite(11, LOW);
  }


  if(cs1 > 100){
    Serial.print("cds = ");
    Serial.println(cs1);
    digitalWrite(13, HIGH);
  }
  if(cs1 < 100){
    Serial.print("cds = ");
    Serial.println(cs1);
    digitalWrite(13, LOW);
  }
    
  
  
  delay(100);
  
}
