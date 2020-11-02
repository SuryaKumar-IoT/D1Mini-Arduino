#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

const char* ssid = "pankaj";
const char* password = "pankajdiwan";

const char* host = "api.thingspeak.com";
//const int httpsPort = 80;//443
String l_line="";
char t_data[10];
void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  read_thingspeak();
  Serial.print("Field Data:");
  Serial.println(t_data);
  delay(1000);
}

void loop()
{

}

void read_thingspeak()
{
  WiFiClient client;
  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host,80))
  {
    Serial.println("connection failed");
    return;
  }
  String url = "https://api.thingspeak.com/channels/221295/fields/1.json?results=1";
  Serial.print("requesting URL: ");
  Serial.println(url);
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Content-Type: application/x-www-form-urlencoded\r\n" +
               "Connection: close\r\n\r\n");
  Serial.println("request sent");
  delay(1000);
  while(!client.available())
  {
     delay(1);
  }
  l_line = client.readStringUntil(']');
  //Serial.println(l_line);
  //delay(2000);
  if (l_line!= "")
  {
      int commaIndex=l_line.indexOf('[');
      int secondCommaIndex = l_line.indexOf(',', commaIndex+1);
      int thirdCommaIndex=l_line.indexOf(',',secondCommaIndex+1);
      int fourthCommaIndex=l_line.indexOf(':',thirdCommaIndex+1);
      int fifthCommaIndex=l_line.indexOf('}',fourthCommaIndex+1);
      
      String s1= l_line.substring(0, commaIndex);
      String s2 =l_line.substring(commaIndex+1, secondCommaIndex);
      String s3 = l_line.substring(secondCommaIndex+1,thirdCommaIndex);
      String s4  = l_line.substring(thirdCommaIndex+1,fourthCommaIndex);
      String s5 = l_line.substring(fourthCommaIndex+1,fifthCommaIndex);

      /*Serial.print("S1:");
      Serial.println(s1);
      delay(1000);
      Serial.print("S2:");
      Serial.println(s2);
      delay(1000);
      Serial.print("S3:");
      Serial.println(s3);
      delay(1000);*/
      Serial.print("Field No:");
      Serial.println(s4);
      if(s5!="")
      {
        int commaIndex1=s5.indexOf('"');
        int secondCommaIndex1 = s5.indexOf('"', commaIndex1+1);
        String s51= s5.substring(0, commaIndex1);
        String s52 =s5.substring(commaIndex1+1, secondCommaIndex1);
        
        s52.toCharArray(t_data,20);
        delay(200);  
      }  
    }
  Serial.println("closing connection");
}

