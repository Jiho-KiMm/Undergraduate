#include <Servo.h>
#include <SoftwareSerial.h>
#include "Wire.h"
#include <Adafruit_GFX.h>        
#include <Adafruit_SSD1306.h> 
#include "MovingMotorControl.h"
#include "DistanceSensing.h"
#include "LEDBlinker.h"
#include "MovingServoControl.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET 4

// Button namenumber 역할
// Servo1    1       1번모터 정회전
// Servo1    2       1번모터 역회전
// Servo2    3       2번모터 정회전
// Servo2    4       2번모터 역회전
// Servo3    5       3번모터 정회전
// Servo3    6       3번모터 역회전
// Servo4    7       4번모터 정회전
// Servo4    8       4번모터 역회전

// DCmotor   9       전진
// DCmotor   10      후진
// DCmotor   11      우회전
// DCmotor   12      좌회전

// Reset     13      서보모터 초기자세

//Initialize
int bluetoothTX = 12;
int bluetoothRX = 13;
int datain = 0;
int datain_1 = 0;
int m = 0;
bool flag = 1;

SoftwareSerial bluetooth(bluetoothTX, bluetoothRX);
//................................

//OLED Diplay
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int Oled_x = 0;
float Oled_inc = 0.0f;
float Oled_force = 1.0f;

void NormalState();
void DangerousState();
void WarningState();
//.....................................

void ServoControl(int datain_);

//Class
LEDBlinker LED(90, 900, 0, 80, 920, 0);
MovingMotor DCmotor(5, 6, 8, 9, 10, 11);
DistanceSensor InfraredSens;
MovingServo Servo1(90, 1);
MovingServo Servo2(179, 1);
MovingServo Servo3(179, 1);
MovingServo Servo4(179, 20);
//..........................................

//main
void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Servo1.attach(2);
  Servo2.attach(3);
  Servo3.attach(4);
  Servo4.attach(7);
  
}
    
