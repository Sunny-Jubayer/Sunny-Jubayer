#include <SoftwareSerial.h>
int RX_pin = 4;
int TX_pin = 2;
int msensor = 4; // moisture sensor is connected with digital pin4 of the Arduino
int pump = 12;
boolean flag = false;
SoftwareSerial BTserial (RX_pin, TX_pin);
String BT_data ;
String Arduino_data;

void setup ()
{
  Serial.begin(9600);
   BTserial.begin(9600);
    pinMode(relay, OUTPUT);
     Serial.begin(9600);
  pinMode(msensor, INPUT);
  pinMode(pump, OUTPUT);  

}

void loop(){
 
if ( (digitalRead(msensor) == HIGH  ) && ( flag == false ) )
{
  digitalWrite(pump, HIGH);  
  flag = true;
  delay(1000);
}
 
  if ( (digitalRead(msensor) == LOW  ) && ( flag == true ) )
{
  digitalWrite(pump, LOW);
  flag = false;
  delay(1000);
}
 
 
  delay(1000);  

digitalWrite(relay, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(2000);                       // wait for a second
  digitalWrite(relay, LOW);    // turn the LED off by making the voltage LOW
  delay(200000);
{
 if (BTserial.available())
 {
  BT_data = BTserial.readString ();
  Serial.println(BT_data);
 }
 if (Serial.available())
 {
  Arduino_data = Serial.readString();
  BTserial.println(Arduino_data);
 }
}
