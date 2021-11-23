#include "instrument.h"
#include <iostream>

Instrument::Instrument(std::string sound_descrpt){
    sound = sound_descrpt; //assing value to sound string
}

Instrument::~Instrument(){

}

void Instrument::play(){
    std::cout << sound <<std::endl; //print 
}