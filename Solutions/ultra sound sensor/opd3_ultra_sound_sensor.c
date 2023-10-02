#define PINGPIN 8
#define measurementAttempts 200

#include "simpletools.h"                      // Include simple tools
#include "mstimer.h"
#include "ping.h"
#define PINGPIN 8
#define PING_SOS_M_PER_SEC 344.8
#define PING_SOS_M_PER_MICROSEC PING_SOS_M_PER_SEC/10000
#define measuretime 50



float pingCmDistanceFloat()
{
    float distanceFloat_CM = ping(PINGPIN)*PING_SOS_M_PER_MICROSEC/2;
    return distanceFloat_CM; 
}

int waitMeasureTime(int lastTimeStamp){
    int mstime =  mstime_get();
    pause(measuretime-mstime+lastTimeStamp);
    return mstime_get();
  }

int main()                                    // Main function
{
  
  pause(500);
  printf("start within 0.5s \n");
  pause(450);
  printf("start");
  pause(50);

  float currentMeasurement = -1; // the last measurement the device made
  int changeCounter = 0; // counter for the amount of measurements that differ from the last one.
  mstime_start();
  int lastTimeStamp = 0;
 
  for(int i = 0; i<measurementAttempts; i++){ 
    float newMeasurement = pingCmDistanceFloat();
    int mstime =  mstime_get();
    print("%d ,%.2f\n", mstime, newMeasurement);

    if(newMeasurement!=currentMeasurement){
        changeCounter++;
        currentMeasurement=newMeasurement;
    }
    lastTimeStamp = waitMeasureTime(lastTimeStamp);
  }
  int mstime = mstime_get();
  printf("it took %dms \n", mstime);
  printf("had %d changes \n", changeCounter);
  printf("ESR is %.0f/s", ((float)changeCounter)/((float)mstime)*1000);  
}