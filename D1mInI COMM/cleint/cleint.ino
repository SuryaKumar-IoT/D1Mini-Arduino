#include <ESP8266WiFi.h>
 
const char* ssid = "ORL";
const char* password = "orl_india";
 
int ledPin = 13; // GPIO13
WiFiServer server(80);
 
void setup() {
  Serial.begin(9600);
  delay(10);
 
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
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
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("Client Connected");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
 
  int value = LOW;
  if (request.indexOf("/robotdir=forward") != -1)
  {
    Serial.println("Forward");
  }
  if (request.indexOf("/robotdir=backward") != -1)
  {
    Serial.println("Backward");
  }
  if (request.indexOf("/robotdir=left") != -1)
  {
    Serial.println("Left");
  }
  if (request.indexOf("/robotdir=right") != -1)
  {
    Serial.println("Right");
  }
  if (request.indexOf("/robotdir=stop") != -1)
  {
    Serial.println("Stop");
  }
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
 

