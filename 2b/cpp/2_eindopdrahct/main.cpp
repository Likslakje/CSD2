//All credits for writeToFile, Sine and basically all the other types of oscillators
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
using namespace std;

int main(int argc,char **argv){
  double samplerate = 44100;
  Additive synth(34, samplerate);
  // synth.midiToFreq();
//   // create a JackModule instance
//   JackModule jack;

//   // init the jack, use program name as JACK client name
//   jack.init(argv[0]);
//   double samplerate = jack.getSamplerate();
//     // double samplerate = 44100;
//     Saw sine(220, samplerate);
//     // while(true){
//     //   sine.calculate();
//     // };

//   float amplitude = 0.15;
//   //assign a function to the JackModule::onProces
//   jack.onProcess = [&sine, &amplitude](jack_default_audio_sample_t *inBuf,
//     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

//     for(unsigned int i = 0; i < nframes; i++) {
//       outBuf[i] = sine.getSample() * amplitude;
//       sine.calculate();
//     }
//     amplitude = 0.5;
//     return 0;
//   };

//   jack.autoConnect();

//   //keep the program running and listen for user input, q = quit
//   std::cout << "\n\nPress 'q' when you want to quit the program.\n";
//   bool running = true;
//   while (running)
//   {
//     switch (std::cin.get())
//     {
//       case 'q':
//         running = false;
//         jack.end();
//         break;
//     }
//   }
// //   WriteToFile fileWriter("output.csv", true);
// //   for(int i = 0; i < samplerate; i++) {
// //     fileWriter.write(std::to_string(sine.getSample()) + "\n");
// //     sine.calculate();
// //   }
  return 0;
}