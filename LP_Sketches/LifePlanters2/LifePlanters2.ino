#include <Wire.h>
#include <LifePlanters.h>

//LifePlanters planter1(0x20, 5);
LifePlanters planter2(0x22, 4);
LifePlanters* planter1;
void setup() {
  Wire.begin();
  Serial.begin(9600);
  planter1 = new LifePlanters(0x20, 5);
  planter1->checkStatus();
//  planter1.getAllReadings();

  planter2.checkStatus();
  planter2.printAllReadings();
//  planter1.changeSensorAddr(0x20);
  planter2.set_desired_moisture(15);
  planter2.findAllSensors();

  planter2.set_feeder_pin(9);
  planter2.set_feed_position(20);
  planter2.set_nofeed_position(100);
  planter2.set_feed_duration(3000);
  planter2.set_feed_interval(0,0,20);
  planter2.calibrate_servoMoveDuration(500);


}

void loop() {
//  planter2.getScaledMoisture();
//  planter2.readLight();
//  planter2.getScaledLight();

  
 
//  delay(1000);
  
//  planter2.control_pump();
  planter2.control_feeder();

  
  
}


