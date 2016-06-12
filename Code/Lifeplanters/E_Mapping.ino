



float mapping(int out_min, int out_max, long in_reading, long in_min, long in_max, uint8_t mode)
{
  float out_reading;
  switch(mode)
  {
    case 1:{        
       break;
    }
    default:{ // linear mapping
      out_reading = out_min + (out_max - out_min)*((in_reading - in_min)/(in_max - in_min));
    }
  }
  return out_reading;
}

