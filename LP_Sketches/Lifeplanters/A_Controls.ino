// Controller 1:
void control_1(String device, byte device_pin, float desired_output)
{
   if(device=="pump")
  { 
    uint16_t moisture_reading = soilSensor1.getCapacitance();
//    int moisture_reading = serial_readbuff("Enter in soil moisture: ");
    readMoisture(moisture_reading);
    pump2(device_pin, desired_output, filter_moist); // what pump 2 does is that it turns pump on once moisture falls below a threshold. And then stops until the moisture reaches the desired. 
  }
  else if(device =="light")
  {  
     uint32_t darkness_reading = soilSensor1.getLight(true); // when dark, .getLight() gives a very high number
//     uint32_t darkness_reading = serial_readbuff("Enter in darkness level: ");
     readLight(darkness_reading);
     light2(device_pin, filter_light);
  }
}

// Controller 2:
void control_2(String device, byte device_num, float desired_output)
{
  if(device=="pump")
  {   readMoisture(100);
      float curr_reading = filter_moist;      
      int pid_out = PID(1, 0, 0, desired_output, curr_reading);
      int pump_time = (int)mapping(0, LOOP_TIME, pid_out, -100, 100, 5);// (out_min, out_max, input_reading, in_min, in_max, mode)
      pump1(device_num, pump_time);
  }
  else if(device =="light")
  {  readLight(100);
     float curr_reading = filter_light;
     int pid_out = PID(1, 0, 0, desired_output, curr_reading);
  }
}

// Controller 1b: using more general code with pointers
//void control_2b(String device, byte device_num, float &desired_output)
//{ // pointers so I dont have to repeat myself
//  uint8_t *point_index;
//  const uint8_t *point_size;
//  uint32_t *point_arr;
//  float *point_filter;
//  const int *point_kp, *point_ki, *point_kd;
//  const int *point_inmin, *point_inmax, *point_outmin, *point_outmax;
//
//  uint8_t mode=5;
//  
//  if(device=="pump")
//  { // pointers
//    point_index = &raw_moist_index; point_size = &MOIST_SIZE; point_arr = raw_moisture; point_filter=&filter_moist; 
//    point_kp=&kp_m; point_ki=&ki_m; point_kd=&kd_m;
//    point_inmin = &in_min_moist; point_inmax = &in_max_moist; point_outmin = &out_min_moist; point_outmax = &out_max_moist; 
//  }
//  
//  float curr_reading = *point_filter;
//  
//    // device actuation
//  if(device=="pump")
//  { //pump1(device_num, process_var); // process_var is percentage, multiplied by a reduction factor in the code. 
//    pump2(device_num, desired_output, curr_reading); // what pump 2 does is that it turns pump on once moisture falls below a threshold. And then stops until the moisture reaches the desired. 
//  }
//  
//}


int PID(int kp, int ki, int kd, float desired_output, float curr_reading)
{
  float err = desired_output - curr_reading;
  err_sum = err + last_err;                 // <<<<<<<<<<<<<< should implement a PID reset of the error once the pumping operation has been completed
  float err_d = (err - last_err)/LOOP_TIME;  // <<<<<<<<<<<<<<<< Again not sure if int / int will give an int which you then cast to a float
  last_err = err;
  int pid_out = kp*err + ki*err_sum + kd*err_d; 
  return pid_out;
}

