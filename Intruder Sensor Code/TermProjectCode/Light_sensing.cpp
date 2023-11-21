#include "arduino.h"
#include "Light_sensing.h"

Lightsensing::Lightsensing()
{
  pinMode(cds, INPUT);
}
void Lightsensing::SensorL()
{
  Sensor_Light_value = analogRead(A0);
}
float Lightsensing::CheckLightvalue()
{
  return Sensor_Light_value;
}
void Lightsensing::CheckLight()
{
  Serial.print("Light = ");
  Serial.println(Sensor_Light_value);
}