class DistanceSens
{
  int pin_Trig, pin_Echo;
  int dt_us = 0;
  int distance = 0;
public:
  DistanceSens(int pin_T, int pin_E);
  void SensorD();
  void Check();
};