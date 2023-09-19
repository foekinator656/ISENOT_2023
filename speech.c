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
 talk * test = talk_run(7, -1);
 talk_say(test, "ffffffff");
 sd_mount(22, 23, 24, 25);
 wav_volume(5);
 while(1){
    pause(150);
    talk_say(test, "nyaaan");
    if(!wav_playing()){
       wav_play("BIRD.WAV");
      }
  }
}
