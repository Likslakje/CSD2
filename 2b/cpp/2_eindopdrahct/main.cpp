//All credits for writeToFile, synth and basically all the other types of oscillators
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#include <iostream>
#include <thread>
#include <limits>
#include "jack_module.h"
#include "writeToFile.h"
#include "math.h"
// #include "sine.h"
// #include "saw.h"
// #include "square.h"
// #include "synth.h"
#include "additive.h"
#include "beating.h"
using namespace std;

#define WRITETOFILE 1

int main(int argc,char **argv){
  // double samplerate = 44100;
  // Additive additiveSynth(34, samplerate);
  // Beating beatingSynth(44, samplerate);
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();
    // double samplerate = 44100;
  Beating synth(60, samplerate);
  cout<< synth.getSample() <<endl;
    // while(true){
    //   synth.calculate();
    // };
  
// #if WRITETOFILE 
//   WriteToFile fileWriter("output.csv", true);
//   for(int i = 0; i < 3000; i++) {
//     fileWriter.write(std::to_string(synth.getSample()) + "\n");
//     synth.nextSample();
//   }
// #else
  float amplitude = 0.15;
  //assign a function to the JackModule::onProces
  jack.onProcess = [&synth, &amplitude](jack_default_audio_sample_t *inBuf,
    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = synth.getSample() * amplitude;
      synth.nextSample();
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
  return 0;
}