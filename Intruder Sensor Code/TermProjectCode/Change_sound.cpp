#include "arduino.h"
#include "Change_sound.h"

ChangeSound::ChangeSound()
{
    flag_motor = 0;
}
void ChangeSound::attach(int pin)
{
  SoundControlServo.attach(pin);
}
void ChangeSound::GetChangeValue()
{
    
  if(flag_motor == 0)
  {
    SoundControlServo.write(90);
    flag_motor = 1;
  }
  if(Serial.available()>0)
  {
    int Get_value = Serial.parseInt();
    Serial.println(Get_value);
    if(Get_value == 0||1||2)
    {        
      if(Get_value == 2)  SoundControlServo.write(1);
      if(Get_value == 1)  SoundControlServo.write(90);
      if(Get_value == 0)  SoundControlServo.write(179);
    }
    else 
    {
      Serial.println("Invaild Input// Please type again");
    }
  }
}