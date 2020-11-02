void setup()
{
  pinMode(16,OUTPUT);//DO 
  pinMode(5,OUTPUT);//D1
  pinMode(4,OUTPUT);//D2
  pinMode(0,OUTPUT);//D3
  pinMode(2,OUTPUT);//D4
  pinMode(14,OUTPUT);//D5
  pinMode(12,OUTPUT);//D6
  pinMode(13,OUTPUT);//D7
  pinMode(15,OUTPUT);//D8
  
  digitalWrite(16,LOW);
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  digitalWrite(0,LOW);
  digitalWrite(2,LOW);
  digitalWrite(14,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  digitalWrite(15,LOW);
}

void loop()
{
  digitalWrite(16,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(0,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(14,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  digitalWrite(15,HIGH);

  delay(300);

  digitalWrite(16,LOW);
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  digitalWrite(0,LOW);
  digitalWrite(2,LOW);
  digitalWrite(14,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  digitalWrite(15,LOW);
  
  delay(300);
}
