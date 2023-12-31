/* Forward then Stop.c */
#include "simpletools.h"
#include "abdrive.h"
// #include "abdrive360.h"
const float input_turning_in_degrees = 60.;
const float pi = 3.14159265359;
const float botWidth = 10.58; // in cm

int roundFloat(float a){
  int aUp = (int) a+0.5;
  int aLow = (int) a;
  if (aUp == aLow){
    return aLow;
  } else {
    return aUp;
  }      
}  

float cm2ticks(float lengthInCm){
  int ticks = roundFloat(lengthInCm / 0.325); // 0.325 cm per tick
  return ticks;
}

float degrees2ticks(float degrees){
  float deg2rad = pi/180.;
  // curve length = r * phi
  // r = 0.5 * botWidth
  // phi = deg2rad * degrees
  float curveLength = 0.5 * botWidth * deg2rad * degrees;
  int ticks = cm2ticks(curveLength);
  return ticks;
}    

void rotateBot(float angle){ // + angle = right turning or - angle = left turning
  drive_goto(degrees2ticks(angle), -degrees2ticks(angle));
}  

int main()                    
{ 
  pause(2000);  
  // assignment "Draai-op-de-plaats"
  rotateBot(input_turning_in_degrees);
  pause(30000);
  rotateBot(-input_turning_in_degrees); 
}
