#include <Wire.h>
#include <LifePlanters.h>

LifePlanters planter1(0x20, 5);
LifePlanters planter2(0x22, 4);

void setup() {
  Wire.begin();
  Serial.begin(9600);
  planter1.checkStatus();
  planter1.getAllReadings();

  planter2.checkStatus();
  planter2.getAllReadings();
//  planter1.changeSensorAddr(0x20);
  planter2.set_desired_moisture(15);
  
  planter2.findAllSensors();
}

void loop() {
  planter1.getScaledMoisture();
  planter2.getScaledMoisture();

//  delay(1000);
  
  planter2.control_pump();

  
  
}


