#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int distanceThreshold = 0;
int cm = 0;
int inches = 0;
int releNO = 13;
int inputPir = 8;
int val = 0;
int resuldoSensorLDR;
int sensorLDR = A0;
int const PINO_SGAS = A1;


long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup() {
  lcd.begin(16, 2);
  
  pinMode(releNO, OUTPUT);
  pinMode(inputPir, INPUT);
  pinMode(sensorLDR, INPUT);
  Serial.begin(9600);
}

void loop() {
  distanceThreshold = 350;
  cm = 0.01723 * readUltrasonicDistance(7, 6);
  inches = (cm / 2.54);
  
    lcd.setCursor(0,0);
  lcd.print("D:");
  lcd.print(cm);
  lcd.print("cm");
  delay(10);
  
    val = digitalRead(inputPir);
  resuldoSensorLDR = analogRead(sensorLDR);
  if(resuldoSensorLDR<600)
  {
    if(val == HIGH)
    {
      digitalWrite(releNO, HIGH);
      lcd.setCursor(0,1);
  lcd.print("L: On ");
      delay(5000);
  }
    else{
      digitalWrite(releNO, LOW);lcd.setCursor(0,1);
  lcd.print("L: Off");
      delay(300);
  }
}
  else{ digitalWrite (releNO, LOW);
  Serial.println(resuldoSensorLDR);
  delay(500);
  }
  
  int color = analogRead(PINO_SGAS);
  
  lcd.setCursor(8,0);
  if(color <= 85){
    lcd.print("G:Low ");
  } else if(color <= 120){
    lcd.print("G:Med ");
  } else if(color <= 200){
    lcd.print("G:High");
  } else if(color <= 300){
    lcd.print("G:Ext ");
  }
  
  delay(250);
}