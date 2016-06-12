
// ====== Pump control scheme 1 ======
/* @param: (int time_on, int time_total)
 * @returns: void
   USES A DELAY. not so good if we want fast response and multi threading
   What this code does that it takes in an integer, time in milliseconds; time_total specifies the total time we will remain in this loop 
   it turns on the pump for that number of milliseconds, and off for the remaining number of seconds
 */

void pump(byte pump, int percent_time_on)
{ long time_total = LOOP_TIME;  // 2^32 = 1193 hours (49 days), 2^16 = 65 seconds 
  long time_on = percent_time_on * time_total / 100;
  long time_off = time_total - time_on;
  
  digitalWrite(pump, HIGH); // turn on pump
  delay(time_on);
  
  digitalWrite(pump, LOW); // turn off pump
  delay(time_off); 
} // end of pump



// Pump control scheme 2============
/*

 uses the millis(), which can count up to 32 bits (49 days). 
 
 */
