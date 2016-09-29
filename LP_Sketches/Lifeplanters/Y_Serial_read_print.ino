// functions to print readings or enter them onto the serial buffer

void printReadings()
{
  Serial.print("Soil Moisture Capacitance: ");
  Serial.print(filter_moist); //read capacitance register
  Serial.print(", Temperature: ");
  Serial.print(filter_temp/(float)10); //temperature register
  Serial.print(", Light: ");
  Serial.println(filter_light); //request light measurement, wait and read light register
}

float serial_readbuff(String message){
  Serial.println(message);  
  while(!Serial.available()){}
  float reading = Serial.parseInt();
  while(Serial.available()>0){Serial.read();} // to clear serial buffer
  Serial.print("input value was: "); Serial.print(reading);
  Serial.println();
  return reading;
}

float serial_printresult(String message, float result){
  Serial.print(message); Serial.print(result);
  Serial.println();
}
