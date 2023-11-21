#include "mbed.h"

class MovingServo
{
private:
    PwmOut servo;
    float ang;
    float inc;
    float incc;
    float ang__;
    
    void turn(PwmOut &rc,float deg)
    {
        uint16_t pulseW=map<float>(deg,0.,180.,600.,2400.);
        servo.pulsewidth_us(pulseW);
    }
    template <class T>
    T map(T x, T in_min, T in_max, T out_min, T out_max)
    {
        return (x - in_min) * (out_max - out_min)/ (in_max - in_min) + out_min;
    }

public:
   
    MovingServo(PinName pin, float ang_, float inc_): servo(pin)
    {
        ang = ang_;
        ang__ = 0;
        inc = inc_;
        incc = -inc;
        servo.period_ms(10);  
    }      


    void Turn0To180()
    {
        ang__ = ang += inc;
        turn(servo, ang__);
    }

    void Turn180To0()
    {
        ang__ = ang += incc;
        turn(servo, ang__);
    }

    void WantedAngle(int angle_)
    {
        ang = angle_;
        turn(servo, ang);
    }


};