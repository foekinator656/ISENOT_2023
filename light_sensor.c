#include "simpletools.h"                      // Include simple tools

#include "mstimer.h"

#include "ping.h"

const int measurementAttempts = 1000;

const int pinNum = 5;

 

const int miljoen = 1000000;

 

int main()                                    // main function

{

  pause(500);

 

  printf("start within 0.5s \n");

 

  pause(500);

 

  float currentMeasurement = -1; // the last measurement the device made

 

  int changeCounter = 0; // counter for the amount of measurements that differ from the last one.

 

  mstime_start();

  //mstime_start(); // start time in miliseconden

  for(int i = 0; i<measurementAttempts; i++)                                 // Endless loop

  {

    high(pinNum);                                  // Set P5 high (3.3 V in)

    pause(1);                                 // Wait for circuit to charge ()

    float newMeasurement = ((float)rc_time(5, 1)) / (miljoen); // Measure decay time on P5

    print("Decay Time = %f\n", newMeasurement); // Display decay time (de tijd die nodig is om onder de 1.65 volt te komen) t is in microseconden

 

    if(newMeasurement!=currentMeasurement){

 

      changeCounter++;

 

      currentMeasurement=newMeasurement;

 

      }

    

    pause(1);                               // Wait 1/10th of a second

  }

  int mstime = mstime_get();

 

  printf("it took %dms \n", mstime);

 

  printf("had %d changes \n", changeCounter);

 

  printf("ESR is %.0f", ((float)changeCounter)/((float)mstime)*1000);

}
