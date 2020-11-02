#include <ESP8266WiFi.h>

WiFiClient client;
const char* MY_SSID = "ORL"; 
const char* MY_PWD = "orl_india";
String data="SURYA";

void setup() { 
  Serial.begin(9600);
  connectWifi();

  delay(10000); // GIVE THE SENSOR SOME TIME TO START
  data = "";
}

void loop()
{ 
  rForward();
  delay(200);
  rBackward();
  delay(200);
  rLeft();
  delay(200);
  rRight();
  delay(200);
  rStop();
  delay(200);
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
  if (client.connect("192.168.1.10",80))
  { // REPLACE WITH YOUR SERVER ADDRESS
    client.println("GET /robotdir=forward HTTP/1.1"); 
    Serial.println("GET /robotdir=forward HTTP/1.1"); 
    /*client.println("Host:192.168.1.10"); // SERVER ADDRESS HERE TOO
    Serial.println("Host:192.168.1.10"); // SERVER ADDRESS HERE TOO
    client.println("Content-Type: application/x-www-form-urlencoded");
    Serial.println("Content-Type: application/x-www-form-urlencoded"); 
    client.print("Content-Length: ");
    Serial.print("Content-Length: "); 
    client.println(data.length()); 
    Serial.println(data.length()); 
    client.println(); 
    client.print(data);
    delay(1000);
    Serial.println(data);*/ 
  } 

  if (client.connected()) { 
    client.stop();  // DISCONNECT FROM THE SERVER
  }

  delay(2000); // WAIT FIVE MINUTES BEFORE SENDING AGAIN
}
void rBackward()
{
  if (client.connect("192.168.1.10",80))
  { // REPLACE WITH YOUR SERVER ADDRESS
    client.println("GET /robotdir=backward HTTP/1.1"); 
    Serial.println("GET /robotdir=backward HTTP/1.1"); 
    /*client.println("Host:192.168.1.10"); // SERVER ADDRESS HERE TOO
    Serial.println("Host:192.168.1.10"); // SERVER ADDRESS HERE TOO
    client.println("Content-Type: application/x-www-form-urlencoded");
    Serial.println("Content-Type: application/x-www-form-urlencoded"); 
    client.print("Content-Length: ");
    Serial.print("Content-Length: "); 
    client.println(data.length()); 
    Serial.println(data.length()); 
    client.println(); 
    client.print(data);
    delay(1000);
    Serial.println(data);*/ 
  } 

  if (client.connected()) { 
    client.stop();  // DISCONNECT FROM THE SERVER
  }

  delay(3000); // WAIT FIVE MINUTES BEFORE SENDING AGAIN
}
void rLeft()
{
  if (client.connect("192.168.1.10",80))
  { // REPLACE WITH YOUR SERVER ADDRESS
    client.println("GET /robotdir=left HTTP/1.1"); 
    Serial.println("GET /robotdir=left HTTP/1.1"); 
    /*client.println("Host:192.168.1.10"); // SERVER ADDRESS HERE TOO
    Serial.println("Host:192.168.1.10"); // SERVER ADDRESS HERE TOO
    client.println("Content-Type: application/x-www-form-urlencoded");
    Serial.println("Content-Type: application/x-www-form-urlencoded"); 
    client.print("Content-Length: ");
    Serial.print("Content-Length: "); 
    client.println(data.length()); 
    Serial.println(data.length()); 
    client.println(); 
    client.print(data);
    delay(1000);
    Serial.println(data);*/ 
  } 

  if (client.connected()) { 
    client.stop();  // DISCONNECT FROM THE SERVER
  }

  delay(2000); // WAIT FIVE MINUTES BEFORE SENDING AGAIN
}
void rRight()
{
  if (client.connect("192.168.1.10",80))
  { // REPLACE WITH YOUR SERVER ADDRESS
    client.println("GET /robotdir=right HTTP/1.1"); 
    Serial.println("GET /robotdir=right HTTP/1.1"); 
    /*client.println("Host:192.168.1.10"); // SERVER ADDRESS HERE TOO
    Serial.println("Host:192.168.1.10"); // SERVER ADDRESS HERE TOO
    client.println("Content-Type: application/x-www-form-urlencoded");
    Serial.println("Content-Type: application/x-www-form-urlencoded"); 
    client.print("Content-Length: ");
    Serial.print("Content-Length: "); 
    client.println(data.length()); 
    Serial.println(data.length()); 
    client.println(); 
    client.print(data);
    delay(1000);
    Serial.println(data);*/ 
  } 

  if (client.connected()) { 
    client.stop();  // DISCONNECT FROM THE SERVER
  }

  delay(2000); // WAIT FIVE MINUTES BEFORE SENDING AGAIN
}
void rStop()
{
  if (client.connect("192.168.1.10",80))
  { // REPLACE WITH YOUR SERVER ADDRESS
    client.println("GET /robotdir=stop HTTP/1.1"); 
    Serial.println("GET /robotdir=stop HTTP/1.1"); 
    /*client.println("Host:192.168.1.10"); // SERVER ADDRESS HERE TOO
    Serial.println("Host:192.168.1.10"); // SERVER ADDRESS HERE TOO
    client.println("Content-Type: application/x-www-form-urlencoded");
    Serial.println("Content-Type: application/x-www-form-urlencoded"); 
    client.print("Content-Length: ");
    Serial.print("Content-Length: "); 
    client.println(data.length()); 
    Serial.println(data.length()); 
    client.println(); 
    client.print(data);
    delay(1000);
    Serial.println(data);*/ 
  } 
  if (client.connected()) { 
    client.stop();  // DISCONNECT FROM THE SERVER
  }
  delay(3000); // WAIT FIVE MINUTES BEFORE SENDING AGAIN
}




