/* Forward then Stop.c */
#include "simpletools.h"
#include "abdrive.h"
#include "ping.h"

const float input_drive_length_in_cm = 50.;
const float input_turning_in_degrees = 30.;
const float pi = 3.14159265359;
const float botWidth = 10.58; // in cm
const int doelAfstand = 50; // in cm
const int PINGPIN = 8;

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

void rotateBotAngle(float angle){ // + angle = right turning or - angle = left turning
  drive_goto(degrees2ticks(angle), -degrees2ticks(angle));
}
void rotateBotTicks(int ticks){ // + ticks = right turning or - ticks = left turning
  drive_goto(ticks, -ticks);
}

int main()                    
{
  pause(2000);
  int minTick = degrees2ticks(-input_turning_in_degrees);
  int maxTick = degrees2ticks(input_turning_in_degrees);
  
  rotateBotTicks(minTick);
  
  int tickpos = minTick;
  
  while (tickpos<=maxTick) {
      int distance = ping_cm(PINGPIN);
      if (distance < doelAfstand) {
        rotateBotTicks(3);
        break;
      } else {
        tickpos = tickpos +1;
        rotateBotTicks(1);
      }
    }
}
int backup()                    
{
  int distance = ping_cm(PINGPIN);
  if (distance < doelAfstand) {
    drive_goto(cm2ticks(10.), cm2ticks(10.));
    drive_goto(cm2ticks(-10.), cm2ticks(-10.));
  } else {
    drive_goto(-degrees2ticks(input_turning_in_degrees), degrees2ticks(input_turning_in_degrees));
    drive_goto(degrees2ticks(2*input_turning_in_degrees), -degrees2ticks(2*input_turning_in_degrees));
    drive_goto(-degrees2ticks(input_turning_in_degrees), degrees2ticks(input_turning_in_degrees));
  }
}