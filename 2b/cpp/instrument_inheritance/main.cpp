#include <iostream>
using namespace std;
#include "string.h"
// #include "key.h"
// #include "wind.h"
// #include "perc.h"

int main(){
    // Give every intrument subclass an intrumentname, a descriptive sound and a note in Hz
    String guitar("guitar", "IIEWWWIIWW", 350);
    guitar.pitchRangeCheck();
    

    
    // String violin("violin", "KKKGGGIIIEE", 3458);
    // violin.play();

    // Key piano("piano", "PING");
    // piano.play();
    // Key DX7("DX7", "PJIEW");
    // DX7.play();

    // Wind saxophone("saxophone", "AUWAWA");
    // saxophone.play();

    // Percussion taiko("taiko", "BIEM");
    // taiko.play();
     
    return 0;
}