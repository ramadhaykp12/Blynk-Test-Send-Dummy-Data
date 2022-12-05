#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL8WdKAqhG"
#define BLYNK_DEVICE_NAME "Data Dummy"
#define BLYNK_AUTH_TOKEN "yDFtW-OP0_tE5WUtJdSZxhHnqmBSKGu9"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Your SSID";
char password[] ="Your Hotspot";

int dummyData;
BlynkTimer timer;


void myTimerEvent()
{
  dummyData = millis();
  Blynk.virtualWrite(V0,dummyData / 1000);
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth,ssid,password);
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run(); 
}
