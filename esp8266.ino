#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "example.firebaseio.com"
#define FIREBASE_AUTH "token_or_secret"
#define WIFI_SSID "SSID"
#define WIFI_PASSWORD "PASSWORD"

void setup() {
  pinMode(2,OUTPUT);
//-----------communications-------------------- 
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
    while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
    }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
 // here we set lampStatus as a String because MIT APP Intentor gives us Strings.
  String lampStatus = Firebase.getString("lamp");
  Serial.print("Lamp Status = "); Serial.println(lampStatus);
    if(lampStatus == "1")
    digitalWrite(2,HIGH);
    else
    digitalWrite(2,LOW);
}
