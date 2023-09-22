#define PINGPIN 8
#define measurementAttempts 1000
#define POTENTIOPIN 7

#include "simpletools.h"                      // Include simple tools
#include "mstimer.h"
#include "ping.h"
#define PINGPIN 8
#define PING_SOS_M_PER_SEC 344.8
#define PING_SOS_M_PER_MICROSEC PING_SOS_M_PER_SEC/10000



float pingCmDistanceFloat()
{
    float distanceFloat_CM = ping(PINGPIN)*PING_SOS_M_PER_MICROSEC/2;
    return distanceFloat_CM; 
}


int main()                                    // Main function
{
  
  pause(500);
  printf("start within 0.5s \n");
  pause(450);
  printf("start");
  pause(50);

  int currentMeasurement = -1; // the last measurement the device made
  int changeCounter = 0; // counter for the amount of measurements that differ from the last one.
  mstime_start();
 
  for(int i = 0; i<measurementAttempts; i++){ 
    print("%d ,%.2f\n",mstime_get(), pingCmDistanceFloat());
  }  
}