#include "mbed.h"

#define InfraredSensor1 A0
#define InfraredSensor2 A3

class DistanceSensor
{
private:
    AnalogIn InfraredSensor1_;
    AnalogIn InfraredSensor2_;

    int adc1;
    double volts1;
    double distance1;

    int adc2;
    double volts2;
    double distance2;

public:
  DistanceSensor();

  void DistanceCalculation1();
  double GetDistance1();

  void DistanceCalculation2();
  double GetDistance2();

};