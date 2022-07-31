#include <ESP8266WiFi.h>
String apiKey = "insert key";
const char *ssid = "ABC";
const char *pass = "abc@2021";
const char *server = "api.thingspeak.com";
WiFiClient client;
void setup()
{
Serial.begin(115200);
delay(10);
Serial.println("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid, pass);
while (WiFi.status() != WL_CONNECTED)
{
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected");
}
void loop()
{
float sensorVoltage;
float sensorValue;
sensorValue = analogRead(A0);
sensorVoltage= sensorValue/1024*100;

if (isnan(sensorVoltage))
{
Serial.println("Failed to read from MQ-135 sensor!");
return;
}
if (client.connect(server, 80))
{
String postStr = apiKey;
postStr  += "&field1=";
postStr  +=String(sensorVoltage);
postStr  += "r\n";
client.print("POST /update HTTP/1.1\n");
client.print("Host: api.thingspeak.com\n");
client.print("Connection: close\n");
client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
client.print("Content-Type: application/x-www-form-urlencoded\n");
client.print("Content-Length: ");
client.print(postStr.length());
client.print("\n\n");
client.print(postStr);
Serial.print("Gas Level: ");
Serial.println(sensorVoltage);
Serial.println("Data Send to ThingSpeak");
}
client.stop();
Serial.println("Waiting...");
delay(1500);
}
