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
#include "oscillator.h"
#include "AM.h"
#include "FM.h"
#include "userInput.h"
using namespace std;
#define WRITE_TO_FILE 0

int main(int argc,char **argv){
  UserInput userInput;
  // int numtypeSynths = 2;
  // Synth* typeSynths[2] = {new AM(0, 0), new FM(0, 0)};
  // // JackModule jack;
  // // jack.init(argv[0]);
  // // double samplerate = jack.getSamplerate();
  // double samplerate = 44100;
  // while(!userInput.terminate){
  //   userInput.commands();
  // }

  // create a string array with the synth type options
  string* synthOptions = new string[Synth::TypeSynth::Size];
  for(int i = 0; i < Synth::TypeSynth::Size; i++) {
     synthOptions[i] = Synth::synthTypeToString((Synth::TypeSynth)i);
  }

  // retrieve the user selection in form of an enum
  Synth::TypeSynth synthType = (Synth::TypeSynth)
    UserInput::retrieveSelectionIndex("synth", synthOptions, Synth::TypeSynth::Size);

  Synth synth;

  // create a string array with the waveform type options
  string* waveformOptions = new string[Oscillator::Waveform::Size];
  for(int i = 0; i < Oscillator::Waveform::Size; i++) {
     waveformOptions[i] = Oscillator::waveformTypeToString((Oscillator::Waveform)i);
  }

  // retrieve the user selection in form of an enum
  Oscillator::Waveform waveType = (Oscillator::Waveform)
    UserInput::retrieveSelectionIndex("waveform", waveformOptions, Oscillator::Waveform::Size);

  Oscillator osc;

  // use waveform of user's choice
  osc.setWaveform(waveType);

  

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