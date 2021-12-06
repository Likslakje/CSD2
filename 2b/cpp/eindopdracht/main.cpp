//All credits for writeToFile, Sine and the structure for every type of oscillator 
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#include <iostream>
#include <thread>
#include "math.h"
#include "sine.h"
#include "tri.h"
#include "saw.h"
#include "square.h"
#include "additive.h"
#include "writeToFile.h"
#include "jack_module.h"
#include "input.cpp"
using namespace std;

// double samplerateGeneral = 44100;

int main(int argc,char **argv){
  Additive additiveSynth(4);
    // execute();
    // create a JackModule instance
  // JackModule jack;
  // // init the jack, use program name as JACK client name
  // jack.init(argv[0]);
  // double samplerate = jack.getSamplerate();
  //   samplerateGeneral = samplerate;
  
  //     // cout<< "Press ? for help or type 'help'\nType command: ";

    //  Sine sine(220, samplerateGeneral);
    //  Triangle tri(330, samplerate);
    //  Saw saw(440, samplerate);
    //  Square sine(550, samplerate);


  // float amplitude = 0.15;
  // //assign a function to the JackModule::onProces
  // jack.onProcess = [&sine, &amplitude](jack_default_audio_sample_t *inBuf,
  //   jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

  //   for(unsigned int i = 0; i < nframes; i++) {
  //     outBuf[i] = sine.getSample() * amplitude;
  //     sine.tick();
  //   }
  //   amplitude = 0.5;
  //   return 0;
  // };

  // jack.autoConnect();

  // //keep the program running and listen for user input, q = quit
  // std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  // bool running = true;
  // while (running)
  // {
  //   switch (std::cin.get())
  //   {
  //     case 'q':
  //       running = false;
  //       jack.end();
  //       break;
  //   }
  // }
    return 0;
}
