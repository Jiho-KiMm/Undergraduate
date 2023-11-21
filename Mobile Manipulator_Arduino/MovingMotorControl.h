class MovingMotor
{
private:
  int RightMotor_E_pin;       // 오른쪽 모터의 Enable & PWM
  int LeftMotor_E_pin;        // 왼쪽 모터의 Enable & PWM
  int RightMotor_1_pin;       // 오른쪽 모터 제어선 IN1
  int RightMotor_2_pin;       // 오른쪽 모터 제어선 IN2
  int LeftMotor_3_pin;       // 왼쪽 모터 제어선 IN3
  int LeftMotor_4_pin;  
  int Speed;

public:

  MovingMotor(int RightMotor_E_pin_, int LeftMotor_E_pin_, int RightMotor_1_pin_, int RightMotor_2_pin_, int LeftMotor_3_pin_, int LeftMotor_4_pin_ );
  
  void GoStraight(int Speed_);
  void GoBack(int Speed_);
  void TurnRight(int Speed_);
  void TurnLeft(int Speed_);
  void StopMoving();

};