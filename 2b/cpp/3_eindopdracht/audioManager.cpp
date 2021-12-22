#include "audioManager.h"
#include "melody.h"
#include "AM.h"
#include "FM.h"
#include "writeToFile.h"

#define WRITE_TO_FILE 0

AudioManager::AudioManager() : synth(nullptr), masterAmp(0.15), frameIndex(0)
{
  // call method that handles assignment of onProcess function for
  // JackModule
  // TODO - why does the program 'break' when I use cin immediately after
  // calling init
#if WRITE_TO_FILE

  WriteToFile fileWriter("output.csv", true);
  samplerate = 44100;
  changeSynth();
  // set first note of the melody as midiPitch
  updatePitch();

  for(int i = 0; i < 1000; i++) {
    fileWriter.write(std::to_string(synth->getSample()) + "\n");
    synth->tick();
  }
#else

  jack = new JackModule();
  jack->init("example");
  samplerate = jack->getSamplerate();
  // set default frameInterval
  frameInterval = samplerate;

  makeMelody();
  // create synth based on user input
  changeSynth();
  // set first note of the melody as midiPitch
  updatePitch();

  assignAudioCallback();
  // start audio!
  jack->autoConnect();
#endif

}

AudioManager::~AudioManager()
{
  // if synth is assigned to dynamic allocated Synth object- delete it
  deleteSynth();
}

void AudioManager::makeMelody(){
  //get user input, append to array
  int numChars = UserInput::retrieveMelodyInput();
  // int numWarpedChars;
  int modulo;
  modulo = numChars % NUM_NOTES;
  melody.setCharHop(modulo);
}

void AudioManager::setMelody(){
  //retrun melody to melody class
}

bool AudioManager::changeSynth()
{
  // create a string array with the synth type options
  std::string* synthTypeOptions = new std::string[SynthType::Size];
  for(int i = 0; i < SynthType::Size; i++) {
     synthTypeOptions[i] = synthTypeToString((SynthType)i);
  }

  // retrieve the user selection in form of an enum
    this->synthType = (SynthType)
    UserInput::retrieveSelectionIndex(synthTypeOptions, SynthType::Size);

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

  // create a string array with the waveform type options
  std::string* waveformOptions = new std::string[Synth::Waveform::Size];
  for(int i = 0; i < Synth::Waveform::Size; i++) {
     waveformOptions[i] = Synth::waveformTypeToString((Synth::Waveform)i);
  }

  // retrieve the user selection in form of an enum
  Synth::Waveform waveformType = (Synth::Waveform)
    UserInput::retrieveSelectionIndex(waveformOptions, Synth::Waveform::Size);

  switch(synthType) {
    case AMSynthType:
      synth = new AMSynth(waveformType, samplerate);
      break;
    case FMSynthType:
      synth = new FMSynth(waveformType, samplerate);
      break;
    default:
      std::cout << "• AudioManager::changeSynth - unknown synth type" << std::endl;
      // failed assinging new synth
      return false;
  }

  return true;
}

void AudioManager::updatePitch() {
  float pitch = melody.getPitch();
#if DEBUG >= 1
  std::cout << "• AudioManager::updatePitch - pitch " << pitch << std::endl;
#endif
  synth->setMPitch(pitch);
}


void AudioManager::assignAudioCallback()
{
  // TODO - add method to AudioManager to set the franeInterval in seconds
  // e..g. 0.1 --> 0.1 * samplerate inside method
  frameInterval = 0.5 * samplerate;
  // start with the first pitch
  updatePitch();
  // assign a function to the JackModule::onProces
  // NOTE: an empty process loop, just to log current synth
  jack->onProcess = [this](jack_default_audio_sample_t *inBuf,
    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
    // fill output buffer
    for(unsigned int i = 0; i < nframes; i++) {

      // check if we need to set the frequency to the next note
      if(frameIndex >= frameInterval) {
        // reset frameIndex
        frameIndex = 0;
        updatePitch();
      } else {
        // increment frameindex
        frameIndex++;
      }

      // write sample to output
      outBuf[i] = synth->getSample() * masterAmp;

      // calculate next sample
      synth->tick();

    }
    return 0;
  };
  //   // fill output buffer
  //   for(unsigned int i = 0; i < nframes; i++) {
  //     // write sample to output
  //     //TODO Cis
  //     if(synth != nullptr) {
  //       outBuf[i] = synth->getSample();
  //       // calculate next sample
  //       synth->tick();
  //     } else {
  //       outBuf[i] = 0;
  //     }
  //   }

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
    // delete current synth
    delete synth;
    synth = nullptr;
  }
}
