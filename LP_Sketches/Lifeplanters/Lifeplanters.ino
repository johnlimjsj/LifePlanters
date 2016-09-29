
#include <Wire.h>
#include <SerialReadPrint.h>
#include <LifePlanters.h>


// Constants
#define PUMP1_PIN 5 //specifying which digital pin controls the pump
#define LIGHT1_PIN 10 //this must be a PWM pin
#define PH_PIN A1;

#define SENSOR1_ADDR 0x20

#define null 1234567

#define LOOP_TIME 100000 //this is loop time in milli seconds

long last_time=0;

const uint8_t MOIST_SIZE=5;
const uint8_t LIGHT_SIZE=5;
const uint8_t TEMP_SIZE=5;

// PID constants
const int kp_m=1, ki_m=0, kd_m=0;

uint8_t hello = A0;
// mapping limits
const int in_min_moist=0, in_max_moist=100, out_min_moist=-100, out_max_moist=100; 

// constructors
LifePlanters soilSensor1 (SENSOR1_ADDR); // 0x20 is the default address of the sensor. need to add more addresses for more sensors
SerialReadPrint serialRP;
// global arrays to store data
uint32_t raw_moisture[MOIST_SIZE], raw_light[LIGHT_SIZE], raw_temp[TEMP_SIZE];


// raw_reading array indexes
uint8_t raw_moist_index=0, raw_light_index=0, raw_temp_index=0;
double filter_moist, filter_light, filter_temp;

int last_err=0;
int err_sum=0;

void setup() {
  
  // Setting up I2C once
  Wire.begin();
  Serial.begin(9600);
  Serial.println(hello);
  soilSensor1.begin(); // reset sensor
  delay(1000); // give some time to boot up

  // Print on serial monitor to make sure that I2C is properly set up
  Serial.print("I2C Soil Moisture Sensor Address: ");
  Serial.println(soilSensor1.getAddress(),HEX);
  Serial.print("Sensor Firmware version: ");
  Serial.println(soilSensor1.getVersion(),HEX);
  Serial.println();
  
  // configuring digital pins
  pinMode(PUMP1_PIN, OUTPUT);

  // initializing arrays to null
  init_nullarr(raw_moisture, MOIST_SIZE);
  init_nullarr(raw_light, LIGHT_SIZE);
  init_nullarr(raw_temp, TEMP_SIZE);
}

void loop() {
//  control_1("pump", PUMP1_PIN, 60.00); // moisture in percentage
  control_1("light", LIGHT1_PIN, 50.55); // light in percentage
//   light2_test(10);
//   pump2_test(5);
//  mov_avg1_test();
//  testMappingFunction();
//  pid_test();
//  test_readMoisture();
//  test_readLight();
//  control_test();
//  control_light_test();
//  sensor_test();
}

// to initialize null arrays
void init_nullarr(uint32_t my_array[], uint8_t arr_data_size)
{ int i;
  for (i=0; i<arr_data_size; ++i) { my_array[i] = null;  }
}

