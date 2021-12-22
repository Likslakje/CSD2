//All credits for AudioManger go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/taylorSwift/csd2b/theorie/xx_eindopdrachtExamples/07_choicesSynth

#include "audioManager.h"
#include "melody.h"
#include "AM.h"
#include "FM.h"
#include "writeToFile.h"

#define WRITE_TO_FILE 0

AudioManager::AudioManager() : modSynth(nullptr), masterAmp(0.15), frameIndex(0)
{
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
  //run Cate bitch...
  jack->init("cate");
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

void AudioManager::makeMelody()
{
  //get user input, count num chars
  int numChars = UserInput::retrieveMelodyInput();
  // wrap numChars by using modulo
  int modulo;
  modulo = numChars % NUM_NOTES;
  //hop through melody array
  melody.setCharHop(modulo);
}

bool AudioManager::changeSynth()
{
  // create a string array with the synth type options from enum 
  //print them as string
  std::string* synthTypeOptions = new std::string[SynthType::Size];
  for(int i = 0; i < SynthType::Size; i++) {
     synthTypeOptions[i] = synthTypeToString((SynthType)i);
  }

  // retrieve the user selection in form of an enum
  synthType = (SynthType)
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
  std::string* waveformOptions = new std::string[ModSynth::Waveform::Size];
  for(int i = 0; i < ModSynth::Waveform::Size; i++) {
     waveformOptions[i] = ModSynth::waveformTypeToString((ModSynth::Waveform)i);
  }

  // retrieve the user selection in form of an enum
  ModSynth::Waveform waveformType = (ModSynth::Waveform)
    UserInput::retrieveSelectionIndex(waveformOptions, ModSynth::Waveform::Size);

  //creat a synth with the selected SynthType and WaveformType
  switch(synthType) {
    case AMSynthType:
      modSynth = new AMSynth(waveformType, samplerate);
      break;
    case FMSynthType:
      modSynth = new FMSynth(waveformType, samplerate);
      break;
    default:
      std::cout << "• AudioManager::changeSynth - unknown synth type" << std::endl;
      // failed assinging new synth
      return false;
  }
  return true;
}

void AudioManager::updatePitch() 
{
  //function gets called depending on frameInterval
  //get midinumber from melody array
  float pitch = melody.getPitch();
#if DEBUG >= 1
  std::cout << "• AudioManager::updatePitch - pitch " << pitch << std::endl;
#endif
  //convert midinumber to frequency and set pitch of oscillators
  modSynth->setMPitch(pitch);
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
      outBuf[i] = modSynth->getSample() * masterAmp;

      // calculate next sample
      modSynth->tick();

    }
    return 0;
  };
}

void AudioManager::end()
{
  //end jack
  std::cout << "• AudioManager::end - ending jack process." << std::endl;
  jack->end();
}

std::string AudioManager::synthTypeToString(SynthType type)
{
  //Return selected synth from enum as string
  switch(type) {
  case AMSynthType:
      return "AM";
    case FMSynthType:
      return "FM";
    default:
      return "Invalid Synth";
  }
}


void AudioManager::deleteSynth()
{
  //if a synth object is created then delete it
  if(modSynth != nullptr) {
    // delete current synth
    delete modSynth;
    modSynth = nullptr;
  }
}
