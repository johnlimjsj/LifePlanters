
/* ============= test pump 2 algorithm  ===============
 *  Result: works!
 */

void pump2_test(int pump_pin){
  int curr_moisture;
  int desired_moisture;

  desired_moisture = serial_readbuff("Key in desired moisture: ");
  curr_moisture = serial_readbuff("Key in current moisture: ");
  pump2(pump_pin, desired_moisture, curr_moisture);
}

/* =====end of test pump2 algorithm ============ */

/* ============= test light 2 algorithm  ===============
 *  Result: works!
 */

void light2_test(int light_pin){
  int light_intensity = serial_readbuff("Key in amount of light currently received: ");
  int curr_light_pwm = light2(light_pin, light_intensity);
  serial_printresult("Current light pwm signal: ", curr_light_pwm);
}


/* ====== Test of moving average algorithm =========
 *  Result: Working 
 */
float mov_avg1_test()
{ 
  float filtered=0;
  raw_moisture[0]=400;
  raw_moisture[1]=300;
  filtered = mov_avg(raw_moisture, MOIST_SIZE);
  print_array();
  serial_printresult("filtered data", filtered);
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

/* ================== Test for Mapping =================== */
/* Result: Working
 Note: in_reading must not be a float, or else it will be off by a little decimal point. Not a problem because the soil sensor i2c library readss off integer values anyway
*/
void testMappingFunction()
{
  float result;
  float in_reading;
  uint8_t mode = 2;

  in_reading = serial_readbuff("key in input to test mapping function");
  if(in_reading==null){Serial.println("The input is indeed null. I should see a print statement before this to say the input is null. Check!");}
  else{
    result = mapping(0, 100, in_reading, 236, 65536, 2); // (int out_min, int out_max, long in_reading, long in_min, long in_max, uint8_t mode)
    serial_printresult("The mapped output is: ", result);
  }  
}
/* ================== Test for reading moisture() =================== */
/* Result: Working
 */
void test_readMoisture()
{
  float reading = serial_readbuff("Enter in the soil capacitance reading: ");
  readMoisture(reading);
  serial_printresult("Filtered moisture value is: ", filter_moist);
}

/* ================== Test for reading light () =================== */
/* Result: Working
 */
void test_readLight()
{
  double reading = serial_readbuff("Enter in the darkness reading: ");
  readLight(reading);
  serial_printresult("Filtered light value is: ", filter_light);
}

/* ================== Test for Pump 1 =================== */
// Result: Incomplete. No need to test actually. 
void pump1_test(){
  unsigned long now = millis();
  pump1(PUMP1_PIN, 70);  // Turns the pump on for 70 %
  unsigned long then = millis();
  Serial.print("Pump was running for: "); Serial.println(then - now);
}


/* ================== Test for PID =================== 
Result: working
*/
void pid_test()
{
  float desired_reading;
  float current_reading;
  float pid_correction;
  
  desired_reading = serial_readbuff("key in desired PID setpoint");
  current_reading = serial_readbuff("key in current reading");
  pid_correction = PID(1, 0, 0, desired_reading, current_reading);
  serial_printresult("The PID output is: ", pid_correction);
}

/* ================== Test for control_1() =================== 
Result: working
*/
void control_test()
{
  int desired_moisture = serial_readbuff("Enter the desired moisture: ");
  control_1("pump", 5, desired_moisture);
  float curr_reading = filter_moist;
  serial_printresult("The current filtered moisture reading is ", curr_reading);
}

void control_light_test()
{
  control_1("light", 10, 100);
  double curr_reading = filter_light;
  serial_printresult("The current filtered light reading is ", curr_reading);
}

/* ================== Test for whether the physical sensor can read data =================== 
Result: working
*/

void sensor_test()
{
  int desired_moisture = serial_readbuff("Key any unsigned integer to proceed: ");
  Serial.print("Soil Moisture Capacitance: ");
  Serial.print(soilSensor1.getCapacitance()); //read capacitance register
  Serial.println();
  Serial.print(", Temperature: ");
  Serial.print(soilSensor1.getTemperature()/(float)10); //temperature register
  Serial.println();
  Serial.print(", Light: ");
  Serial.println(soilSensor1.getLight(true)); //request light measurement, wait and read light register
  Serial.println();
}

