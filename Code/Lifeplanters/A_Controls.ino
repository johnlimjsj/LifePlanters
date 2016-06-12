

// Controller 1:
void control(String device, byte device_num, float desired_output)
{
  if(device=="pump")
  {   readMoisture();
      float curr_reading = filter_moist;
      
      int pid_out = PID(1, 0, 0, desired_output, curr_reading);
      int pump_time = (int)mapping(0, LOOP_TIME, pid_out, -100, 100, 5);// (out_min, out_max, input_reading, in_min, in_max, mode) 
      // <<<<<<<<<<<<<<<<<<<<<< Should add a saturation limit so that pump_time does not go beyond 10000 which might be possible with integral controller
      pump(PUMP1_PIN, pump_time, LOOP_TIME);    // <<<<<<<<<<<< pump_time here is int but function takes in a long. Is this compatible?
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
  err_sum = err + last_err;                 // <<<<<<<<<<<<<< should implement a PID reset of the error once the pumping operation has been completed
  float err_d = (err - last_err)/LOOP_TIME;  // <<<<<<<<<<<<<<<< Again not sure if int / int will give an int which you then cast to a float
  last_err = err;
  int pid_out = kp*err + ki*err_sum + kd*err_d; 
  return pid_out;
}

