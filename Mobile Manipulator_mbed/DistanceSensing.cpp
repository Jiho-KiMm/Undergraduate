#include "DistanceSensing.h"

DistanceSensor::DistanceSensor(): InfraredSensor1_(A0), InfraredSensor2_(A3)
{
    adc1 = 0;
    volts1 = 0;
    distance1 = 0;

    adc2 = 0;
    volts2 = 0;
    distance2 = 0;
}

void DistanceSensor::DistanceCalculation1()
{
    adc1 = InfraredSensor1_.read_u16();
    volts1 = adc1*5./1023.;
    distance1 = 12.08*pow(volts1,-1.08);  
}

void DistanceSensor::DistanceCalculation2()
{
    adc2 = InfraredSensor2_.read_u16();
    volts2 = adc2*5./1023.;
    distance2 = 12.08*pow(volts2,-1.08);  
}

double DistanceSensor::GetDistance1()
{
  return distance1*100;
}

double DistanceSensor::GetDistance2()
{
  return distance2*100;
}