void loop() {
  NormalState();
  LED.justLED1(255);
  
  if(bluetooth.available() > 0)
  {
    datain = bluetooth.read();

    ServoControl(datain);
    
    //DCmotor Control
    if(datain == 9)
    {
      LED.justLED1(0);
      while(1)
      {
        DCmotor.GoStraight(130);
        NormalState();
        InfraredSens.DistanceCalculation1();
        
        LED.justLED2(255);

        if(InfraredSens.GetDistance1() < 7)
        {
          LED.justLED2(0);
          while(1)
          {
            DangerousState();
            InfraredSens.DistanceCalculation1();
            LED.Blink1();
            LED.Blink2();
            DCmotor.StopMoving();

            if(bluetooth.available() > 0)
            {
              datain_1 = bluetooth.read();
              
              ServoControl(datain_1);

              if(datain_1 == 10)
              {
                while(1)
                {
                  DCmotor.GoBack(130);
                  NormalState();
                  LED.justLED2(255);

                  if(bluetooth.available() > 0)
                  {
                    break;
                  }
                }
              }

              if(datain_1 == 11)
              {
                while(1)
                {
                  DCmotor.TurnRight(130);
                  NormalState();
                  LED.justLED2(255);

                  if(bluetooth.available() > 0)
                  {
                    break;
                  }
                }
              }

              if(datain_1 == 12)
              {
                while(1)
                {
                  DCmotor.TurnLeft(130);
                  NormalState();
                  LED.justLED2(255);

                  if(bluetooth.available() > 0)
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

        if(bluetooth.available() > 0 || flag == 0)
        {
          LED.justLED2(0);
          DCmotor.StopMoving();
          flag = 1;
          break;
        }
      }
    }

    if(datain == 10)
    {
      LED.justLED1(0);
      while(1)
      {
        DCmotor.GoBack(130);
        NormalState();
        InfraredSens.DistanceCalculation2();
        
        LED.justLED2(255);

        if(InfraredSens.GetDistance2() < 6)
        {
          LED.justLED2(0);
          while(1)
          {
            DangerousState();
            InfraredSens.DistanceCalculation2();
            LED.Blink1();
            LED.Blink2();
            DCmotor.StopMoving();

            if(bluetooth.available() > 0)
            {
              datain_1 = bluetooth.read();

              ServoControl(datain_1);
              
              if(datain_1 == 9)
              {
                while(1)
                {
                  DCmotor.GoStraight(130);
                  NormalState();
                  LED.justLED2(255);

                  if(bluetooth.available() > 0)
                  {
                    break;
                  }
                }
              }

              if(datain_1 == 11)
              {
                while(1)
                {
                  DCmotor.TurnRight(130);
                  NormalState();
                  LED.justLED2(255);

                  if(bluetooth.available() > 0)
                  {
                    break;
                  }
                }
              }

              if(datain_1 == 12)
              {
                while(1)
                {
                  DCmotor.TurnLeft(130);
                  NormalState();
                  LED.justLED2(255);

                  if(bluetooth.available() > 0)
                  {
                    break;
                  }
                }
              }
            }            

            if(InfraredSens.GetDistance2() > 6)
            {
              flag = 0;
              break;
            }
          }
        }

        if(bluetooth.available() > 0 || flag == 0)
        {
          LED.justLED2(0);
          DCmotor.StopMoving();
          flag = 1;
          break;
        }
      }
    }

    if(datain == 11)
    {
      LED.justLED1(0);
      while(1)
      {
        DCmotor.TurnRight(130);
        NormalState();
        InfraredSens.DistanceCalculation1();
        
        LED.justLED2(255);

        if(InfraredSens.GetDistance1() < 7)
        {
          LED.justLED2(0);
          while(1)
          {
            DangerousState();
            InfraredSens.DistanceCalculation1();
            LED.Blink1();
            LED.Blink2();
            DCmotor.StopMoving();

            if(bluetooth.available() > 0)
            {
              datain_1 = bluetooth.read();

              ServoControl(datain_1);
              
              if(datain_1 == 10)
              {
                while(1)
                {
                  DCmotor.GoBack(130);
                  NormalState();
                  LED.justLED2(255);

                  if(bluetooth.available() > 0)
                  {
                    break;
                  }
                }
              }

              if(datain_1 == 12)
              {
                while(1)
                {
                  DCmotor.TurnLeft(130);
                  NormalState();
                  LED.justLED2(255);

                  if(bluetooth.available() > 0)
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

        if(bluetooth.available() > 0 || flag == 0)
        {
          LED.justLED2(0);
          DCmotor.StopMoving();
          flag = 1;
          break;
        }
      }
    }

    if(datain == 12)
    {
      LED.justLED1(0);
      while(1)
      {
        DCmotor.TurnLeft(130);
        NormalState();
        InfraredSens.DistanceCalculation1();
        
        LED.justLED2(255);


        if(InfraredSens.GetDistance1() < 7)
        {
          LED.justLED2(0);
          while(1)
          {
            DangerousState();
            InfraredSens.DistanceCalculation1();
            LED.Blink1();
            LED.Blink2();
            DCmotor.StopMoving();

            if(bluetooth.available() > 0)
            {
              datain_1 = bluetooth.read();

              ServoControl(datain_1);
              
              if(datain_1 == 10)
              {
                while(1)
                {
                  DCmotor.GoBack(130);
                  NormalState();
                  LED.justLED2(255);

                  if(bluetooth.available() > 0)
                  {
                    break;
                  }
                }
              }

              if(datain_1 == 11)
              {
                while(1)
                {
                  DCmotor.TurnRight(130);
                  NormalState();
                  LED.justLED2(255);

                  if(bluetooth.available() > 0)
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

        if(bluetooth.available() > 0 || flag == 0)
        {
          LED.justLED2(0);
          DCmotor.StopMoving();
          flag = 1;
          break;
        }
      }
    }


  }


}
//main..................................................


//OLED function
void NormalState()
{
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Moving");
  display.fillRect(0, 19, 128, 12, BLACK);
  display.drawRect(Oled_x, 30, 30, 30, WHITE);
  display.display();

  Oled_inc += 0.1f*Oled_force;
  Oled_x += Oled_inc;
  if(Oled_x > 118 || Oled_x < 0)
  {
    Oled_force =- Oled_force;
    Oled_inc = 0.0f;
  }        
}

void DangerousState()
{
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Dangerous!");
  display.fillRect(0, 19, 128, 12, BLACK);
  display.fillRect(80, 25, 10, 40, WHITE);
  display.drawRect(Oled_x, 30, 30, 30, WHITE);
  display.display();

  Oled_inc += 0.1f*Oled_force;
  Oled_x += Oled_inc;
  if(Oled_x > 50 || Oled_x < 0)
  {
    Oled_force =- Oled_force;
    Oled_inc = 0.0f;
  }    
}

void WarningState()
{
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,30);
  display.println("!Warning!");    
  display.display();
}
//...................................................


void ServoControl(int datain_)
{
//Servo Control
    if(datain_ == 1)
    {
      LED.justLED1(0);
      while(1)
      {
        Servo1.Turn180To0();
        WarningState();
        LED.justLED2(255);

        if(bluetooth.available() > 0)
        {
          LED.justLED2(0);
          break;
        }
      }
    }

    if(datain_ == 2)
    {
      LED.justLED1(0);
      while(1)
      {
        Servo1.Turn0To180();
        WarningState();
        LED.justLED2(255);

        if(bluetooth.available() > 0)
        {
          LED.justLED2(0);
          break;
        }
      }
    }

    if(datain_ == 3)
    {
      LED.justLED1(0);
      while(1)
      {
        Servo2.Turn0To180();
        WarningState();
        LED.justLED2(255);

        if(bluetooth.available() > 0)
        {
          LED.justLED2(0);
          break;
        }
      }
    }

    if(datain_ == 4)
    {
      LED.justLED1(0);
      while(1)
      {
        Servo2.Turn180To0();
        WarningState();
        LED.justLED2(255);

        if(bluetooth.available() > 0)
        {
          LED.justLED2(0);
          break;
        }
      }
    }

    if(datain_ == 5)
    {
      LED.justLED1(0);
      while(1)
      {
        Servo3.Turn180To0();
        WarningState();
        LED.justLED2(255);

        if(bluetooth.available() > 0)
        {
          LED.justLED2(0);
          break;
        }
      }
    }

    if(datain_ == 6)
    {
      LED.justLED1(0);
      while(1)
      {
        Servo3.Turn0To180();
        WarningState();
        LED.justLED2(255);

        if(bluetooth.available() > 0)
        {
          LED.justLED2(0);
          break;
        }
      }
    }

    if(datain_ == 7)
    {
      LED.justLED1(0);
      while(1)
      {
        Servo4.Turn180To0();
        WarningState();
        LED.justLED2(255);

        if(bluetooth.available() > 0)
        {
          LED.justLED2(0);
          break;
        }
      }
    }

    if(datain_ == 8)
    {
      LED.justLED1(0);
      while(1)
      {
        Servo4.Turn0To180();
        WarningState();
        LED.justLED2(255);

        if(bluetooth.available() > 0)
        {
          LED.justLED2(0);
          break;
        }
      }
    }

    if(datain_ == 13)
    {
      Servo1.WantedAngle(90);
      Servo2.WantedAngle(179);
      Servo3.WantedAngle(179);
      Servo4.WantedAngle(179);
    }
    //..........................................
}



