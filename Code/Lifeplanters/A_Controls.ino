

// Controller 1:
void control_1(String device, byte device_num, float desired_output)
{
  if(device=="pump")
  {   readMoisture();
      float curr_reading = filter_moist;
      int pid_out = PID(1, 0, 0, desired_output, curr_reading);
      int pump_time = (int)mapping(0, LOOP_TIME, pid_out, -100, 100, 5);// (out_min, out_max, input_reading, in_min, in_max, mode)
      
      if(debug){
        Serial.print("pid_out: ");   Serial.println(pid_out);
        };
        
      pump1(device_num, pump_time);
  }
  else if(device =="light")
  {  readLight();
     float curr_reading = filter_light;
     int pid_out = PID(1, 0, 0, desired_output, curr_reading);

     if(debug){
        Serial.print("pid_out: ");   Serial.println(pid_out);
        };
  }
}

// Controller 1b: using more general code with pointers
void control_1b(String device, byte device_num, float &desired_output)
{ // pointers so I dont have to repeat myself
  uint8_t *point_index;
  const uint8_t *point_size;
  uint32_t *point_arr;
  float *point_filter;
  const int *point_kp, *point_ki, *point_kd;
  const int *point_inmin, *point_inmax, *point_outmin, *point_outmax;

  uint8_t mode=5;
  
  if(device=="pump")
  { // pointers
    point_index = &raw_moist_index; point_size = &MOIST_SIZE; point_arr = raw_moisture; point_filter=&filter_moist; 
    point_kp=&kp_m; point_ki=&ki_m; point_kd=&kd_m;
    point_inmin = &in_min_moist; point_inmax = &in_max_moist; point_outmin = &out_min_moist; point_outmax = &out_max_moist; 
  }
  
  float curr_reading = *point_filter;
  int pid_out = PID(*point_kp, *point_ki, *point_kd, desired_output, curr_reading);
  int process_var = (int)mapping(*point_outmin, *point_outmax, pid_out, *point_inmin, *point_inmax, mode);
  
    // device actuation
  if(device=="pump")
  { //pump1(device_num, process_var); // process_var is percentage, multiplied by a reduction factor in the code. 
    pump2(device_num, desired_output, curr_reading); // what pump 2 does is that it turns pump on once moisture falls below a threshold. And then stops until the moisture reaches the desired. 
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

