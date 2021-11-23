#include <iostream>

class Instrument{
    public:
        Instrument(std::string sound_descrpt); //for excecution
        ~Instrument(); //no excecution
        void play();
        std::string sound; //point to standard, make string named sound
};