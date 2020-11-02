int led=13;
int sw=5;

void setup() 
{
  pinMode(sw,INPUT);
  pinMode(led,OUTPUT);
}

void loop() 
{
  if(digitalRead(sw)==0)
    digitalWrite(led,LOW);
  else
    digitalWrite(led,HIGH);
}
