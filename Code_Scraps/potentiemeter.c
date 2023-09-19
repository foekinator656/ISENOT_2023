#include "simpletools.h"                      // Include simpletools header
#include "ping.h"                             // Include ping header
#include <datetime.h>

typedef datetime;

int main()                                    // main function
{
  printf("start within 0.5s \n");
  pause(500);
  int startTime = dt_getms();
  high(7);
  pause(1);
  int currentDist = (rc_time(7, 1));
  int shortestDuration = 1000;
  int startRotationTimeStamp = startTime;
   
  while(startTime+2000>dt_getms())                                   // Repeat indefinitely
  {
   high(7);
   pause(1);
   int newDist = (rc_time(7, 1));  
   print("dist: %d \n", newDist);
   if(currentDist!=newDist){
     currentDist = newDist;
     int duration = dt_getms() - startRotationTimeStamp;
     if(duration<shortestDuration){
        shortestDuration = duration;
       }
     int startRotationTimeStamp = dt_getms();
    }    
  }
  print("shortest duration: %d \n", shortestDuration);
  print("ESP: %f", 1/(((float)shortestDuration)/1000));
}


