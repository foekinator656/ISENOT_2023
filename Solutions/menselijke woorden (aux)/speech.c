/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simple tools
#include <stdint.h>
#include "text2speech.h"
#include "wavplayer.h "

#define timequote "the time has come and so have I"
#define bday "happy birthday"
#define cmas "merry christmas"
#define horror "WHY"


int main()                                    // Main function
{
 talk * test = talk_run(27, 26);
 talk_setVolume(test, 7);
 sd_mount(22, 23, 24, 25);
  wav_volume(5);

 while(1){
    pause(2000);
    talk_say(test, horror);
    wav_play("scream.wav");
  }
}
