/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simple tools
#include "ping.h"                             // Include ping header

int main()                                    // Main function
{
  // Add startup code here.

 
  while(1)                                    // Repeat indefinitely
  {
    int cmDist = ping(8);                 // Get cm distance from Ping)))
    print("cmDist = %d\n", cmDist);           // Display distance
    pause(200);                               // Wait 1/5 second
  }
}
