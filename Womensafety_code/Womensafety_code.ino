   
#include <SoftwareSerial.h>
#include <TinyGPS++.h>
SoftwareSerial mySerial(6,7);

#include <LiquidCrystal.h>
const int rs=13, en = 12, d4 = 11, d5 = 1



0, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int buttonPin = 2;     // the number of the pushbutton pin

const int buzzer =  5;      // the number of the LED pin
int PowerPin = 4; 
int buttonState = 0; 

static const int RXPin = 0, TXPin = 1;
static const uint32_t gps_baudrate = 9600;
TinyGPSPlus gps;
SoftwareSerial soft(RXPin, TXPin);
String textMessage;
float Lat, Lon;

void setup()
{
mySerial.begin(9600); // Setting the baud rate of GSM Module
Serial.begin(9600); // Setting the baud rate of Serial Monitor (Arduino)
soft.begin(gps_baudrate);
pinMode(buttonPin,INPUT);
pinMode(buzzer, OUTPUT);
pinMode(PowerPin, OUTPUT);     
digitalWrite(PowerPin, HIGH); 
lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print ("WOMEN SAFETY");
lcd.setCursor(2,1);
lcd.print ("PROJECT");
delay(3000);
lcd.clear();
}
 
void loop()
{
buttonState = digitalRead(buttonPin);

gps.encode(soft.read());
    if (gps.location.isUpdated())
    {
      Lat = gps.location.lat();
      Lon = gps.location.lng();
    }
   
if(buttonState == 1)
{
  
    digitalWrite(buzzer,HIGH);
     MakeCall1();
     delay(7000);
     MakeCall();
     delay(7000);
    SendMessage();
    delay(7000);
    SendMessage1();
    Serial.print("EMERGENCY!!!!!");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("EMERGENCY!!!!!");
    lcd.setCursor(0,1);
    lcd.print("SMS/CallingSend");
    Serial.println("Received");
  
    }
   
else
{
digitalWrite(buzzer,LOW);
Serial.println("Normal State");
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Normal State");
delay(1000);
String data= String(buttonState)+"@";
Serial.println(data);
} 
}
 
void SendMessage()
{
Serial.println("Help Me I am in Trouble!!!");
mySerial.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
delay(1000); // Delay of 1000 milli seconds or 1 second
mySerial.println("AT+CMGS=\"+918778413830\"\r"); // Replace x with mobile number
delay(1000);
mySerial.println("I want Help !!!Location:" + String("Lat: ") +String(Lat) + " "+String("Lon: ") + String(Lon));
mySerial.println((char)26);// ASCII code of CTRL+Z
delay(1000);
}
void SendMessage1()
{
Serial.println("Help Me I am in Trouble!!!");
mySerial.println("AT+CMGF=2"); //Sets the GSM Module in Text Mode
delay(1000); // Delay of 1000 milli seconds or 1 second
mySerial.println("AT+CMGS=\"+916380279596\"\r"); // Replace x with mobile number
delay(1000);
mySerial.println("Help Me I am in Trouble !!!Location:" + String("Lat: ") +String(Lat) + " "+String("Lon: ") + String(Lon));
mySerial.println((char)26);// ASCII code of CTRL+Z
delay(1000);
}
void MakeCall()
{
  mySerial.println("ATH");
  delay(1000);
  mySerial.println("ATD+918778413830;"); // ATDxxxxxxxxxx; -- watch out here for semicolon at the end!!
  delay(1000);
  mySerial.println("Calling  "); // print response over serial port
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("CALLING");
  lcd.setCursor(0, 1);
  lcd.print("+918778413830");
  Serial.println("918778413830");
}
void MakeCall1()
{
  mySerial.println("ATH");
  delay(1000);
  mySerial.println("ATD+916380279596;"); // ATDxxxxxxxxxx; -- watch out here for semicolon at the end!!
  delay(1000);
  mySerial.println("Calling  "); // print response over serial port
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("CALLING");
  lcd.setCursor(0, 1);
  lcd.print("+916380279596");
  Serial.println("6380279596");
}
