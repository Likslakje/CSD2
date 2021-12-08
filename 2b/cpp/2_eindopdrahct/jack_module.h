//All credits for writeToFile, Sine and basically all the other types of oscillators
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga

#ifndef _JACK_MODULE_H_
#define _JACK_MODULE_H_

#include <string>
#include <functional>
#include <jack/jack.h>

class JackModule
{
public:
  JackModule();
  ~JackModule();
  int init();
  int init(std::string clientName);
  unsigned long getSamplerate();
  void autoConnect();
  void end();
  //the onProcess function that needs to be assigned to a JackModule object
  std::function <int(jack_default_audio_sample_t *,
     jack_default_audio_sample_t *, jack_nframes_t)> onProcess;

private:
  static int _wrap_jack_process_cb(jack_nframes_t nframes,void *arg);
  jack_client_t *client;
  const char **ports;
};

#endif
