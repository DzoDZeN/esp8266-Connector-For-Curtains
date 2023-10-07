#include <ESP8266WiFi.h>
 
const char* ssid = "Kolobok 2.4Gz";
const char* password =  "87654321";
 
const uint16_t port = 8080;
const char * host = "80.76.42.42";

void setup()
{
  Serial.begin(9600);
 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("...");
  }
 
  Serial.print("WiFi connected with IP: ");
  Serial.println(WiFi.localIP());
 
}
 
void loop()
{
    WiFiClient client;
    
    if (!client.connect(host, port)) {
 
        Serial.println("Connection to host failed");
 
        delay(1000);
        return;
    }
 
    Serial.println("Connected to server successful!");
    while (client.connected()){
      client.setTimeout(200);
      while(!client.available()){
      }
    Serial.write(client.read());
}

    Serial.println("Disconnecting...");
    client.stop();
 
    delay(10000);
}