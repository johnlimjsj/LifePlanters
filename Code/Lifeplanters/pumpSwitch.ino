
// ====== Pump control scheme 1 ======
/* @param: (int time_on, int time_total)
 * @returns: void
   What this code does that it takes in an integer, time in milliseconds; time_total specifies the total time we will remain in this loop 
   it turns on the pump for that number of milliseconds, and off for the remaining number of seconds
 */



void mapping(long in_minimum, long in_maximum, uint8_t mode)
{
  float 
  switch(mode)
  {
    case 1: // linear mapping
       
       break;

    default:
      break;
  }
  
}



void pump(long time_on, long time_total)
{   int time_off = time_total - time_on;
    
    on_pump(time_on);
    off_pump(time_off); 
} // end of pump



void on_pump(long time_on){ 
  digitalWrite(PUMP_PIN, HIGH);
  delay(time_on);  
}

void off_pump(long time_off){ 
  digitalWrite(PUMP_PIN, LOW);
  delay(time_off);  
}
