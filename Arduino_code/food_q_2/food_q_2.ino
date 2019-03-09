#include <Adafruit_Sensor.h>
#include "DHT.h"                                                                      //Required Sensor Libraries to communicate with DHT-11 sensor


#define DHTTYPE DHT11                                                                 //Tyoe of DHT sensor used
#define DHT11_PIN 8                                                                   //DHT sensor data pin
#define MQ3_PIN A0                                                                    //MQ-3 Gas sensor pin

DHT dht(DHT11_PIN, DHTTYPE);                                                          //initiaization of the DHT-11 sensor

char data = 0;                                                                        //initialization of the required variables
int gas_read = 0;
float temp;
float hum;

void setup()
{
  dht.begin();

  Serial.begin(115200);                                                               //begin serial communication

  Serial.println("AT");                                                               //Communication with NodeMCU using standard AT commands to
  delay(1000);                                                                        //initialize communication and connect to the Wi-Fi network
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
  gas_read = analogRead(MQ3_PIN);                                                   //Requests for data on analog pin A0 for sensor vzlues 
  temp = dht.readTemperature();                                                     //Reads the Temperature value in °C
  hum = dht.readHumidity();                                                         //Reads the Humidity in the air

  esp_8266();                                                                       //Calls function to send data to appliction server
}

void esp_8266()
{
  String cmd="AT+CIPSTART=0,\"TCP\",\"192.168.43.210\",8000";                      //Initialize TCP communication to the application server
  Serial.println(cmd);

  String getStr="GET /update/?d1=";                                                //Creates a data set in the format GET /update/?d1='TEMP'&d2='HUMIDITY'&d3='METHENE GAS'
  getStr+=String(temp);
  getStr+="&d2=";
  getStr+=String(hum);
  getStr+="&d3=";
  getStr+=String(gas_read);
  cmd = "AT+CIPSEND=0,";                                                          //Closes the container for the TCP communication packet
  cmd += String(getStr.length());
  Serial.println(cmd);
  delay(1000);
  Serial.println(getStr);
  delay(1000);
  Serial.println("AT+CIPCLOSE=0");                                                //Sends the TCP packet and closes the connection
  delay(1000);
}
