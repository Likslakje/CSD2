#include <iostream>
#include "../../../CSD2_pull_voorbeelden/CSD_21-22/csd2c/sharedCode/utilities/writeToFile.h"
#include "../../../CSD2_pull_voorbeelden/CSD_21-22/csd2c/sharedCode/utilities/jack_module.h"
#include "../../../CSD2_pull_voorbeelden/CSD_21-22/csd2c/sharedCode/oscillators/sine.h"
#include "circularBuffer.h"


int main(int argc,char **argv){
  // CircBuf* circBuf;
  JackModule jack;
  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  unsigned int samplerate = jack.getSamplerate();
  float amplitude = 0.5;
  Sine sine(440, samplerate);
  //pointer to circbuf so we can create them with different 
  // default delay times
  CircBuf* circBuf;
  WriteToFile fileWriter("output.csv", true);

  std::cout<< "Please enter delay time type: \n0 = short(2 sec)\n 1 = mid (5 sec) \n 2 = long (10 sec)" 
    <<std::endl;
  std::string getUserDelayType;
  std::cin>> getUserDelayType;
  int userChoice = stoi(getUserDelayType);

  //create the type of delay dynamicly
  switch(userChoice){
    case 0:{
      circBuf = new CircBuf(samplerate, CircBuf::DelayTimeType::SHORT, 250);
      break;
    }
    case 1:{
      circBuf = new CircBuf(samplerate, CircBuf::DelayTimeType::MID, 500);
      break;
    }
    case 2:{
      circBuf = new CircBuf(samplerate, CircBuf::DelayTimeType::LONG, 1000);
      break;
    }
    default:
      throw "Just type a number man";
      break;
  }


  // assign a function to the JackModule::onProces
  jack.onProcess = [&amplitude, &sine, &fileWriter](jack_default_audio_sample_t* inBuf,
    jack_default_audio_sample_t* outBuf, jack_nframes_t nframes) {
    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = sine.genNextSample() * amplitude;
      // ----- write result to file -----
      static int count = 0;
      if(count < 441000) {
        fileWriter.write(std::to_string(outBuf[i]) + "\n");
      } else {
        // log 'Done' message to console, only once
        static bool loggedDone = false;
        if(!loggedDone) {
          std::cout << "\n**** DONE **** \n"
            << "Output is written to file.\n"
            << "Please enter 'q' to quit the program." << std::endl;
          loggedDone = true;
        }
      }
      count++;
      // set output to 0 to prevent issues with output
      outBuf[i] = 0;
    }

    return 0;
  };

  jack.autoConnect();

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
        jack.end();
        if(circBuf != nullptr){
          delete circBuf;
          circBuf = nullptr;
        }
        break;
      }
  }

  //end the program
  return 0;

} // main()
