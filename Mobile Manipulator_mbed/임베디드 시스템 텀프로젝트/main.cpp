#include "mbed.h"
#include "DistanceSensing.h"
#include "MovingServoControl.h"
#include "MovingMotorControl.h"
#include "Adafruit_SSD1306.h"


#define bluetoothTX D2
#define bluetoothRX D10
int datain = 0;
int datain_1 = 0;
bool flag = 1;

//Class
I2C i2c(I2C_SDA, I2C_SCL); 
Adafruit_SSD1306_I2c display(i2c, D2, 0x78, 64, 128);

DistanceSensor InfraredSens;
MovingServo ServoMotor1(D4, 90, 4);
MovingServo ServoMotor2(D7, 179, 4);
MovingServo ServoMotor3(D12, 179, 4);
MovingServo ServoMotor4(D13, 179, 20);
MovingMotor DCmotor(D5, D6, D8, D9, D11, D3);
Serial bt(bluetoothRX, bluetoothTX);
//..........................................

//OLED Diplay
void NormalState();
void DangerousState();
void WarningState();

int Oled_x = 0;
float Oled_inc = 0.0f;
float Oled_force = 1.0f;
//.....................................

void ServoControl(int datain_);


int main()
{
     bt.baud(9600);
    ServoMotor1.WantedAngle(90);
    ServoMotor2.WantedAngle(179);
    ServoMotor3.WantedAngle(179);
    ServoMotor4.WantedAngle(179);

    while(1)
    {      
        NormalState();

        if(bt.readable())
        {
            datain = bt.getc();

            ServoControl(datain);

            if(datain == 9)
            {
                while(1)
                {
                    DCmotor.GoStraight(0.5);
                    NormalState();
                    InfraredSens.DistanceCalculation1();


                    if(InfraredSens.GetDistance1() < 7)
                    {
                        while(1)
                        {
                            DangerousState();
                            InfraredSens.DistanceCalculation1();

                            DCmotor.StopMoving();

                            if(bt.readable())
                            {
                                datain_1 = bt.getc();

                                ServoControl(datain_1);

                                if(datain_1 == 10)
                                {

                                    while(1)
                                    {
                                        DCmotor.GoBack(0.5);
                                        NormalState();

                                        if(bt.readable())
                                        {
                                            break;
                                        }
                                    }
                                }

                                if(datain_1 == 11)
                                {

                                    while(1)
                                    {
                                        DCmotor.TurnRight(0.8);
                                        NormalState();
  
                                        if(bt.readable())
                                        {
                                            break;
                                        }
                                    }
                                }

                                if(datain_1 == 12)
                                {

                                    while(1)
                                    {
                                        DCmotor.TurnLeft(0.8);
                                        NormalState();

                                        if(bt.readable())
                                        {
                                            break;
                                        }
                                    }
                                }
                            }

                            if(InfraredSens.GetDistance1() > 7)
                            {
                                flag = 0;
                                break;
                            }
                        }
                    }

                    if(bt.readable() > 0 || flag == 0)
                    {
                        DCmotor.StopMoving();
                        flag = 1;
                        break;
                    }
                }
            }

            if(datain == 10)
            {
                while(1)
                {
                    DCmotor.GoBack(0.5);
                    NormalState();
                    InfraredSens.DistanceCalculation2();


                    if(InfraredSens.GetDistance2() < 7)
                    {
                        while(1)
                        {
                            DangerousState();
                            InfraredSens.DistanceCalculation2();

                            DCmotor.StopMoving();

                            if(bt.readable())
                            {
                                datain_1 = bt.getc();

                                ServoControl(datain_1);

                                if(datain_1 == 9)
                                {
                                    while(1)
                                    {
                                        DCmotor.GoStraight(0.5);
                                        NormalState();

                                        if(bt.readable())
                                        {
                                            break;
                                        }
                                    }
                                }

                                if(datain_1 == 11)
                                {
                                    while(1)
                                    {
                                        DCmotor.TurnRight(0.8);
                                        NormalState();

                                        if(bt.readable())
                                        {
                                            break;
                                        }
                                    }
                                }

                                if(datain_1 == 12)
                                {
                                    while(1)
                                    {
                                        DCmotor.TurnLeft(0.8);
                                        NormalState();

                                        if(bt.readable())
                                        {
                                            break;
                                        }
                                    }
                                }
                            }

                            if(InfraredSens.GetDistance2() > 7)
                            {
                                flag = 0;
                                break;
                            }
                        }
                    }

                    if(bt.readable() > 0 || flag == 0)
                    {
                        DCmotor.StopMoving();
                        flag = 1;
                        break;
                    }
                }
            }

            if(datain == 11)
            {
                while(1)
                {
                    DCmotor.TurnRight(0.8);
                    NormalState();
                    InfraredSens.DistanceCalculation1();


                    if(InfraredSens.GetDistance1() < 7)
                    {
                        while(1)
                        {
                            DangerousState();
                            InfraredSens.DistanceCalculation1();
                            DCmotor.StopMoving();

                            if(bt.readable())
                            {
                                datain_1 = bt.getc();

                                ServoControl(datain_1);

                                if(datain_1 == 10)
                                {
                                    while(1)
                                    {
                                        DCmotor.GoBack(0.5);
                                        NormalState();

                                        if(bt.readable())
                                        {
                                            break;
                                        }
                                    }
                                }

                                if(datain_1 == 12)
                                {
                                    while(1)
                                    {
                                        DCmotor.TurnLeft(0.8);
                                        NormalState();

                                        if(bt.readable())
                                        {
                                            break;
                                        }
                                    }
                                }
                            }

                            if(InfraredSens.GetDistance1() > 7)
                            {
                                flag = 0;
                                break;
                            }
                        }
                    }

                    if(bt.readable() > 0 || flag == 0)
                    {
                        DCmotor.StopMoving();
                        flag = 1;
                        break;
                    }
                }
            }

            if(datain == 12)
            {
                while(1)
                {
                    DCmotor.TurnLeft(0.8);
                    NormalState();
                    InfraredSens.DistanceCalculation1();


                    if(InfraredSens.GetDistance1() < 7)
                    {
                        while(1)
                        {
                            DangerousState();
                            InfraredSens.DistanceCalculation1();
                            DCmotor.StopMoving();

                            if(bt.readable())
                            {
                                datain_1 = bt.getc();

                                ServoControl(datain_1);

                                if(datain_1 == 10)
                                {
                                    while(1)
                                    {
                                        DCmotor.GoBack(0.5);
                                        NormalState();

                                        if(bt.readable())
                                        {
                                            break;
                                        }
                                    }
                                }

                                if(datain_1 == 11)
                                {
                                    while(1)
                                    {
                                        DCmotor.TurnRight(0.8);
                                        NormalState();

                                        if(bt.readable())
                                        {
                                            break;
                                        }
                                    }
                                }
                            }
                            if(InfraredSens.GetDistance1() > 7)
                            {
                                flag = 0;
                                break;
                            }
                        }
                    }

                    if(bt.readable() > 0 || flag == 0)
                    {
                        DCmotor.StopMoving();
                        flag = 1;
                        break;
                    }
                }
            }
         
        }
    }

}


