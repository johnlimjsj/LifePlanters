


void readMoisture()
{
  raw_moisture[raw_moist_index] = soilSensor1.getCapacitance();
  raw_moist_index++;
  filter_moist = mov_avg(raw_moisture, MOIST_SIZE);
}

void readLight()
{
  raw_light[raw_light_index] = soilSensor1.getLight();
  raw_light_index++;
  filter_light = mov_avg(raw_light, LIGHT_SIZE);
}

void readTemp()
{
  raw_temp[raw_temp_index] = soilSensor1.getTemperature();
  raw_temp_index++;
  filter_temp = mov_avg(raw_temp, TEMP_SIZE);
}
