typedef enum{OFF, ON} STATE;
class LEDBlinker
{
  int pin;
  STATE state;
  long onTime, offTime;
  uint32_t prevMillis;
public:
  LEDBlinker(int pinN, long OnT, long OffT, unsigned long p_M);
  void justLED(int state);
  void Blink(); 
};