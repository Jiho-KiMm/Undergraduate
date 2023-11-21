#define POT A1
class Sound
{
  int pin_Siren;
public:
  Sound(int pin_Siren_);
  void MakeANoise();
  void StopNoise();
};