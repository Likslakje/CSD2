#include <iostream>
using namespace std;
#include "string.h"
#include "key.h"
#include "wind.h"
#include "perc.h"

int main(){
    // Give every intrument subclass an intrumentname, a descriptive sound and a note in Hz
    String guitar("guitar", "IIEWWWIIWW", 45);
    guitar.pitchRangeCheck();
    String violin("violin", "KKKGGGIIIEE", 127);
    violin.pitchRangeCheck();

    Key piano("piano", "PING", 75);
    piano.pitchRangeCheck();
    Key DX7("DX7", "PJIEW", 12);
    DX7.pitchRangeCheck();

    Wind saxophone("saxophone", "AUWAWA", 20);
    saxophone.pitchRangeCheck();

    Percussion taiko("taiko", "BIEM", 63);
    taiko.pitchRangeCheck();
     
    return 0;
}