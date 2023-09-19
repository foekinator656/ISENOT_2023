#define PINGPIN 8
#define measurementAttempts 1000
#define POTENTIOPIN 7

#include "simpletools.h"                      // Include simple tools
#include "mstimer.h"
#include "ping.h"

int measurePotentiometer(){
    high(POTENTIOPIN);
    pause(1);
    return rc_time(POTENTIOPIN, 1);
  }
  
void bereikMetenPotentioMeter(){
    while(1){
      print("%d \n", measurePotentiometer());
      }
  }  

int main()                                    // Main function
{
  
  //bereikMetenPotentioMeter();
  pause(500);
  printf("start within 0.5s \n");
  pause(450);
  printf("start");
  pause(50);

  int currentMeasurement = -1; // the last measurement the device made
  int changeCounter = 0; // counter for the amount of measurements that differ from the last one.
  mstime_start();
 
  for(int i = 0; i<measurementAttempts; i++){ 
    int newMeasurement = measurePotentiometer();
    if(newMeasurement!=currentMeasurement){
      changeCounter++;
      currentMeasurement=newMeasurement;
      } 
    pause(1); 
  }  
  int mstime = mstime_get();
  printf("it took %dms \n", mstime);
  printf("had %d changes \n", changeCounter);
  printf("ESR is %.0f/s", ((float)changeCounter)/((float)mstime)*1000); // changes/time(MS) = sampling rate MS, sampling rate MS*1000 = sampling rate S
}
