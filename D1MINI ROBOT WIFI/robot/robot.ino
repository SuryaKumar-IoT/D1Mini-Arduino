#include <ESP8266WiFi.h>
 
const char* ssid = "ORL";
const char* password = "orl_india";
WiFiServer server(80);
 
void setup() 
{
  pinMode(16,OUTPUT);//DO 
  pinMode(5,OUTPUT);//D1
  pinMode(4,OUTPUT);//D2
  pinMode(0,OUTPUT);//D3
  pinMode(2,OUTPUT);//D4
  pinMode(14,OUTPUT);//D5
  
  Serial.begin(9600);
  delay(10); 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  // Start the server
  server.begin();
  Serial.println("Server started");
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}
void loop()
{
  WiFiClient client = server.available();
  if (!client)
  {
    return;
  }
  // Wait until the client sends some data
  Serial.println("Client Connected");
  while(!client.available())
  {
    delay(1);
  }
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  // Match the request
  if (request.indexOf("/robotdir=forward") != -1)
  {
    Serial.println("Forward");
    digitalWrite(16,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(0,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(14,LOW);
    delay(500);
  }
  if (request.indexOf("/robotdir=backward") != -1)
  {
    Serial.println("Backward");
    digitalWrite(16,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(0,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(14,HIGH);
    digitalWrite(2,LOW);
    delay(500);
  }
  if (request.indexOf("/robotdir=left") != -1)
  {
    Serial.println("Left");
    digitalWrite(16,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(0,LOW);
    digitalWrite(2,LOW);
    digitalWrite(14,LOW);
    delay(500);
  }
  if (request.indexOf("/robotdir=right") != -1)
  {
    Serial.println("Right");
    digitalWrite(16,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(0,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(14,LOW);
    delay(500);
  }
  if (request.indexOf("/robotdir=stop") != -1)
  {
    Serial.println("Stop");
    digitalWrite(16,LOW);
    digitalWrite(5,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(0,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(14,LOW);
    delay(500);
  }
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}


