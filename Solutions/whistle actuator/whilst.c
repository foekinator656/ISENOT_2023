/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simple tools
#define piezopin 10
int main()                                    // main function             
{
  outputwaveup(2500,3500, 20);
  outputwavedown(3000,3500, 20);
  square_wave_stop();
  pause(500);
  outputwavedown(3800,4300, 20);
  outputwaveup(3800,4300, 20);
  square_wave_stop();
}


void outputwaveup(int low, int high, int duration){
  int current = low;
  for(;current<high;current = current+(high-low)/duration){
    square_wave(piezopin, 0, current);
    pause(10);
  }
}


void outputwavedown(int low, int high, int duration){
  int current = high;
  for(;current>low;current = current-(high-low)/duration){
    square_wave(piezopin, 0, current);
    pause(10);
  }
}

void outputwaveupanddown(int low, int high, int duration){
    outputwaveup( low,  high, duration);
    outputwavedown( low,  high, duration);
}
