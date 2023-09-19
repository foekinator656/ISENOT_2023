#include "simpletools.h"                      // Include simpletools header
#include "ping.h"                             // Include ping header
#include <datetime.h>


#define firsttest 1
#define PINGPIN 8
#define PING_SOS_M_PER_SEC 344.8
#define PING_SOS_M_PER_MICROSEC PING_SOS_M_PER_SEC/10000


typedef datetime;


float pingCmDistanceFloat()
{
    float distanceFloat_CM = ping(PINGPIN)*PING_SOS_M_PER_MICROSEC/2;
    return distanceFloat_CM; 
}


int main(){
  while(0){
  float variable = pingCmDistanceFloat();
  printf("%.4f \n",variable);
  }  
  //exit(0);
  printf("start within 0.5s \n");
  pause(500);
  int startTime = dt_getms();
  int currentDist = ping(PINGPIN);
  print("%d", currentDist);
  int shortestDuration = 1000;
  int startRotationTimeStamp = startTime;
   
  while(startTime+2000>dt_getms()){
   int newDist = ping(PINGPIN);            
   if(currentDist!=newDist){
     currentDist = newDist;
     int duration_ms = dt_getms() - startRotationTimeStamp;
     if(duration_ms<shortestDuration){
        shortestDuration = duration_ms;
       }
     int startRotationTimeStamp = dt_getms();
    }    
  }
  
  print("shortest duration: %d \n", shortestDuration);
  print("ESP: %f", 1/(((float)shortestDuration)/1000));
  return 0;
}




