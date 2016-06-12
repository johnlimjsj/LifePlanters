

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
