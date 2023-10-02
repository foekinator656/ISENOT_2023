/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simple tools



int main()                                    // main function             
{
  outputwaveup(2200,3000, 40);
  outputwavedown(2900,3000, 5);
  square_wave_stop();
  
}


void outputwaveup(int low, int high, int duration){
  int current = low;
  for(;current<high;current = current+(high-low)/duration){
    square_wave(10, 0, current);
    pause(10);
  }
}


void outputwavedown(int low, int high, int duration){
  int current = high;
  for(;current>low;current = current-(high-low)/duration){
    square_wave(10, 0, current);
    pause(10);
  }
}

void outputwaveupanddown(int low, int high, int duration){
    outputwaveup( low,  high, duration);
    outputwavedown( low,  high, duration);
}
