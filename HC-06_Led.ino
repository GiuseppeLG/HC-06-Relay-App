// HC-06 with Arduino and LED
#include <SoftwareSerial.h>
#define rele1 9
#define rele2 10
int rxPin = 3;
int txPin = 2;

SoftwareSerial bluetooth(rxPin, txPin);

String message; //string that stores the incoming message


void setup()
{
  Serial.begin(9600); //set baud rate
  bluetooth.begin(9600); //set baud rate
  pinMode(rele1, OUTPUT); 
  pinMode(rele2, OUTPUT);
}

void loop()
{
  while(bluetooth.available()){
    message+=char(bluetooth.read());
  
  }
  if(!bluetooth.available())
  {
    if(message!="")
    {//if data is available
      if(message == "1"){
          digitalWrite(rele1, HIGH);
          Serial.println("rele1 OFF"); //show the data
          delay(20);
          message=""; //clear the data
       }
       else if(message == "o"){
          digitalWrite(rele1, LOW);
          Serial.println("rele1 ON"); //show the data
          delay(20);
          message=""; //clear the data
       }
         else if(message == "2"){
          digitalWrite(rele2, HIGH);
          Serial.println("rele2 OFF"); //show the data
          delay(20);
          message=""; //clear the data
       }
         else if(message == "p"){
          digitalWrite(rele2, LOW);
          Serial.println("rele2 ON"); //show the data
          delay(20);
          message=""; //clear the data
       }
       message="";
    }
  }
}
