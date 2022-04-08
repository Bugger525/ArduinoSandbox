class Digital
{
public:
  Digital() { }
  Digital(int pin, int mode)
  {
    pin_ = pin;
    mode_ = mode;
    pinMode(pin_, mode_);
  }
  int pin() const
  {
    return pin_;
  }
  int mode() const
  {
    return mode_;
  }
protected:
  int pin_ = 0;
  int mode_ = 0;
};
class LED : public Digital
{
public:
  LED() : Digital()
  {
  }
  LED(int pin, int mode) : Digital(pin, mode)
  {
  }
  void on()
  {
    digitalWrite(pin_, HIGH);
  }
  void blink(unsigned int ms)
  {
     digitalWrite(pin_, HIGH);
     delay(ms);
     digitalWrite(pin_, LOW);
  }
};
class ArduinoProgram
{
private:
  LED leds_[3];
public:
  ArduinoProgram()
  {
  }
  void Setup()
  {
    leds_[0] = LED(2, OUTPUT);
    leds_[1] = LED(6, OUTPUT);
    leds_[2] = LED(13, OUTPUT); 
  }
  void Loop()
  {
    leds_[0].blink(100);
    leds_[1].blink(200);
    leds_[2].blink(300);
  }
};

ArduinoProgram arduinoProgram = ArduinoProgram();

void setup()
{
  arduinoProgram.Setup();
}
void loop()
{
  arduinoProgram.Loop();
}
