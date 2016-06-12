





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
  filtered_reading = sum/arr_data_size ;

  return filtered_reading;
}






// to determine array size

// initialize array to NULL
void init_nullarr(uint32_t my_array[], uint8_t arr_data_size)
{ int i;
  for (i=0; i<arr_data_size; ++i) { my_array[i] = null;  }
}

