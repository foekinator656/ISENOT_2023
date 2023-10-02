/* 
 ActivityBot 360 Calibrate.c
*/

#include "simpletools.h"
#include "abcalibrate360.h"    

int main()
{
 cal_servoPins(12, 13);
 cal_encoderPins(14, 15);
 
 high(26);
 high(27);
 pause(1000);
 low(26);
 low(27);
 cal_activityBot();
 high(26);
 high(27);
}