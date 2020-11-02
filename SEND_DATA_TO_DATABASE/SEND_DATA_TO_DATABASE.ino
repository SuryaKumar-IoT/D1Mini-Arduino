#include <ESP8266WiFi.h>

WiFiClient client;
const char* MY_SSID = "ORL"; 
const char* MY_PWD = "orl_india";
String data;

void setup() { 
  Serial.begin(9600);
  connectWifi();

  delay(10000); // GIVE THE SENSOR SOME TIME TO START
  data = "";
}

void loop()
{ 
 int h = analogRead(A0);
 int t = analogRead(A0);
 
 data = "boot_value="+String(t)+"&boot_value1="+String(h);
 data += "\r\n\r\n";
  if (client.connect("192.168.1.9",80))
  { // REPLACE WITH YOUR SERVER ADDRESS
    client.println("POST /d1mini.php HTTP/1.1"); 
    Serial.println("POST /d1mini.php HTTP/1.1"); 
    client.println("Host:192.168.1.9"); // SERVER ADDRESS HERE TOO
    Serial.println("Host:192.168.1.9"); // SERVER ADDRESS HERE TOO
    client.println("Content-Type: application/x-www-form-urlencoded");
    Serial.println("Content-Type: application/x-www-form-urlencoded"); 
    client.print("Content-Length: ");
    Serial.print("Content-Length: "); 
    client.println(data.length()); 
    Serial.println(data.length()); 
    client.println(); 
    client.print(data);
    delay(1000);
    Serial.println(data); 
  } 

  if (client.connected()) { 
    client.stop();  // DISCONNECT FROM THE SERVER
  }

  delay(3000); // WAIT FIVE MINUTES BEFORE SENDING AGAIN
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



