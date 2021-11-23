#include "instrument.h"
#include <iostream>

int main(){
   Instrument flute("fffuuuuu"); //use Intrument class for flute
   Instrument synth("airhorns");
   flute.play(); //excecute the play() function for the class instance of flute
   synth.play();
}
