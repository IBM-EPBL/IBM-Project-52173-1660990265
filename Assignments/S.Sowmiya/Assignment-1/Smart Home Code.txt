// C++ code
//
void setup()
{
  pinMode(A2, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);
  pinMode(A1, INPUT);
 
}

void loop()
{
  
 int temp=analogRead(A1);
 if(temp>30)
 {
   digitalWrite(2,HIGH);
 }
   if(temp<30)
 {
   digitalWrite(2,LOW);
 }
 
 int gas=analogRead(A0);
 int b=map(gas,0,1023,0,255);
 if(b>50)
 {
   analogWrite(A2,b*10);
   delay(1000);
   analogWrite(A2,0);
   delay(10);
 }
 delay(500);
}
