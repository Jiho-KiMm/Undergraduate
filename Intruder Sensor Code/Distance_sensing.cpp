#include "arduino.h"
#include "Distance_sensing.h"

DistanceSens::DistanceSens(int pin_T, int pin_E)
{
  pin_Trig = pin_T;
  pin_Echo = pin_E;
  pinMode(pin_Trig, OUTPUT);
  pinMode(pin_Echo, INPUT);
}

void DistanceSens::SensorD()
{
  digitalWrite(pin_Trig,LOW);
  delayMicroseconds(2);
  digitalWrite(pin_Trig,HIGH);
  delayMicroseconds(5);
  digitalWrite(pin_Trig,LOW);
}

void DistanceSens::Check()
{
  Serial.print("d = "); 
  Serial.println(distance);
}