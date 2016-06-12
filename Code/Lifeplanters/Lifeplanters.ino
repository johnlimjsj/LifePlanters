#include <Wire.h>
#include <I2CSoilMoistureSensor.h>
// Constants
#define PUMP_PIN 13 //specifying which digital pin controls the pump
#define MOIST_SIZE 5
#define LIGHT_SIZE 5
#define TEMP_SIZE 5

#define SENSOR1_ADDR 0x20

#define null -1234
// constructors
I2CSoilMoistureSensor soilSensor1 (SENSOR1_ADDR); // 0x20 is the default address of the sensor. need to add more addresses for more sensors

// global arrays to store data
uint32_t raw_moisture[MOIST_SIZE], raw_light[LIGHT_SIZE], raw_temp[TEMP_SIZE];


// variables
  // raw_reading array indexes
  uint8_t raw_moist_index=0, raw_light_index=0, raw_temp_index=0;
  float filter_moist, filter_light, filter_temp;


  

void setup() {
  
  // Setting up I2C once
  Wire.begin();
  Serial.begin(9600);
  
  soilSensor1.begin(); // reset sensor
  delay(1000); // give some time to boot up

  // Print on serial monitor to make sure that I2C is properly set up
  Serial.print("I2C Soil Moisture Sensor Address: ");
  Serial.println(soilSensor1.getAddress(),HEX);
  Serial.print("Sensor Firmware version: ");
  Serial.println(soilSensor1.getVersion(),HEX);
  Serial.println();


  // initializing arrays to null
  init_nullarr(raw_moisture, MOIST_SIZE);
  init_nullarr(raw_light, LIGHT_SIZE);
  init_nullarr(raw_temp, TEMP_SIZE);
}

void loop() {
  // Reading data:
/*  Serial.print("Soil Moisture Capacitance: ");
  Serial.print(sensor.getCapacitance()); //read capacitance register
  Serial.print(", Temperature: ");
  Serial.print(sensor.getTemperature()/(float)10); //temperature register
  Serial.print(", Light: ");
  Serial.println(sensor.getLight(true)); //request light measurement, wait and read light register
*/





}
