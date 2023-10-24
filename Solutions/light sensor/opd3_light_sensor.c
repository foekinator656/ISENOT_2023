
#define POTENTIOPIN 5
#define sensorUseage 2 //0=sampling rate 1=range 2=graphdata
#define measurementAttempts 200


#include "simpletools.h"                    
#include "mstimer.h"
#include "ping.h"

//reference document https://learn.parallax.com/tutorials/language/blocklyprop/circuit-practice-blocklyprop/potentiometer-position

float measurePotentiometer(){
    high(POTENTIOPIN);
    pause(1);
    return ((float)rc_time(POTENTIOPIN, 1))/(1000000);
  }
  
void measureRange(){
    while(1){
      printf("%ld \n", measurePotentiometer());
      }
  }  

void createGaphData(){
  mstime_start();
  for(int i = -23; i<measurementAttempts; i++){// -25 off set to begin prints
      printf("%d, %0.8f \n",  mstime_get(), measurePotentiometer());
    }
  }
  
void measureSamplingrate(){
  pause(500);
  printf("start within 0.2s \n");
  pause(200);

  float currentMeasurement = -1; // the last measurement the device made
  int changeCounter = 0; // counter for the amount of measurements that differ from the last one.
  mstime_start();
 
  for(int i = 0; i<measurementAttempts; i++){ 
    long newMeasurement = measurePotentiometer();
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


int main()                                    // Main function
{
  if(sensorUseage==0){
    pause(1000);
    measureSamplingrate();
  }
  else if(sensorUseage==1){
    measureRange();
  }
   else if(sensorUseage==2){
    createGaphData();
  }
   exit(0);
}
