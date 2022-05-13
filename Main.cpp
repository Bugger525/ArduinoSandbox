class Complex
{
public:
  Complex()
  {
    pin_ = 0;
    mode_ = 0;
    analogValue_ = 0;
  }
  Complex(int pin, int mode)
  {
    pin_ = pin;
    mode_ = mode;
    analogValue_ = 0;
    pinMode(pin_, mode_);
  }
  int Pin() const
  {
    return pin_;
  }
  int Mode() const
  {
    return mode_;
  }
  int AnalogValue() const
  {
    return analogValue_;
  }
protected:
  int pin_;
  int mode_;
  int analogValue_;
};
class LED : public Complex
{
public:
  LED() : Complex()
  {
  }
  LED(int pin) : Complex(pin, OUTPUT)
  {
  }
  void On() const
  {
    analogWrite(pin_, analogValue_);
  }
  void Off() const
  {
    analogWrite(pin_, 0);
  }
  void Set(unsigned int value)
  {
    analogValue_ = value;
  }
  void Blink(unsigned int ms) const
  {
     On();
     delay(ms);
     Off();
     delay(ms);
  }
};

auto Red = LED(11);
auto Green = LED(10);
auto Blue = LED(9);

void setup()
{
  Red.Set(255);
  Green.Set(255);
  Blue.Set(255);
  
  Red.On();
  Green.On();
  Blue.On();
}

void loop()
{
  int value = map(analogRead(A0), 0, 1023, 0, 255);
  const int Third = 255 / 3;
  
  if (value < Third)
  {
    Red.Set(255);
    Red.On();
    
    Green.Set(255);
    Green.On();
    
    Blue.Off();
  }
  else if (Third <= value && value < Third * 2)
  {
    Red.Set(255);
    Red.On();
    
    Green.Off();
    
    Blue.Set(255);    
    Blue.On();
  }
  else
  {
    Red.Off();
    
    Green.Set(255);
    Green.On();
    
    Blue.Set(255);
    Blue.On();
  }
}
