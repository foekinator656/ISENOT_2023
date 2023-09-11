#include "simpletools.h"                      // Include simpletools header
#include "ping.h"                             // Include ping header

int main()                                    // main function
{
  while(1)                                    // Repeat indefinitely
  {
    low(4);
    low(13);
    int cmDist = ping_cm(8);                 // Get cm distance from Ping)))
    print("cmDist = %d\n", cmDist);           // Display distance
    if(cmDist < 10){
        freqout(4, 200, 3000);
        high(13);
    }
    else{
         freqout(4, 200, 2500);
    }
    pause(200);                               // Wait 1/5 second
  }
}
