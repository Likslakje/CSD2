//All credits for writeToFile, Triangle and basically all the other types of oscillators
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#include <iostream>
#include "triangle.h"
#include "math.h"
using namespace std;

Triangle::Triangle(double frequency, double samplerate) : Oscillator(frequency, samplerate){
    cout<< "constructor Triangle" <<endl;
}

Triangle::~Triangle(){
    cout<< "destructor Triangle" <<endl;
}

void Triangle::calculate(){
    if(phase < 0.5){
        sample = phase;
    }else{
        sample = (phase * -1) + 0.5;
    }
}

