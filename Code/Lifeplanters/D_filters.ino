

// Moving average filter in a ring buffer
/* @param: takes ina pointer to an array with size of 5. 
 
 */
double mov_avg(uint32_t raw_reading[], uint8_t arr_data_size)
{
  uint8_t i;
  uint32_t sum=0;
  double filtered_reading;
  byte data_size = 0;
  for (i=0; i<arr_data_size; ++i) {  
    if(raw_reading[i] != null){ sum += raw_reading[i];  data_size++;}
  }
  filtered_reading = (double)sum/data_size ; 
  data_size=0;
  return filtered_reading;
}

// initialize array to NULL

