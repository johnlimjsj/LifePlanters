



float mapping(int out_min, int out_max, long in_reading, long in_min, long in_max, uint8_t mode)
{
  float out_reading;
  // Saturation limits
  if(in_reading>in_max){in_reading = in_max;}
  if(in_reading<in_min){in_reading = in_min;}
  if(in_reading == null){Serial.println("null input into the mapping function"); return null;};
  switch(mode)
  {
    case 1:{
      out_reading = null;         
      break;
    }
    default:{ // linear mapping
      out_reading = out_min + (out_max - out_min)*((in_reading - in_min)/(in_max - in_min));
    }
  }
  return out_reading;
}

