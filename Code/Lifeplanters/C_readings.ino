


void readMoisture()
{
  raw_moisture[raw_moist_index] = soilSensor1.getCapacitance();
  raw_moist_index++;
  filter_moist = mov_avg(raw_moisture, MOIST_SIZE);
}

void readLight()
{
  raw_light[raw_light_index] = soilSensor1.getLight(true); //when .getLight(bool) takes in a TRUE, it reads the light for 3 seconds before returning the value. This means that if the array size is 5, if takes 15 seconds to filter the data. take note
  raw_light_index++;
  filter_light = mov_avg(raw_light, LIGHT_SIZE);
}

void readTemp()
{
  raw_temp[raw_temp_index] = soilSensor1.getTemperature(); // .getTemperature() returns a celcius value with a factor of 10. Divide by 10 to get real value
  raw_temp_index++;
  filter_temp = mov_avg(raw_temp, TEMP_SIZE)/10;
}



