
// ====== Pump control scheme 1 ======
/* @param: (int time_on, int time_total)
 * @returns: void
   USES A DELAY. not so good if we want fast response and multi threading
   What this code does that it takes in an integer, time in milliseconds; time_total specifies the total time we will remain in this loop 
   it turns on the pump for that number of milliseconds, and off for the remaining number of seconds
 */

void pump1(byte pump_pin, int percent_time_on)
{ long time_total = LOOP_TIME;  // 2^32 = 1193 hours (49 days), 2^16 = 65 seconds 
  long time_on = percent_time_on * time_total / 100;
  long time_off = time_total - time_on;
  
  digitalWrite(pump_pin, HIGH); // turn on pump
  delay(time_on);
  
  digitalWrite(pump_pin, LOW); // turn off pump
  delay(time_off); 

  if(debug){
    Serial.print("Turning the pump on for: ");    Serial.println(time_on);
    Serial.print("Turning the pump off for: ");   Serial.println(time_off);
  }        
} // end of pump



// Pump control scheme 2============
/*
what pump 2 does is that it turns pump on once moisture falls below a threshold. And then stops until the moisture reaches the desired level 
 */

 void pump2(byte pump_pin, int desired_moisture, int curr_moisture)
 {
  int min_thresh = 0.6 * desired_moisture;
  if(curr_moisture < min_thresh){ digitalWrite(pump_pin, HIGH);}
  if(curr_moisture > desired_moisture){ digitalWrite(pump_pin, LOW);}

  long interval = millis() - last_time;
  if(interval<= time_total)
  {
    if(millis() - last_time <time_on){
      // turn on pump
    }
    if(millis()-last_time > time_on){
      last_time=millis();
    }
    digitalWrite(pump_pin, LOW); // turn off pump
  }   
// last_time = millis();
 }

