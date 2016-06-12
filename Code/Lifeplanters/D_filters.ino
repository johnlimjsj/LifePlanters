





// Moving average filter in a ring buffer
/* @param: takes ina pointer to an array with size of 5. 
 
 */
float mov_avg(uint32_t raw_reading[], uint8_t arr_data_size)
{
  int i, sum=0;
  float filtered_reading;

  for (i=0; i<arr_data_size; ++i) {  
    if(raw_reading[i] != null){ sum += raw_reading[i];  }
  }
  filtered_reading = sum/arr_data_size ;  // <<<<<<<<<<<<<<<<<<<<< you cast int / int into float. That would probably give you an int value still. 

  return filtered_reading;
}

// initialize array to NULL

