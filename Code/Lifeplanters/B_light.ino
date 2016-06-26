

// for demonstration purpose only. Not actually controlling the optimal amount of light. 
int light2(byte light_pin, int light_intensity)
{ 
  // inverse mapping, mode 2. When light intensity read is brighter, pwm signal becomes smaller to dim to control. 
  int light_pwm = mapping(0, 255, light_intensity, 0, 100, 2); //(int out_min, int out_max, long in_reading, long in_min, long in_max, uint8_t mode)
  analogWrite(light_pin, light_pwm);
  return light_pwm;
}

