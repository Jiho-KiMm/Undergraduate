#include <Servo.h>
#include "Light_sensing.h"
#include "Sound.h"
#include "LED_Blink.h"
#include "Distance_sensing.h"
#include "Change_sound.h"
#define Button 8
DistanceSens DS(3, 2);
Lightsensing LS;
ChangeSound CS;
Sound SC(7);
LEDBlinker LED1(13, 90, 900, 0);
LEDBlinker LED2(12, 80, 920, 0);
unsigned long Check_Operationg_Time = 0;
unsigned long Start_Time = 0;
unsigned long Check_Time1 = 0;
unsigned long dt_us = 0;
unsigned long lastTime = millis();
int interrupt_Num = 0;
float distance = 0;
int flag = 1;

void setup(){
  Serial.begin(9600);
  CS.attach(5);
  pinMode(Button, INPUT_PULLUP);
}
void rise() 
{ 
  dt_us=micros();
  attachInterrupt(interrupt_Num, fall, FALLING); 
}
void fall() 
{ 
  dt_us=micros()-dt_us;
  distance = dt_us/58.2;
}

void mainProcess()
{
  LED2.justLED(HIGH);
  CS.GetChangeValue();
  LS.SensorL();
  //LS.CheckLight();
  if(LS.CheckLightvalue()<60)
  {
    while(1)
    { 
      unsigned long curTime = millis();
      if (curTime-lastTime > 5)
      {
        DS.SensorD();
        attachInterrupt(interrupt_Num, rise, RISING); 
        lastTime=curTime;
      }
      SC.MakeANoise();
      LED1.Blink();
      LED2.Blink();
      //Serial.print("d = ");Serial.println(distance);
      if(distance < 8) 
      {
        Serial.print("d = ");Serial.println(distance);
        LED1.justLED(LOW);
        SC.StopNoise();
        break;            
      } 
    }
    Check_Time1 = millis();
    while(1) // 60000ms후 가동
    {
      Check_Operationg_Time = millis();
      if((Check_Operationg_Time - Check_Time1) > 360000) break;    
    }
  }
}

void loop()
{
  LED2.justLED(LOW);
  LED1.justLED(HIGH);

  if(digitalRead(Button)==0) 
  {
    if(flag == 1)
    {
      Start_Time = millis();
      flag = 0;
    }   
    Serial.println("Sound Control : 0. Small/ 1. Medium/ 2. Large");
    LED1.justLED(LOW);
    while(1) // 60000ms후 가동
    {
      Check_Operationg_Time = millis();
      if((Check_Operationg_Time - Start_Time) > 360000) break;
    }

    while(1)
    {
      Check_Operationg_Time = millis();
      mainProcess();
      if((Check_Operationg_Time -Start_Time) > 28800000) break; // 8시간 후 멈춤(28800000)
    }
    
    
    Serial.println("CheckPoint 3");
    Check_Operationg_Time = 0;
    flag = 1;
  }    
} 





