#include "mbed.h"

class MovingMotor
{
private:
    PwmOut RightMotor_E_pin;
    PwmOut LeftMotor_E_pin;
    DigitalOut RightMotor_1_pin;
    DigitalOut RightMotor_2_pin;
    DigitalOut LeftMotor_3_pin;
    DigitalOut LeftMotor_4_pin;
    double Speed;


public:
    MovingMotor(PinName pin1, PinName pin2, PinName pin3, PinName pin4, PinName pin5, PinName pin6): RightMotor_E_pin(pin1), LeftMotor_E_pin(pin2), RightMotor_1_pin(pin3), RightMotor_2_pin(pin4), LeftMotor_3_pin(pin5), LeftMotor_4_pin(pin6)
    {
        Speed = 0;
    }

    void GoStraight(double Speed_)
    {
        Speed = Speed_;
        RightMotor_1_pin = 1;
        RightMotor_2_pin = 0;
        LeftMotor_3_pin = 1;
        LeftMotor_4_pin = 0;

        RightMotor_E_pin = Speed;
        LeftMotor_E_pin = Speed;
    }

    void GoBack(double Speed_)
    {
        Speed = Speed_;

        RightMotor_1_pin = 0;
        RightMotor_2_pin = 1;
        LeftMotor_3_pin = 0;
        LeftMotor_4_pin = 1;

        RightMotor_E_pin = Speed;
        LeftMotor_E_pin = Speed;
    }

    void TurnRight(double Speed_)
    {
        Speed = Speed_;
        
        RightMotor_1_pin = 0;
        RightMotor_2_pin = 1;
        LeftMotor_3_pin = 1;
        LeftMotor_4_pin = 0;

        RightMotor_E_pin = Speed;
        LeftMotor_E_pin = Speed;
    }

    void TurnLeft(double Speed_)
    {
        Speed = Speed_;
        
        RightMotor_1_pin = 1;
        RightMotor_2_pin = 0;
        LeftMotor_3_pin = 0;
        LeftMotor_4_pin = 1;

        RightMotor_E_pin = Speed;
        LeftMotor_E_pin = Speed;
    }

    void StopMoving()
    {
        MovingMotor::GoStraight(0);
    }

};