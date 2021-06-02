//Arduino Mega Side 
#include <SdFat.h> SdFat sd; 
#define SD_ChipSelectPin 12   
#include <TMRpcm.h>          //  also need to include this library... TMRpcm audio; 
// create an object for use in this sketch // nrf24_server 
#include <SPI.h> 
#include <RH_NRF24.h> 
#include<SoftwareSerial.h> 
SoftwareSerial mySerial(4,5); 
//(Tx,Rx)for GSM String number = "+919836474193"; 
char call; 
int d1,d2,d3,d4; 
#include <ArduinoJson.h> 
SoftwareSerial ss(2,3); 
RH_NRF24 nrf24; 
 
 

///////////////////////////////// //Connections //Arduino 2 -> NodeMcu D7 //Arduino 3 -> NodeMcu D6 ///////////////////////////////// String str_soil; 
String str_humid; 
String str_temp; 
String str_out; 
String water; 
float e,f,c,d; 

void setup()  {   
	Serial.begin(9600); 
	ss.begin(9600); 
	mySerial.begin(9600); 
	delay(1000); 
    // Serial1.begin(9600); 
	while (!Serial); 
    // wait for serial port to connect. Needed for Leonardo only   if (!nrf24.init())     Serial.println("init failed"); 
	// Defaults after init are 2.402 GHz (channel 2), 2Mbps, 0dBm   if (!nrf24.setChannel(1))     Serial.println("setChannel failed"); 
	if (!nrf24.setRF(RH_NRF24::DataRate2Mbps, RH_NRF24::TransmitPower0dBm))     
		Serial.println("setRF failed"); 
		pinMode(22,INPUT); 
		pinMode(23,INPUT); 
		pinMode(24,INPUT); 
		pinMode(25,INPUT); 
		pinMode(13,OUTPUT); 
		audio.speakerPin = 46; 
  } 
  
 DynamicJsonDocument root(1024); 
 
 void loop() {   ///////for auto receive   
	mySerial.println(F("ATA")); 
	delay(1000);  
	if (nrf24.available())   {     // Should be a message for us now      
	uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN]; 
	uint8_t len = sizeof(buf); 
 
 
  
    if (nrf24.recv(buf, &len))     {       
       str_out = String((char*)buf); 
       //Serial.println(str_out); 
       // Split string into two values       
	   for (int i = 0; i < str_out.length(); i++) {
		   if (str_out.substring(i,i+1) == ",") {       
		   str_soil = str_out.substring(0, i); 
		   Serial.print(str_soil); 
		   Serial.println("%"); 
		   // ss.println(str_soil); 
		   str_humid = str_out.substring(i+1,i+5); 
		   Serial.print(str_humid); 
		   Serial.println("H"); 
		   //ss.println(str_humid); 
		   str_temp= str_out.substring(i+7,i+12); 
		   Serial.print(str_temp); 
		   Serial.println("*C"); 
		   //ss.println(str_temp); 
		   water=str_out.substring(i+13); 
		   Serial.print(water); 
		   Serial.println("cm"); 
		   //ss.println(water); 
		   Serial.println("  "); 
		   //break; 
		   c=str_temp.toFloat(); 
		   root["v2"] = c; 
		   f=str_humid.toFloat(); 
		   root["v1"] = f; 
		   d=water.toFloat(); 
		   root["v4"] = d; 
		   e=str_soil.toFloat(); 
		   root["v3"] = e; 
		   serializeJson(root,ss); 
           break; 
       }       }     }   }     
   d1=digitalRead(22); 
   d2=digitalRead(23); 
   d3=digitalRead(24); 
   d4=digitalRead(25); 
   if(d1==1&&d2==0&&d3==0&&d4==0) { 
		digitalWrite(13,1); 
		audio.play("2.wav"); 
    }  else if(d1==0&&d2==1&&d3==0&&d4==0)   { 
		digitalWrite(13,0); 
		audio.play("3.wav"); 
   }  else if(d1==1&&d2==1&&d3==0&&d4==0)     {   
		audio.play("4.wav"); 
		SendMessage(c,f,e,d); 
     }      
   delay(1000); 
 } 
 
 void SendMessage(int t,int h,int s,int w) {   
	Serial.println("Sending message...."); 
	mySerial.println("AT+CMGF=1"); 
	delay(1000); 
	mySerial.println("AT+CMGS=\"" + number + "\"\r"); 
	delay(1000); 
	// String SMS = "Hi Razib, How are you?"; 
	mySerial.println("The Temperature is ""+t+""The Humidity is ""+h+""The Soil moisture is ""+s+""The Water level is ""+w"); 
	delay(100); 
	mySerial.println((char)26); 
	delay(1000); 
	Serial.println("Message sent...");
 }	
 