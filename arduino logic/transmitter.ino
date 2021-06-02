//Arduino Nano Side 
#include <DHT.h> 
#include <RH_NRF24.h>//nrf24_client 
#include <SPI.h> 
RH_NRF24 nrf24; 


int sensor_pin = A1; 
int output_value ; 
#define DHTPIN 8        
#define DHTTYPE DHT11    
float hum; 
float temp; 

DHT dht(DHTPIN, DHTTYPE); 
const int pingPin = 2; 

// Trigger Pin of Ultrasonic Sensor const int echoPin = 3; 
// Echo Pin of Ultrasonic Sensor void setup()  {   dht.begin(); 
Serial.begin(9600); 
while (!Serial); 
// wait for serial port to connect. Needed for Leonardo only   if (!nrf24.init())     Serial.println("init failed"); 
if (!nrf24.setChannel(1))     
   Serial.println("setChannel failed"); 
if (!nrf24.setRF(RH_NRF24::DataRate2Mbps, RH_NRF24::TransmitPower0dBm))     
   Serial.println("setRF failed"); 

 void loop() {    
	String str=""; 
	 int i; 
	Serial.println("Sending to nrf24_server"); 
	// Send a message to nrf24_server    uint8_t data[25]; 
	char xyz[25]; 
	float output_value= analogRead(sensor_pin); 
	output_value = map(output_value,550,0,0,100); 
	hum = dht.readHumidity(); 
	temp= dht.readTemperature(); 
	float duration,cm; 
 
    pinMode(pingPin, OUTPUT); 
    digitalWrite(pingPin, LOW); 
    delayMicroseconds(2); 
    digitalWrite(pingPin, HIGH); 
    delayMicroseconds(10); 
    digitalWrite(pingPin, LOW); 
    pinMode(echoPin, INPUT); 
    duration = pulseIn(echoPin, HIGH); 
    cm = microsecondsToCentimeters(duration); 
    str=String(output_value)+","+String(hum)+","+String(temp)+","+String(cm); 
    str.toCharArray(xyz,25); 
    for(i=0;i<sizeof(data);i++)    {     data[i]=uint8_t(xyz[i]); 
    }    
	nrf24.send(data, sizeof(data)); 
    delay(1000); 
 } long microsecondsToCentimeters(long microseconds) {    return microseconds / 29 / 2; 
 }