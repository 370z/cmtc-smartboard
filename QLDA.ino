#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <mysql.h>

char *host, *user, *pass, *db;

// WiFi parameters
const char* ssid = "Xiaomi 11T";
const char* password = "qwerty12345";
 HTTPClient http;
//host to send data
//String host= "http://192.168.124.40/QLDA/Getstatus.php";
void setup() {
  pinMode(4,OUTPUT);
  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
delay(3000);
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  host = "localhost";
  user = "root";
  pass = "";
  db = "qlda";
  if(mysql_connect(host,user,pass,db){
   
    Serial.print("Connected to ");
    Serial.println(host);
    int result = mysql_result_query("SELECT FROM `sensors` WHERE `id` = 1", "value");
    if(result){
      Serial.print("Value of the sensor is:");
      Serial.println(result);
    }else{
      Serial.println("Query exexcution failed or no record(s) found.");
    }
  }else{
    Serial.println("Connection failed.");
  }
  
}
void loop() {
  
//  http.begin(host);
//  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
//  int httpCode=http.GET();
//  String payload=http.getString(); // get data from webhost continously
//  Serial.print(payload);
//  if(payload == "1")  // if data == 1 -> LED ON
//  {
//    digitalWrite(4,HIGH);
//    }
//   else if (payload == "0") // if data == 0 -> LED OFF
//   {
//    digitalWrite(4,LOW);
//    }
//  delay(500);
//   http.end();

}
