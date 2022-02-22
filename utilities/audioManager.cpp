//All credits for AudioManger go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/taylorSwift/csd2b/theorie/xx_eindopdrachtExamples/07_choicesSynth

#include "audioManager.h"
#define WRITE_TO_FILE 0

AudioManager::AudioManager(char **argv) : effect(EffectType::NONE)
{
#if WRITE_TO_FILE

  WriteToFile fileWriter("output.csv", true);
  samplerate = 44100;
#else

  jack = new JackModule();
  //give program name to jack
  jack->init(argv[0]);
  samplerate = jack->getSamplerate();

  makeEffect(effect);
  assignAudioCallback();
  std::cout<< "before auto connect" <<std::endl;
  jack->autoConnect();
  std::cout<< "after auto connect" <<std::endl;

#endif
}

AudioManager::~AudioManager()
{
  delete audioEffect;
  audioEffect = nullptr;
}

std::string AudioManager::effectEnumToString(EffectType type)
{
  //Return selected synth from enum as string
  switch(type) {
  case TREMOLO:
      return "tremolo";
    case SIMPLEDELAY:
      return "simpleDelay";
    default:
      return "Invalid effect";
  }
}

std::string AudioManager::waveformEnumToString(Modulation::WaveformType waveform){
  switch (waveform)
  {
  case Modulation::WaveformType::SINE:
    return "sine";
    break;
  case Modulation::WaveformType::SAW:
    return "saw";
    break;
  case Modulation::WaveformType::SQUARE:
    return "square";
    break;
  default:
    throw "Please choose an excisting waveform";
    break;
  }
}

std::string AudioManager::delayTimeEnumToString(Delay::BufferSizeType delayTime){
    switch (delayTime)
  {
  case Delay::BufferSizeType::SHORT:
    return "short";
    break;
  case Delay::BufferSizeType::MID:
    return "mid";
    break;
  case Delay::BufferSizeType::LONG:
    return "long";
    break;
  default:
    throw "Please choose an excisting delayTimeType";
    break;
  }
}

Modulation::WaveformType AudioManager::waveformTypeSelection(){
  //make string of Enum options
  std::string* wavefromOptions = new std::string[Modulation::WaveformType::SIZE];
    for(int i = 0; i < Modulation::WaveformType::SIZE; i++) {
    wavefromOptions[i] = waveformEnumToString((Modulation::WaveformType)i);
  }
  // retrieve the user selection in form of an enum
  Modulation::WaveformType waveformType = (Modulation::WaveformType)
  UserInput::retrieveSelectionIndex(wavefromOptions, Modulation::WaveformType::SIZE);

  delete [] wavefromOptions;
  wavefromOptions = nullptr;

  return waveformType;
}

Delay::BufferSizeType AudioManager::delayTimeSelection(){
    //make string of Enum options
  std::string* delayTimeOptions = new std::string[Delay::BufferSizeType ::SIZE];
    for(int i = 0; i < Delay::BufferSizeType ::SIZE; i++) {
    delayTimeOptions[i] = delayTimeEnumToString((Delay::BufferSizeType )i);
  }
  // retrieve the user selection in form of an enum
  Delay::BufferSizeType delayTimeType = (Delay::BufferSizeType )
  UserInput::retrieveSelectionIndex(delayTimeOptions, Delay::BufferSizeType::SIZE);

  delete [] delayTimeOptions;
  delayTimeOptions = nullptr;

  return delayTimeType;
}

float AudioManager::setModFreq(){
  std::cout<< "Please set modulation frequency: " <<std::endl;
  float modFreq = UserInput::retrieveValueInRange(0, 100);
  return modFreq;
}

float AudioManager::setDelayTime(){
  std::cout<< "Please set delay time: " <<std::endl;
  //TODO: get size of enum type for max range
  float delayTime = UserInput::retrieveValueInRange(0, 10000);
  return delayTime;
}

void AudioManager::makeEffect(EffectType effect){
    //choose effect
  // make string of Enum options
  std::string* effectOptions = new std::string[EffectType::SIZE];
    for(int i = 0; i < EffectType::SIZE; i++) {
     effectOptions[i] = effectEnumToString((EffectType)i);
  }
  // std::string userSelection = UserInput::retrieveSelection(effectOptions, EffectType::SIZE);
  // retrieve the user selection in form of an enum
  EffectType effectType = (EffectType)
  UserInput::retrieveSelectionIndex(effectOptions, EffectType::SIZE);

  std::cout<< "Please enter dry/wet ratio: " <<std::endl;
  float dryWet = UserInput::retrieveValueInRange(0, 1);

  bool bypass = false;

  // actual effect choosing
  switch (effectType){
    case TREMOLO: {
      Modulation::WaveformType delayTimeType = waveformTypeSelection();
      float modFreq = setModFreq();
      audioEffect = new Tremolo(samplerate, dryWet, bypass, 
        delayTimeType, modFreq);  
      break;
    }
    case SIMPLEDELAY: {
      Delay::BufferSizeType delayTimeType = delayTimeSelection();
      float delayTime = setDelayTime();
      audioEffect = new SimpleDelay(samplerate, dryWet, bypass,
        delayTimeType, delayTime);
      break;
    }
    default:{
      throw "If it does not appear in our database, it does not excist";
      break;
    }
  }
  effect = effectType;

  //release the string to enum pointer
  delete [] effectOptions;
  effectOptions = nullptr;
}

void AudioManager::assignAudioCallback()
{
  // assign a function to the JackModule::onProces
  // NOTE: an empty process loop, just to log current synth
  jack->onProcess = [this](jack_default_audio_sample_t *inBuf,
    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    // fill output buffer
    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = audioEffect->applyEffect(inBuf[i]) * amplitude;
    }
    return 0;
  };
}

void AudioManager::end(){
  jack->end();
}