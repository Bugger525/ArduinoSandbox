class Element
{
public:
  Element()
  {
    pin_ = 0;
    mode_ = 0;
    value_ = 0;
  }
  Element(int pin, int mode)
  {
    pin_ = pin;
    mode_ = mode;
    value_ = 0;
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
  virtual int Value()
  {
    return value_;
  }
  void SetValue(int value)
  {
    value_ = value;
  }
protected:
  int pin_;
  int mode_;
  int value_;
};

class LED : public Element
{
public:
  LED() : Element()
  {
  }
  LED(int pin) : Element(pin, OUTPUT)
  {
  }
  void On() const
  {
    analogWrite(pin_, value_);
  }
  void Off() const
  {
    analogWrite(pin_, 0);
  }
  void Blink(unsigned int ms) const
  {
     On();
     delay(ms);
     Off();
     delay(ms);
  }
};
class Button : public Element
{
public:
  Button() : Element()
  {
  }
  Button(int pin, int mode) : Element(pin, mode)
  {
  }
  int Value() override
  {
    value_ = digitalRead(pin_);
    return value_;
  }
};
class Buzzer : public Element
{
public:
  Buzzer() : Element()
  {
  }
  Buzzer(int pin) : Element(pin, OUTPUT)
  {
  }
  void Beep(int sound)
  {
    tone(pin_, sound);
    delay(30);
    noTone(pin_);
  }
};

Button Buttons[3] = { Button(2, INPUT_PULLUP), Button(3, INPUT), Button(4, INPUT) };
Buzzer Buzzer1 = Buzzer(9);

void setup()
{
}

void loop()
{
  if (Buttons[0].Value() == LOW)
  {
    Buzzer1.Beep(523);
  }
  else if (Buttons[1].Value() == LOW)
  {
    Buzzer1.Beep(659);
  }
  else if (Buttons[2].Value() == HIGH)
  {
    Buzzer1.Beep(783);
  }
}
