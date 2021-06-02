//nodemcu side 
#include <SoftwareSerial.h> 
SoftwareSerial ss(D6,D7); 
#include <ArduinoJson.h> 
#include <ESP8266WiFi.h> 
#include <WiFiClient.h> 
 
  
#include <ThingSpeak.h> 
const char* ssid  = "Engineers Inside"; 
const char* password = "idnthvpswrd"; 
const char* server="api.thingspeak.com"; 
String url; 
float a,b,c,d; 
WiFiClient client; 
unsigned long myChannelNumber = 716991; 
String apiKey = "6DI9SK70B1OWZ6YZ"; 
String str=""; 
   
void setup()  {    
	Serial.begin(9600); 
    ss.begin(9600); 
	delay(10); 
    //Connect to WiFi network      Serial.println(); 
    Serial.println(); 
    Serial.print("Connecting to "); 
	Serial.println(ssid); 
	WiFi.begin(ssid, password); 
	while (WiFi.status() != WL_CONNECTED) {       
		delay(500); 
		Serial.print("."); 
	  }      
	  Serial.println(""); 
	  Serial.println("WiFi connected"); 
	  // Print the IP address      Serial.println(WiFi.localIP()); 
	  ThingSpeak.begin(client); 
  } 
  
 DynamicJsonDocument root(1024); 
 
 void loop() {   
	DeserializationError error = deserializeJson(root, ss); 
	if (error)   {     
		return; 
	}    
	//Print the data in the serial monitor   Serial.println("JSON received and parsed"); 
	Serial.println(""); 
	Serial.print("Humidity: "); 
	float data1=root["v1"]; 
	Serial.println(data1); 
	Serial.print("Temperature: "); 
	float data2=root["v2"]; 
 
 
  
	Serial.println(data2); 
	Serial.print("Soil moisture: "); 
	float data3=root["v3"]; 
	Serial.println(data3); 
	Serial.print("Water level: "); 
	float data4=root["v4"]; 
	Serial.println(data4); 
	Serial.println(""); 
    upload(String(data1),String(data2),String(data3),String(data4)); 
} 

// for thingspeak void upload(String a,String b,String c,String d) //the upload function to upload the temp data {   String tsData=""; 
if(client.connect(server,80)) {
	 //connects to server at port 80   
	 tsData=apiKey; 
	 //takes the full string here ..thinkspeak supports string format     
	 tsData+="&field1="; 
     tsData+=a; 
     tsData+="&field2="; 
     tsData+=b; 
     tsData+="&field3="; 
     tsData+=c; 
     tsData+="&field4="; 
     tsData+=d; 
     tsData+="\r\n\r\n"; 
	 //strings are all concatenated     client.print("POST /update HTTP/1.1\n"); 
     client.print("Host: api.thinkspeak.com\n"); 
	 //data uploaded to server using POST method     client.print("Connection: close\n"); 
     client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n"); 
     client.print("Content-Type: application/x-www-form-urlencoded\n"); 
     client.print("Content-Length: "); 
     client.print(tsData.length()); 
     client.print("\n\n"); 
     client.print(tsData); 
  }   
client.stop(); 
//delay(30000); 
//thinkspeak needs a 15 sec delay }