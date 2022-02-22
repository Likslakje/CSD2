#include <iostream>
#include <thread>
#include "math.h"
#include "../../utilities/audioManager.h"

/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

#define WRITE_TO_FILE 1
#define WRITE_NUM_SAMPLES 44100

int numEffects = 2;
std::string effectOptions[2] = {"tremolo", "simpleDelay"};

int main(int argc,char **argv)
{
  AudioManager audioManager(argv);

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  // boolean is used to keep program running / turn it off
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        audioManager.end();
        break;
      }
  }

  //end the program
  return 0;

} // main()
