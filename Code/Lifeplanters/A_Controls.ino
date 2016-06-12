

// Controller 1:
void control(String device, byte device_num, float desired_output)
{
  if(device=="pump")
  {   readMoisture();
      float curr_reading = filter_moist;
      
      int pid_out = PID(1, 0, 0, desired_output, curr_reading);
      int pump_time = (int)mapping(0, LOOP_TIME, pid_out, -100, 100, 5);// (out_min, out_max, input_reading, in_min, in_max, mode)
      pump(PUMP1_PIN, pump_time, LOOP_TIME);
  }
  else if(device =="light")
  {  readLight();
     float curr_reading = filter_light;
     int pid_out = PID(1, 0, 0, desired_output, curr_reading);
  }
}


int PID(int kp, int ki, int kd, float desired_output, float curr_reading)
{
  float err = desired_output - curr_reading;
  err_sum = err + last_err;
  float err_d = (err - last_err)/LOOP_TIME;  
  last_err = err;
  int pid_out = kp*err + ki*err_sum + kd*err_d; 
  return pid_out;
}

