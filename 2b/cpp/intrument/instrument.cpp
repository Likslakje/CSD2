#include <iostream>
 //make yo life easier

class Instrument{
public:
    Instrument(std::string sound_descrpt); //for excecution
    ~Instrument(); //no excecution
    void play();
    std::string sound; //point to standard, make string named sound
};

Instrument::Instrument(std::string sound_descrpt){
    sound = sound_descrpt; //assing value to sound string
}

Instrument::~Instrument(){

}

void Instrument::play(){
    std::cout << sound <<std::endl; //print 
}

int main(){
   Instrument flute("fffuuuuu"); //use Intrument class for flute
   Instrument synth("airhorns");
   flute.play(); //excecute the play() function for the class instance of flute
   synth.play();
}