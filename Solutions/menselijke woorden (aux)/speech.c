/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simple tools
#include <stdint.h>
#include "text2speech.h"
#include "wavplayer.h "


int main()                                    // Main function
{
 talk * test = talk_run(27, 26);
 talk_setVolume(test, 7);

 while(1){
    pause(2000);
    talk_say(test, "automatische frituur");
  }
}
