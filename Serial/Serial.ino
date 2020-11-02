void setup()
{
  Serial.begin(9600);
  Serial.println("WELCOME");
}

void loop() 
{
  while(Serial.available())
  {
    char ch= Serial.read();
    Serial.println(ch);
  }
}
