#include "arduino.h"
#include "MovingMotorControl.h"

MovingMotor::MovingMotor(int RightMotor_E_pin_, int LeftMotor_E_pin_, int RightMotor_1_pin_, int RightMotor_2_pin_, int LeftMotor_3_pin_, int LeftMotor_4_pin_ )
{
  RightMotor_E_pin = RightMotor_E_pin_;       
  LeftMotor_E_pin = LeftMotor_E_pin_;        
  RightMotor_1_pin = RightMotor_1_pin_;       
  RightMotor_2_pin = RightMotor_2_pin_;       
  LeftMotor_3_pin = LeftMotor_3_pin_;      
  LeftMotor_4_pin = LeftMotor_4_pin_ ;    

  Speed = 0;

  pinMode(RightMotor_E_pin, OUTPUT);        
  pinMode(RightMotor_1_pin, OUTPUT);
  pinMode(RightMotor_2_pin, OUTPUT);
  pinMode(LeftMotor_3_pin, OUTPUT);
  pinMode(LeftMotor_4_pin, OUTPUT);
  pinMode(LeftMotor_E_pin, OUTPUT);
}

void MovingMotor::GoStraight(int Speed_)
{
  Speed = Speed_;
    
  digitalWrite(RightMotor_1_pin, HIGH);
  digitalWrite(RightMotor_2_pin, LOW);
  digitalWrite(LeftMotor_3_pin, HIGH);
  digitalWrite(LeftMotor_4_pin, LOW);

  analogWrite(RightMotor_E_pin, Speed);
  analogWrite(LeftMotor_E_pin, Speed + 5);
}

void MovingMotor::GoBack(int Speed_)
{
  Speed = Speed_;

  digitalWrite(RightMotor_1_pin, LOW);
  digitalWrite(RightMotor_2_pin, HIGH);
  digitalWrite(LeftMotor_3_pin, LOW);
  digitalWrite(LeftMotor_4_pin, HIGH);
    
  analogWrite(RightMotor_E_pin, Speed+10);
  analogWrite(LeftMotor_E_pin, Speed+10);
}

void MovingMotor::TurnRight(int Speed_)
{
  Speed = Speed_;

  int R_motor = 0;
  int L_motor = 1;

  digitalWrite(RightMotor_1_pin, R_motor);
  digitalWrite(RightMotor_2_pin, !R_motor);
  digitalWrite(LeftMotor_3_pin, L_motor);
  digitalWrite(LeftMotor_4_pin, !L_motor);               
   
  analogWrite(RightMotor_E_pin, max(Speed,50));  // 우측 모터 속도값
  analogWrite(LeftMotor_E_pin, min(Speed,255));
}

void MovingMotor::TurnLeft(int Speed_)
{
  Speed = Speed_;
  int R_motor = 1;
  int L_motor = 0;

  digitalWrite(RightMotor_1_pin, R_motor);
  digitalWrite(RightMotor_2_pin, !R_motor);
  digitalWrite(LeftMotor_3_pin, L_motor);
  digitalWrite(LeftMotor_4_pin, !L_motor);
   
  analogWrite(RightMotor_E_pin, min(Speed,255));  // 우측 모터 속도값
  analogWrite(LeftMotor_E_pin, max(Speed,50));   // 좌측 모터 속도값   
}

void MovingMotor::StopMoving()
{
  MovingMotor::GoStraight(0);
}




