


void readMoisture()
{
  raw_moisture[raw_moist_index] = soilSensor1.getCapacitance();
  raw_moist_index++;
  if(raw_moist_index>=MOIST_SIZE){raw_moist_index=0;}
  filter_moist = mov_avg(raw_moisture, MOIST_SIZE); 
}

void readLight()
{
  raw_light[raw_light_index] = soilSensor1.getLight(true); //when .getLight(bool) takes in a TRUE, it reads the light for 3 seconds before returning the value. This means that if the array size is 5, if takes 15 seconds to filter the data. take note
  raw_light_index++;
  if(raw_light_index >=5){ raw_light_index = 0;}
  filter_light = mov_avg(raw_light, LIGHT_SIZE);
}

void readTemp()
{
  raw_temp[raw_temp_index] = soilSensor1.getTemperature(); // .getTemperature() returns a celcius value with a factor of 10. Divide by 10 to get real value
  raw_temp_index++;
  if(raw_temp_index>=MOIST_SIZE){raw_temp_index=0;}
  filter_temp = mov_avg(raw_temp, TEMP_SIZE)/10;
}


// do a pass by reference so that I can have a generic functoin that applies to all 3 diferent parameters
float read_process_Param(String device, uint8_t &index, const uint8_t &arrsize, uint32_t param_array[])
{
  float reading;
  if(device== "pump"){ param_array[index] = soilSensor1.getCapacitance();}  // need to write a library for this to make it easy to retrieve data from multiple sensors. Currently, this is hard-coded to save time 
  
  else if(device =="light"){param_array[index] = soilSensor1.getLight();}

  else if(device =="temp"){param_array[index] = soilSensor1.getTemperature();}  

  index++;
  if(index >= arrsize){index=0;}

  // filters. Each of them return a float value of the filtered data
  reading = mov_avg(param_array, arrsize);// Moving average filter

  return reading;
  
}


