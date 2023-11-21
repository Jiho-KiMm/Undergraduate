#include <Servo.h>
class ChangeSound
{
  Servo SoundControlServo;
  int pin;
  int flag_motor;
public:
  ChangeSound();
  void attach(int pin);
  void GetChangeValue();
};