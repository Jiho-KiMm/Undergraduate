#include "arduino.h"
#include "Sound.h"

Sound::Sound(int pin_Siren_)
{
  pin_Siren = pin_Siren_;
  pinMode(pin_Siren, OUTPUT);
}
void Sound::MakeANoise()
{
  tone(pin_Siren, map(analogRead(POT),0,1023,0,3000));
}
void Sound::StopNoise()
{
  noTone(pin_Siren);
}