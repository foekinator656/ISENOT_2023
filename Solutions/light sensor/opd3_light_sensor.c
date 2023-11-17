
#define LIGHTPIN 5
#define sensorUseage 0 //0=sampling rate 1=range 2=graphdata
#define measurementAttempts 500


#include "simpletools.h"                    
#include "mstimer.h"
#include "ping.h"

//reference document https://learn.parallax.com/tutorials/language/blocklyprop/circuit-practice-blocklyprop/potentiometer-position

float measureLightSensor(){
    high(LIGHTPIN);
    pause(1);
    return ((float)rc_time(LIGHTPIN, 1))/(1000000);
  }
  
void measureRange(){
    while(1){
      printf("%ld \n", measureLightSensor());
      }
  }  

void createGaphData(){
  mstime_start();
  for(int i = -23; i<measurementAttempts; i++){// -25 off set to begin prints
      printf("%d, %0.6f \n",  mstime_get(), measureLightSensor());
    }
  }
  
void measureSamplingrate(){
  pause(500);
  printf("start within 0.2s \n");
  pause(200);

  float currentMeasurement = -1; // the last measurement the device made
  mstime_start();
 
  for(int i = 0; i<measurementAttempts; i++){ 
    float newMeasurement = measureLightSensor();
    printf("%d, %0.6f \n",  mstime_get(), newMeasurement);
    pause(1); 
  }  
  int mstime = mstime_get();
  printf("it took %dms \n", mstime);
  printf("SR is %.0f/s", ((float)measurementAttempts)/((float)mstime)*1000); // changes/time(MS) = sampling rate MS, sampling rate MS*1000 = sampling rate S
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
