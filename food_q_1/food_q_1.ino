#include <SoftwareSerial.h>

#include <LiquidCrystal.h>

#include <dht.h>   // include dht sensor library

LiquidCrystal lcd(10, 9, 5, 4, 3, 2);

dht DHT;

float t=0;

float h=0;

#define DHT11_PIN 8

#define LDR_PIN A1

#define MQ3_PIN A0

char data = 0;

int ldr_read = 0;

int gas_read = 0;

// replace with your channel's thingspeak API key

String apiKey = "[API KEY FROM THINGSPEAK]";

// connect 10 to TX of Serial USB

// connect 11 to RX of serial USB

SoftwareSerial ser(12,13); // RX, TX

void setup() 

{                

  // enable software serial

  ser.begin(9600);

  lcd.begin(16,2);


 

 // pinMode(LDR_PIN, INPUT);

  //pinMode(MQ3_PIN, INPUT);


 

  lcd.setCursor(1,0);

  lcd.print("**SmarT FooD**");

  lcd.setCursor(3,1);

  lcd.print("MonitorinG");

  Serial.begin(9600);


 

  // reset ESP8266 WiFi connection AT+CIPMUX=1 AT+CWJAP

  ser.println("AT");

  delay(1000);

  ser.println("AT+GMR");

  delay(1000);

  ser.println("AT+CWMODE=3");

  delay(1000);

  ser.println("AT+RST");

  delay(5000);

  ser.println("AT+CIPMUX=1");

  delay(1000);

  String cmd="AT+CWJAP=\"[YOUR SSID]\",\"[PASSWORD]\"";

  ser.println(cmd);

  delay(1000);

  ser.println("AT+CIFSR");

  delay(1000);

 }

// the loop 

void loop()

{

  lcd.clear();

  ldr_read = analogRead(LDR_PIN);

  lcd.setCursor(0,0);

  lcd.print("LDR-");

  lcd.setCursor(4,0);

  lcd.print(ldr_read);


 

  lcd.setCursor(0,1);

  lcd.print("MQ3-");

  gas_read = analogRead(MQ3_PIN);

  lcd.setCursor(4,1);

  lcd.print(gas_read);


 

  int chk = DHT.read11(DHT11_PIN);

  Serial.print("Temperature = ");

  t = DHT.temperature;


 

  //lcd.clear();

  lcd.setCursor(8,0);

  lcd.print("Tem-");


 

  lcd.setCursor(12,0);

  lcd.print(t);

  Serial.println(t);


 

  Serial.print("Humidity = ");

  h = DHT.humidity;

  lcd.setCursor(8,1);

  lcd.print("Hum-");

  lcd.setCursor(12,1);

  lcd.print(h);

  Serial.println(h);


 

  esp_8266();

}

void esp_8266()

{

   // TCP connection AT+CIPSTART=4,"TCP","184.106.153.149",80 

    String cmd = "AT+CIPSTART=4,\"TCP\",\"";

    cmd += "184.106.153.149"; // api.thingspeak.com

    cmd += "\",80";

    ser.println(cmd);

    Serial.println(cmd); 

    if(ser.find("Error"))

    {

      Serial.println("AT+CIPSTART error");

      return;

    }


 

  // prepare GET string GET https://api.thingspeak.com/update?api_key=LHAG4NSIYJ5UWS6U&field1=0\r\n\r\n

  String getStr = "GET /update?api_key=";

  getStr += apiKey;

  getStr +="&field1=";

  getStr +=String(t);

  getStr +="&field2=";

  getStr +=String(h);

  getStr +="&field3=";

  getStr +=String(ldr_read);

  getStr +="&field4=";

  getStr +=String(gas_read);

  getStr += "\r\n\r\n";

  // send data length

  cmd = "AT+CIPSEND=4,";

  cmd += String(getStr.length());

  ser.println(cmd);

  Serial.println(cmd);

  delay(1000);

  ser.print(getStr);

  Serial.println(getStr);


    

  // thingspeak needs 15 sec delay between updates

  delay(3000);  

}
