#include "SerialReadPrint.h"

SerialReadPrint hi;
void setup()
{
  Serial.begin(9600);
  
  hi.s_print("hello hello", 6);
  hi.s_print("byebye", 'c');
  hi.s_println("Johnny", 7);
  hi.s_println("JohnnyBrave", 7);
  
}

void loop()
{
  int hello;  
  float bye;
  char myChar;
  String myStr;
  
  hi.s_read("reading Int: ", &hello);
//  hi.s_read("Reading float", &bye);
  hi.s_read("Reading char", &myChar);
//  hi.s_read("Reading String", &myStr);

  
}

