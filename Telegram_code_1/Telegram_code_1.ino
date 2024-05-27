#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>


LiquidCrystal_I2C lcd (0x27, 16, 2);
const char* ssid = "Gokulkavi";
const char* password = "gokul2309";


#define BOTtoken "6519782351:AAE4MZOpXG5vdoCCO3tZjCgZiSRMRej6W8w"
#define CHAT_ID "6808333067"

int pin_rec   = 0; // GPIO 0
int pin_playe = 1; // GPIO 1
int value = 0;

//#define Sensor D0
//#define LEDR D3
//#define LEDG D4
//#define Buzzer D5

X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);


void setup() {
  Serial.begin(115200);
  //lcd.init();
  //lcd.backlight();
 // Wire.begin(D2, D1);
  configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
  client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org

  //pinMode(Sensor, INPUT);
  //pinMode(LEDR, OUTPUT);
 // pinMode(LEDG, OUTPUT);
 // pinMode(Buzzer, OUTPUT);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  int a = 0;
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    //lcd.setCursor(a, 0);
    //lcd.print(".");
    //delay(500);
    a++;
  }

 // Serial.println("");
 // lcd.clear();
 // lcd.setCursor(0, 0);
 // lcd.print("WiFi connected");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
 // lcd.setCursor(0, 1);
 // lcd.print(WiFi.localIP());
  Serial.println(WiFi.localIP());
  delay(500);

  bot.sendMessage(CHAT_ID, "System started", "");
 // lcd.clear();
 // lcd.setCursor(0, 0);
 // lcd.print("System started");
  delay(1000);
  //lcd.clear();
}
void loop() {
 
  {
  delay(5000);
  digitalWrite(pin_rec, HIGH);
  delay(10000);
  digitalWrite(pin_rec, LOW);
  delay(5000);
  digitalWrite(pin_playe, HIGH);
  delay(100);
  digitalWrite(pin_playe, LOW);
  delay(20000);
}  
 
  //bool value = digitalRead(Sensor);
  //Serial.println(value);
  if (pin_rec == 1) {
   // Serial.println("Motion Detected");
    //digitalWrite(LEDR, HIGH);
    //digitalWrite(Buzzer, HIGH);
    //digitalWrite(LEDG, LOW);
   // lcd.setCursor(0, 0);
   // lcd.print("Motion Detected");
    //bot.sendMessage(CHAT_ID, pin_rec);
  } else if (value == 0) {
   // digitalWrite(LEDR, LOW);
    //digitalWrite(Buzzer, LOW);
    //digitalWrite(LEDG, HIGH);
  //  lcd.setCursor(0, 0);
   // lcd.print("No Motion      ");
  }
}
