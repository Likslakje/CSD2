//Original credits for AudioManger go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/taylorSwift/csd2b/theorie/xx_eindopdrachtExamples/07_choicesSynth

#include "audioManager.h"
#define WRITE_TO_FILE 0

AudioManager::AudioManager(char **argv) : effect(EffectType::NONE)
{
#if WRITE_TO_FILE

  WriteToFile fileWriter("output.csv", true);
  samplerate = 44100;
#else
  //create a new jack module


  // inbuf = (float*) malloc(chunkSize * sizeof(float));
  // memset (inbuf, 0, chunkSize * sizeof(float));
  // outbuf = (float*) malloc(chunkSize * sizeof(float));
  // memset (outbuf, 0, chunkSize * sizeof(float));

  jack = new JackModuleStereo();

  //set output and input channels
  jack->setNumberOfInputChannels(1);
  jack->setNumberOfOutputChannels(2);

  //give program name to jack
  jack->init(argv[0]);
  samplerate = jack->getSamplerate();

  // makeEffect(effect);
  // assignAudioCallback();
  jack->autoConnect();

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
    case MODDELAY:
      return "modDelay";
    case CHORUS:
      return "chorus";
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
  std::string* delayTimeOptions = new std::string[Delay::BufferSizeType::SIZE];
    for(int i = 0; i < Delay::BufferSizeType::SIZE; i++) {
    delayTimeOptions[i] = delayTimeEnumToString((Delay::BufferSizeType )i);
  }
  // retrieve the user selection in form of an enum
  Delay::BufferSizeType delayTimeType = (Delay::BufferSizeType)
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

float AudioManager::setDelayTime(Delay::BufferSizeType delayTimeType){
  std::cout<< "Please set delay time: " <<std::endl;
  //get size of enum type for max range
  int maxSize = Delay::selectSize(samplerate, delayTimeType);
  float delayTime = UserInput::retrieveValueInRange(0, maxSize);
  return delayTime;
}

float AudioManager::setDelayFeedback(){
  std::cout<< "Please set feedback amount: " <<std::endl;
  float feedback = UserInput::retrieveValueInRange(0, 1);
  return feedback;
}

float AudioManager::setModDelayModDepth(Delay::BufferSizeType delayTimeType){
   std::cout<< "Please set modulation depth: " <<std::endl;
  int maxSize = Delay::selectSize(samplerate, delayTimeType);
  float modDepth = UserInput::retrieveValueInRange(0, maxSize);
  return modDepth;
}

float AudioManager::setChorusBufferSize(){
  //get size of enum type for max range
  //buffer is always short
  int maxSize = Delay::selectSize(samplerate, Delay::BufferSizeType::SHORT);
  float modDepth = UserInput::retrieveValueInRange(0, maxSize);
  return modDepth;
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

  // std::cout<< "Please enter dry/wet ratio: " <<std::endl;
  // float dryWet = UserInput::retrieveValueInRange(0, 1);
  float dryWet = 0.6;
  bool bypass = false;

  // actual effect choosing
  switch (effectType){
    case TREMOLO: {
      Modulation::WaveformType waveformType = waveformTypeSelection();
      float modFreq = setModFreq();
      std::cout<< "samplerate " << samplerate <<std::endl;
      std::cout<< "drywet " << dryWet <<std::endl;
      std::cout<< "bypass " << bypass <<std::endl;
      std::cout<< "waveformType " << waveformType <<std::endl;
      std::cout<< "modFreq " << modFreq <<std::endl;
      audioEffect = new Modulation(samplerate, dryWet, bypass, 
        waveformType, modFreq);  
      break;
    }
    case SIMPLEDELAY: {
      Delay::BufferSizeType delayTimeType = delayTimeSelection();
      //give the delayTimeType to the function so ze can set the max
      float delayTime = setDelayTime(delayTimeType);
      float feedback = setDelayFeedback();
      audioEffect = new Delay(samplerate, dryWet, bypass,
        delayTimeType, delayTime, feedback);
      break;
    }
    case MODDELAY: {
      Delay::BufferSizeType delayTimeType = delayTimeSelection();
      //give the delayTimeType to the function so ze can set the max
      float delayTime = setDelayTime(delayTimeType);
      float feedback = setDelayFeedback();
      float modFreq = setModFreq();
      float modDepth = setModDelayModDepth(delayTimeType);
      audioEffect = new ModDelay(samplerate, dryWet, bypass, 
        delayTimeType, delayTime, feedback, modFreq, modDepth);
      break;
    }
    case CHORUS: {
      //bufferSize = always short
      float delayTime = setDelayTime(Delay::BufferSizeType::SHORT);
      float feedback = setDelayFeedback();
      float modFreq = setModFreq();
      float modDepth = setModDelayModDepth(Delay::BufferSizeType::SHORT);
      audioEffect = new ModDelay(samplerate, dryWet, bypass,
      Delay::BufferSizeType::SHORT, delayTime, feedback, modFreq, modDepth);
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
  std::cout<< "inside audiocCallback " <<std::endl;
  std::cout<< "inbuf " << inbuf <<std::endl;
  jack->readSamples(inbuf, chunkSize);
  std::cout<< "chunksize " << chunkSize <<std::endl;
  for(unsigned int i = 0; i < chunkSize; i ++){
    std::cout<< inbuf[i] <<std::endl;
    //left channel
    // outbuf[i], outbuf[i + 1] = audioEffect->bypassOrApply(inbuf[i]);
    outbuf[2 * i] = inbuf[i];
    outbuf[2 * i + 1] = inbuf[i];
    // outbuf[i + 1] = inbuf[i];
    //right channel
    // outbuf[i + 1] = audioEffect->bypassOrApply(inbuf[i]);
  }
  jack->writeSamples(outbuf,chunkSize *2);
}

void AudioManager::end(){
  jack->end();
  delete audioEffect;
  audioEffect = nullptr;
}