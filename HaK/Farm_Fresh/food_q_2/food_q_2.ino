#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include <Adafruit_Sensor.h>
#include "DHT.h"

LiquidCrystal lcd(10, 9, 5, 4, 3, 2);

#define DHTTYPE DHT11
#define DHT11_PIN 8
#define MQ3_PIN A0

DHT dht(DHT11_PIN, DHTTYPE);

String debug;

char data = 0;
int gas_read = 0;
float temp;
float hum;

SoftwareSerial ser(12,13); // RX, TX

void setup()
{
  //ser.begin(115200);

  dht.begin();
  
  lcd.begin(16,2);
  lcd.setCursor(1,0);
  lcd.print("**SmarT FooD**");
  lcd.setCursor(3,1);
  lcd.print("MonitorinG");

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
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.setCursor(4,0);

  lcd.setCursor(0,1);
  lcd.print("MQ3-");
  gas_read = analogRead(MQ3_PIN);
  lcd.setCursor(4,1);
  lcd.print(gas_read);

  //int chk = dht.read11(DHT11_PIN);
  //Serial.print("Temperature = ");
  temp = dht.readTemperature();
  //lcd.clear();
  lcd.setCursor(8,0);
  lcd.print("Tem-");
  lcd.setCursor(12,0);
  lcd.print(temp);
  //Serial.println(temp);
  //Serial.print("Humidity = ");
  hum = dht.readHumidity();
  lcd.setCursor(8,1);
  lcd.print("Hum-");
  lcd.setCursor(12,1);
  lcd.print(hum);
  //Serial.println(hum);

  esp_8266();
}

void esp_8266()
{
  String cmd="AT+CIPSTART=0,\"TCP\",\"192.168.43.210\",8000";
  ser.println(cmd);
  Serial.println(cmd);

  if(ser.find("Error"))
    {
      Serial.println("AT+CIPSTART error");
      return;
    }

  String getStr="GET /update/?d1=";
  getStr+=String(temp);
  getStr+="&d2=";
  getStr+=String(hum);
  getStr+="&d3=";
  getStr+=String(gas_read);
  cmd = "AT+CIPSEND=0,";
  cmd += String(getStr.length());
  ser.println(cmd);
  Serial.println(cmd);
  delay(1000);
  ser.print(getStr);
  Serial.println(getStr);
  delay(1000);
  ser.println("AT+CIPCLOSE=0");
  Serial.println("AT+CIPCLOSE=0");
  delay(10000);
}

