#include <ESP8266WiFi.h>

WiFiClient client;
const char* MY_SSID = "ORL"; 
const char* MY_PWD = "orl_india";
const char* url="192.168.1.3";
void setup()
{  
  pinMode(5,INPUT_PULLUP);//D1
  pinMode(4,INPUT_PULLUP);//D2
  pinMode(0,INPUT_PULLUP);//D3
  pinMode(2,INPUT_PULLUP);//D4
  Serial.begin(9600);
  connectWifi();
  delay(10000); // GIVE THE SENSOR SOME TIME TO START
}

void loop()
{ 
  if(digitalRead(5)==0)
  {
    rForward();
    delay(200);
  }
  else if(digitalRead(4)==0)
  {
    rBackward();
    delay(200);
  }
  else if(digitalRead(0)==0)
  {
    rLeft();
    delay(200);
  }
  else if(digitalRead(2)==0)
  {
    rRight();
    delay(200);
  }
  else
  {
    rStop();
    delay(200);
  }
}
void connectWifi()
{
  Serial.print("Connecting to "+*MY_SSID);
  WiFi.begin(MY_SSID, MY_PWD);
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("Connected");
  Serial.println("");  
}
void rForward()
{
  if (client.connect(url,80))
  { // REPLACE WITH YOUR SERVER ADDRESS
    client.println("GET /robotdir=forward HTTP/1.1"); 
    Serial.println("GET /robotdir=forward HTTP/1.1"); 
  } 
  if (client.connected()) { 
    client.stop();  // DISCONNECT FROM THE SERVER
  }
  delay(2000); // WAIT FIVE MINUTES BEFORE SENDING AGAIN
}
void rBackward()
{
  if (client.connect(url,80))
  { 
    client.println("GET /robotdir=backward HTTP/1.1"); 
    Serial.println("GET /robotdir=backward HTTP/1.1"); 
  } 
  if (client.connected()) { 
    client.stop();  // DISCONNECT FROM THE SERVER
  }
  delay(3000); // WAIT FIVE MINUTES BEFORE SENDING AGAIN
}
void rLeft()
{
  if (client.connect(url,80))
  { 
    client.println("GET /robotdir=left HTTP/1.1"); 
    Serial.println("GET /robotdir=left HTTP/1.1"); 
  } 
  if (client.connected()) { 
    client.stop();  // DISCONNECT FROM THE SERVER
  }
  delay(2000); // WAIT FIVE MINUTES BEFORE SENDING AGAIN
}
void rRight()
{
  if (client.connect(url,80))
  { 
    client.println("GET /robotdir=right HTTP/1.1"); 
    Serial.println("GET /robotdir=right HTTP/1.1");
  } 
  if (client.connected()) { 
    client.stop();  // DISCONNECT FROM THE SERVER
  }

  delay(2000); // WAIT FIVE MINUTES BEFORE SENDING AGAIN
}
void rStop()
{
  if (client.connect(url,80))
  { 
    client.println("GET /robotdir=stop HTTP/1.1"); 
    Serial.println("GET /robotdir=stop HTTP/1.1"); 
  } 
  if (client.connected()) { 
    client.stop();  // DISCONNECT FROM THE SERVER
  }
  delay(3000); // WAIT FIVE MINUTES BEFORE SENDING AGAIN
}




