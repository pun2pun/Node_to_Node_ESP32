#include <SPI.h>
#include <WiFi.h>
#include <TridentTD_LineNotify.h>

#define LINE_TOKEN "Fki6Pje9S3QZsi1NWvNTCmxZkGvBpiRu4bdonS1iFlM"


byte LED_PIN = 2;
void LED_Blink(void);
void WiF_server(void);
b

char ssid[] = "PLC-Smart Farm 8080";              
char pass[] = "farm1212312121ubu";  


WiFiServer server(80);

IPAddress ip(192, 168, 1, 80);            
IPAddress gateway(192,168,1,1);          
IPAddress subnet(255,255,255,0);    
 

void setup() {
  pinMode(LED_PIN,OUTPUT);  pinMode(4,INPUT);
  Serial.begin(115200);


LINE.setToken(LINE_TOKEN);

  
 // WiFi.config(ip, gateway, subnet);
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(ssid, pass);
  WiFi.softAP("PunPun",""); 

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  if(WiFi.status() == WL_CONNECTED){
     Serial.println(" ");
      Serial.println("We connect internet !! Yeahhhh ");
    }

  server.begin();

}

void loop() {
  WiF_server();

 
    
}


//----------------------------------------------------  USER FUNCTTION ---------------------------------
void LED_Blink(){ 
   digitalWrite(LED_PIN,1); delay(500);
   digitalWrite(LED_PIN,0); delay(500);
}

void WiF_server(){
  WiFiClient client = server.available();
  if (client) {
    if (client.connected()) {
      digitalWrite(LED_PIN, LOW);  
      Serial.println(".");
      String request = client.readStringUntil('\n');   
      Serial.print("From client: "); Serial.println(client);
      client.flush();
      client.println("Hi client! No, I am listening.\r");
      digitalWrite(LED_PIN, HIGH);
       LINE.notify("Test");
 
   

      
    }
    client.stop();                
  }
}




  
