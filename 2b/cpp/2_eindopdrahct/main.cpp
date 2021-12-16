//All credits for writeToFile, synth and basically all the other types of oscillators
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#include <iostream>
#include <thread>
#include <limits>
#include "jack_module.h"
#include "writeToFile.h"
#include "math.h"
#include "sine.h"
#include "saw.h"
#include "square.h"
#include "synth.h"
#include "additive.h"
#include "beating.h"
#include "lfo.h"
#include "userInput.h"
using namespace std;
#define WRITE_TO_FILE 0

int main(int argc,char **argv){
  // JackModule jack;
  // jack.init(argv[0]);
  // double samplerate = jack.getSamplerate();
  double samplerate = 44100;

  UserInput userInput;
  while(!userInput.terminate)
  userInput.commands();

  // Lfo synth(60, samplerate);
  // for(int i = 0; i < 3000; i++) {
  //   synth.typeSynthNextSample();
  // }

  // Square synth(45, samplerate);
  // for(int i = 0; i < 3000; i++) {
  //   synth.nextSample();
  // }
  

  #if WRITE_TO_FILE
    
    // WriteToFile fileWriter("output.csv", true);
    // for(int i = 0; i < 8000; i++) {
    //   fileWriter.write(std::to_string(synth.getTypeSynthSample()) + "\n");
    //   synth.typeSynthNextSample();
    // }
  #else
    // Saw sine(440, samplerate);
    // WriteToFile fileWriter("output.csv", true);
    // for(int i = 0; i < 3000; i++) {
    //   fileWriter.write(std::to_string(sine.getSample()) + "\n");
    //   sine.nextSample();
    // }

  #endif
 #if 0
  float amplitude = 0.15;
  //assign a function to the JackModule::onProces
  jack.onProcess = [&synth, &amplitude](jack_default_audio_sample_t *inBuf,
    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = synth.getTypeSynthSample() * amplitude;
      synth.typeSynthNextSample();
    }
    amplitude = 0.5;
    return 0;
  };

  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        jack.end();
        break;
    }
  }
 #endif
  return 0;
}