#include <iostream>
using namespace std;
#include "string.h"

String::String(string name, string soundDes, float note) : Instrument(name, soundDes, note){
    cout<< "String: " <<endl;
    this-> lowHz = 80;
    this-> highHz = 3500;
}

String::~String(){
    // cout<< lowHz <<endl;
}

void String::pitchRangeCheck(){
    if(note >= lowHz && note <= highHz){
        Instrument::play(" is playing");
    }else{
        Instrument::play(" pitch is out of range");
    }
}