void NormalState()
{
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setTextCursor(0,0);
    display.printf("Moving\n");
    display.fillRect(0, 19, 128, 12, BLACK);
    display.drawRect(Oled_x, 30, 30, 30, WHITE);
    display.display();

    Oled_inc += 0.1f*Oled_force;
    Oled_x += Oled_inc;
    if(Oled_x > 118 || Oled_x < 0)
    {
        Oled_force = -Oled_force;
        Oled_inc = 0.0f;
    }        
}

void DangerousState()
{
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setTextCursor(0,0);
    display.printf("Dangerous!");
    display.fillRect(0, 19, 128, 12, BLACK);
    display.fillRect(80, 25, 10, 40, WHITE);
    display.drawRect(Oled_x, 30, 30, 30, WHITE);
    display.display();

    Oled_inc += 0.1f*Oled_force;
    Oled_x += Oled_inc;
    if(Oled_x > 50 || Oled_x < 0)
    {
        Oled_force = -Oled_force;
        Oled_inc = 0.0f;
    }    
}

void WarningState()
{
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setTextCursor(10,30);
    display.printf("!Warning!");    
    display.display();
}

void ServoControl(int datain_)
{
    if(datain_ == 1)
    {
        while(1)
        {
            ServoMotor1.Turn180To0();
            WarningState();

            if(bt.readable())
            {
                break;
            }
        }
    }

    if(datain_ == 2)
    {
        while(1)
        {
            ServoMotor1.Turn0To180();
            WarningState();

            if(bt.readable())
            {
                break;
            }
        }
    }

    if(datain_ == 3)
    {
        while(1)
        {
            ServoMotor2.Turn0To180();
            WarningState();

            if(bt.readable())
            {
                break;
            }
        }
    }

    if(datain_ == 4)
    {
        while(1)
        {
            ServoMotor2.Turn180To0();
            WarningState();

            if(bt.readable())
            {
                break;
            }
        }
    }

    if(datain_ == 5)
    {
        while(1)
        {
            ServoMotor3.Turn180To0();
            WarningState();

            if(bt.readable())
            {
                break;
            }
        }
    }

    if(datain_ == 6)
    {
        while(1)
        {
            ServoMotor3.Turn0To180();
            WarningState();

            if(bt.readable())
            {
                break;
            }
        }
    }

    if(datain_ == 7)
    {
        while(1)
        {
            ServoMotor4.Turn180To0();
            WarningState();

            if(bt.readable())
            {
                break;
            }
        }
    }

    if(datain_ == 8)
    {
        while(1)
        {
            ServoMotor4.Turn0To180();
            WarningState();

            if(bt.readable())
            {
                break;
            }
        }
    }

    if(datain_ == 13)
    {
        ServoMotor1.WantedAngle(90);
        ServoMotor2.WantedAngle(179);
        ServoMotor3.WantedAngle(179);
        ServoMotor4.WantedAngle(179);
    }
}