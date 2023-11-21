#include "arduino.h"
#include "MovingServoControl.h"

MovingServo::MovingServo(float ang_, float inc_)
{
  ang = ang_;
  inc = inc_;
  incc = -inc;
}

void MovingServo::attach(int pin)
{
  ServoManipulator.attach(pin);
  ServoManipulator.write(ang);
}

void MovingServo::Turn0To180()
{
  ServoManipulator.write(min(ang += inc, 180));
}

void MovingServo::Turn180To0()
{
  ServoManipulator.write(max(ang += incc, 0));    
}

void MovingServo::WantedAngle(int angle_)
{
  ang = angle_;
  ServoManipulator.write(ang);    
}