



double mapping(long out_min, long out_max, long in_reading, long in_min, long in_max, uint8_t mode)
{
  double out_reading;
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
    case 2:{ //inverse linear mapping
      out_reading = (double)out_max - (double)(out_max - out_min)*((double)(in_reading - in_min)/(in_max - in_min));
      break;
    }
    default:{ // linear mapping      
      out_reading = out_min + (double)(out_max - out_min)*(double)((double)(in_reading - in_min)/(in_max - in_min));
    }
  }
  return out_reading;
}

