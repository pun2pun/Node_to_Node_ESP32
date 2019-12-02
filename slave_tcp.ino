#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "PunPun";
const char* password =  "";
 
void setup() {
 
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
 
}
void loop(){

  
    if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status
 
   HTTPClient http;   
 
   http.begin("http://192.168.4.1");  //Specify destination for HTTP request
   http.addHeader("Content-Type", "text/plain");             //Specify content-type header
 
   int httpResponseCode = http.POST("POSTING from ESP32");   //Send the actual POST request
 
           if(httpResponseCode>0){
         
                String response = http.getString();                       //Get the response to the request
             
                Serial.println(httpResponseCode);   //Print return code
                Serial.println(response);           //Print request answer
                Serial.println("send already ");
           }
           
           else{
         
                Serial.print("Error on sending POST: ");
                Serial.println(httpResponseCode);
         
           }
   
     http.end();  //Free resources
   
   }
 else{
 
    Serial.println("Error in WiFi connection");   
 
 }
 
  delay(5000);  //Send a request every 10 seconds
 
  
  }
 
