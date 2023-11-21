#include "arduino.h"
#include "LED_Blink.h"

LEDBlinker::LEDBlinker(int pinN, long OnT, long OffT, unsigned long p_M)
{
  pin = pinN;
  pinMode(pin, OUTPUT);
  onTime = OnT;
  offTime = OffT;
  state = OFF;
  prevMillis = p_M;
}

void LEDBlinker::justLED(int state)
{
  digitalWrite(pin, state);
}

void LEDBlinker::Blink() { 
  unsigned long curMillis = millis();
  if (state==ON)
  {
    if(curMillis - prevMillis >= onTime) 
    {
      state = OFF;
      prevMillis = curMillis;
      digitalWrite(pin, state);
    }
  }
  else{
    if (curMillis - prevMillis >= offTime) 
    { 
      state = ON;
      prevMillis = curMillis;
      digitalWrite(pin, state);
    }
  }
}