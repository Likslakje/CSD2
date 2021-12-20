#include "audioManager.h"
#include "AM.h"
#include "FM.h"
AudioManager::AudioManager() : synth(nullptr)
{
  jack = new JackModule();
  jack->init("example");
  // call method that handles assignment of onProcess function for
  // JackModule
  // TODO - why does the program 'break' when I use cin immediately after
  // calling init
  assignAudioCallback();
  // create synth based on user input
  changeSynth();
  // start audio!
  jack->autoConnect();
}

AudioManager::~AudioManager()
{
  // if synth is assigned to dynamic allocated Synth object- delete it
  deleteSynth();
}

int AudioManager::getNumFrequencies(){
  return numFrequencies;
}

bool AudioManager::changeSynth()
{
  // create a string array with the synth type options
  std::string* synthTypeOptions = new std::string[SynthType::Size];
  for(int i = 0; i < SynthType::Size; i++) {
     synthTypeOptions[i] = synthTypeToString((SynthType)i);
  }

  // retrieve the user selection in form of an enum
  SynthType synthType = (SynthType)
    userInput::retrieveSelectionIndex(synthTypeOptions, SynthType::Size);

  // release the dynamic synth array
  delete [] synthTypeOptions;
  synthTypeOptions = nullptr;

  // create the by the user selected synth type
  return changeSynth(synthType);
}

bool AudioManager::changeSynth(SynthType synthType)
{
  // if synth is assigned to dynamic allocated Synth object- delete it
  deleteSynth();
  // double carFreq = userInput::retrieveValueInRange(20, 20000);
  // double modFreq = userInput::retrieveValueInRange(20, 20000);
  const double samplerate = jack->getSamplerate();
  // set freq
  // double carFreq = 400;
  // double modFreq = 440;
  switch(synthType) {
    case AMSynthType:
      //the set frequncy fills up the frquency array
      //these frequencies are used to set their respective oscillators
      makeSynth(samplerate);
      synth = new AMSynth(waveformType, frequencies, samplerate);
      break;
    case FMSynthType:
      makeSynth(samplerate);
      synth = new FMSynth(waveformType, frequencies, samplerate);
      break;
    default:
      std::cout << "• AudioManager::changeSynth - unknown synth type" << std::endl;
      // failed assinging new synth
      return false;
  }

  return true;
}

void AudioManager::setWaveform(double samplerate){
  //als case synthtype voor deze functie uit
  //moet synthtype hebben om de hoeveel osc te weten
  //deze functies moet aantal keer als osc uitgevoerd
    // create a string array with the waveform type options
    std::string* waveformOptions = new std::string[Synth::Waveform::Size];
    for(int i = 0; i < Synth::Waveform::Size; i++) {
      waveformOptions[i] = Synth::waveformTypeToString((Synth::Waveform)i);
    }
    // retrieve the user selection in form of an enum
    Synth::Waveform waveformTypeSelection = (Synth::Waveform)
      userInput::retrieveSelectionIndex(waveformOptions, Synth::Waveform::Size);
    
    //after running the selection process, get the frequency
    // sinds we cannot make an new Oscillator type without a frequency
    setFrequency();

    switch (waveformTypeSelection)
  {
    case Synth::SineType:
      waveformType[waveformIndex] = new Sine(frequencies[waveformIndex], samplerate);
    break;
    case Synth::SawType:
      waveformType[waveformIndex] = new Saw(frequencies[waveformIndex], samplerate);
    break;
    case Synth::SquareType:
      waveformType[waveformIndex] = new Square(frequencies[waveformIndex], samplerate);
    break;
  default:
    /* code */
    break;
  }
}

void AudioManager::setFrequency(){
  this->frequencies[waveformIndex] = userInput::retrieveValueInRange(20, 20000);
}

void AudioManager::makeSynth(double samplerate){
  // this function excits because I didnt want to put a forloop inside the changeSynth()
  // during the switch process
  for(int i = 0; i < numFrequencies; i++){
    setWaveform(samplerate);
    waveformIndex++;
  }
}

void AudioManager::assignAudioCallback()
{
  // assign a function to the JackModule::onProces
  // NOTE: an empty process loop, just to log current synth
  jack->onProcess = [this](jack_default_audio_sample_t *inBuf,
    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    // fill output buffer
    for(unsigned int i = 0; i < nframes; i++) {
      // write sample to output

      if(synth != nullptr) {
        outBuf[i] = synth->getSample();
        // calculate next sample
        synth->tick();
      } else {
        outBuf[i] = 0;
      }
    }
    return 0;
  };
}

void AudioManager::end()
{
  std::cout << "• AudioManager::end - ending jack process." << std::endl;
  jack->end();
}

std::string AudioManager::synthTypeToString(SynthType type)
{
  switch(type) {
  case AMSynthType:
      return "AMSynth";
    case FMSynthType:
      return "FMSynth";
    default:
      return "Invalid Synth";
  }
}

void AudioManager::deleteSynth()
{
  if(synth != nullptr) {
    // delete all the waveforms used by a synth
    // delete current synth
    for(int i = 0; i < numFrequencies; i++){
      delete waveformType[i];
      waveformType[i] = nullptr;
    }
    delete synth;
    synth = nullptr;
  }
}
