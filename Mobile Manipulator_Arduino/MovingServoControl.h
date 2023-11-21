#include <Servo.h>

class MovingServo
{
private:
  Servo ServoManipulator;
  int pin;
  float ang;
  float inc;
  float incc;  

public:
  MovingServo(float ang_, float inc_);
  void attach(int pin);
  void Turn0To180();
  void Turn180To0();
  void WantedAngle(int angle_);
};