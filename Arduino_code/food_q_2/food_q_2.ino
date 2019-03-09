#include <Adafruit_Sensor.h>
#include "DHT.h"


#define DHTTYPE DHT11
#define DHT11_PIN 8
#define MQ3_PIN A0

DHT dht(DHT11_PIN, DHTTYPE);

String debug;

char data = 0;
int gas_read = 0;
float temp;
float hum;

void setup()
{
  //ser.begin(115200);

  dht.begin();

  Serial.begin(115200); 

  Serial.println("AT");  
  delay(1000);
  Serial.println("AT+GMR");
  delay(1000);
  Serial.println("AT+CWMODE=3");
  delay(1000);
  Serial.println("AT+RST");
  delay(5000);
  Serial.println("AT+CIPMUX=1");
  delay(1000);
  String cmd="AT+CWJAP=\"SuperUser\",\"pinaqsharma0207\"";
  Serial.println(cmd);
  delay(1000);
  Serial.println("AT+CIFSR");
  delay(1000);
}

void loop()
{
  gas_read = analogRead(MQ3_PIN);
  temp = dht.readTemperature();
  hum = dht.readHumidity();

  esp_8266();
}

void esp_8266()
{
  String cmd="AT+CIPSTART=0,\"TCP\",\"192.168.43.210\",8000";
  Serial.println(cmd);

  String getStr="GET /update/?d1=";
  getStr+=String(temp);
  getStr+="&d2=";
  getStr+=String(hum);
  getStr+="&d3=";
  getStr+=String(gas_read);
  cmd = "AT+CIPSEND=0,";
  cmd += String(getStr.length());
  Serial.println(cmd);
  delay(1000);
  Serial.println(getStr);
  delay(1000);
  Serial.println("AT+CIPCLOSE=0");
  delay(1000);
}
