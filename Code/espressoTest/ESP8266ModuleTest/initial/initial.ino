#include <AFMotor.h>
#include <Adafruit_NeoPixel.h>

AF_DCMotor motor_dc_1(1, MOTOR12_64KHZ);
Adafruit_NeoPixel strip_pin2 = Adafruit_NeoPixel(60,2, NEO_RGB + NEO_KHZ800);

void setup()
{
  strip_pin2.begin();
  strip_pin2.show();
}

void loop()
{
  motor_dc_1.setSpeed(255);
  motor_dc_1.run(FORWARD);
}


