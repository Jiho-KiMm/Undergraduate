#include "arduino.h"
#include "DistanceSensing.h"

DistanceSensor::DistanceSensor()
{
  adc1 = 0;
  volts1 = 0;
  distance1 = 0;

  adc2 = 0;
  volts2 = 0;
  distance2 = 0;

  pinMode(InfraredSensor1, INPUT);
  pinMode(InfraredSensor2, INPUT);
}

void DistanceSensor::DistanceCalculation1()
{
  adc1 = analogRead(InfraredSensor1);
  volts1 = adc1*5./1023.;
  distance1 = 12.08*pow(volts1,-1.08);  
}

void DistanceSensor::DistanceCalculation2()
{
  adc2 = analogRead(InfraredSensor2);
  volts2 = adc2*5./1023.;
  distance2 = 12.08*pow(volts2,-1.08);  
}

double DistanceSensor::GetDistance1()
{
  return distance1;
}

double DistanceSensor::GetDistance2()
{
  return distance2;
}