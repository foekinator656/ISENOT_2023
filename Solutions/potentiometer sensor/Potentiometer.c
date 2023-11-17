#define POTENTIOPIN 7
#define sensorUseage 0 //0=sampling rate 1=range 2=graphdata
#define measurementAttempts 500


#include "simpletools.h"                    
#include "mstimer.h"
#include "ping.h"

//reference document https://learn.parallax.com/tutorials/language/blocklyprop/circuit-practice-blocklyprop/potentiometer-position

long measurePotentiometer(){
    high(POTENTIOPIN);
    pause(1);
    return rc_time(POTENTIOPIN, 1);
  }
  
void measureRange(){
    while(1){
      printf("%ld \n", measurePotentiometer());
      }
  }  

void createGaphData(){
   mstime_start();
  for(int i = -25; i<measurementAttempts; i++){// -25 off set to begin prints
      printf("%d, %d, %ld \n",i ,  mstime_get(), measurePotentiometer());
    }
  }
  
void measureSamplingrate(){
  pause(500);
  printf("start within 0.2s \n");
  pause(200);

  long currentMeasurement = -1; // the last measurement the device made
  mstime_start();
 
  for(int i = 0; i<measurementAttempts; i++){ 
    printf("%d, %ld \n",  mstime_get(), measurePotentiometer());
    pause(1); 
  }  
  int mstime = mstime_get();
  printf("it took %dms \n", mstime);
  printf("ESR is %.0f/s", ((float)measurementAttempts)/((float)mstime)*1000); // changes/time(MS) = sampling rate MS, sampling rate MS*1000 = sampling rate S
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
