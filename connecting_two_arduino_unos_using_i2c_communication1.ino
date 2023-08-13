//Transmitter


#include <Wire.h>
int pushButton = A0;
int x = 0;
void setup()
{
  Wire.begin();
  pinMode(pushButton, INPUT);
}

void loop()
{
   Wire.beginTransmission(1);
   x = digitalRead(pushButton);
   Wire.write(x);
   Wire.endTransmission();
   delay(100);
}



//Receiver


#include <Wire.h>
int pinLed=11;
int x =0;

void setup()
{
  Wire.begin(1);
  Wire.onReceive(receiveEvent); 
  pinMode(pinLed, OUTPUT);
}

void loop()
{
  delay(100);
}

void receiveEvent(int howMany){

x = Wire.read();
  
  if (x == 1){
  
        digitalWrite(pinLed,HIGH);
  }
  else{
        digitalWrite(pinLed,LOW);
  }
}
