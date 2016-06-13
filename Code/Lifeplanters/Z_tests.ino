

// functions to print readings

void printReadings()
{
  Serial.print("Soil Moisture Capacitance: ");
  Serial.print(filter_moist); //read capacitance register
  Serial.print(", Temperature: ");
  Serial.print(filter_temp/(float)10); //temperature register
  Serial.print(", Light: ");
  Serial.println(filter_light); //request light measurement, wait and read light register
}

/* ============= test pump 2 algorithm  ===============
 *  Result: works!
 */
int curr_moisture;
int desired_moisture = 60;
void pump2_test(int pump_pin){
  for(curr_moisture=35; curr_moisture<=76; curr_moisture+=10){print_delay(pump_pin);}
  for(curr_moisture=74; curr_moisture>=30; curr_moisture-=10){print_delay(pump_pin);}
}

void print_delay(int pump_pin)
{
  pump2(pump_pin, desired_moisture, curr_moisture);
  Serial.print("Current moisture:");Serial.print(curr_moisture, DEC);
  Serial.println();
  delay(1500); 
}
/* =====end of test pump2 algorithm ============ */


/* ====== Test of moving average algorithm =========
 *  Result: Working 
 */
float mov_avg_test()
{
  float filtered=0;
  raw_moisture[0]=400;
  raw_moisture[1]=300;
  filtered = mov_avg(raw_moisture, MOIST_SIZE);
  print_array();
  Serial.print("filtered data: "); Serial.print(filtered);
  Serial.println();
  return filtered;
}

void print_array()
{
  int i;
  Serial.print("Array: ");
  for(i=0; i<MOIST_SIZE; i++){Serial.print(raw_moisture[i]); Serial.print(", ");}
  Serial.println();
  delay(1500);
}

/* ====== End of test of moving average algorithm ======== */









 
