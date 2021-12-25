#include <Arduino.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <WiFiClient.h>
#include "index.h"
#ifndef WifiSSID
#define WifiSSID "Tele2-0f3cf"  // Wifi network name
#define WifiPASS "12345678" // Wifi password
#endif

ESP8266WebServer server(80);
bool relayState = false;
int relayPin = 4; // D2 on esp-12f

void notFound()
{
  String msg = "404 Not found. ";
  msg += server.uri();
  msg += " " + server.args();
  server.send(404, "text/plain", msg);
}
void root()
{
  server.send(200, "text/html", indexHtml);
}

void api()
{
  //server.send(200, "text/plain", "Light Control API");
  String arg = server.arg("Light");
  if (arg == "on" && relayState == false)
  {
    relayState = true;
    digitalWrite(relayPin, LOW);
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, "text/plain", "Relay state changed to ON");
    Serial.println(1);
  }
  else if (arg == "off" && relayState == true)
  {
    relayState = false;
    digitalWrite(relayPin, HIGH);
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, "text/plain", "Relay state changed to OFF");
    Serial.println(2);
  }
  else
  {
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, "text/plain", relayState ? "ON" : "OFF");
  }
}

void setup()
{
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WifiSSID, WifiPASS);
  Serial.print("\nTrying to connect to ");
  Serial.print(WifiSSID);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.print("Connected!\n");
  Serial.println("IP address: ");
  Serial.print(WiFi.localIP());

  if (MDNS.begin("LightControl"))
  {
    Serial.println("\nMDNS started with name \"LightControl\"");
  }

  server.on("/", root);
  server.on("/api", api);
  server.onNotFound(notFound);
  server.begin();
  Serial.println("HTTP server started");
}

void loop()
{
  server.handleClient();
  MDNS.update();
}