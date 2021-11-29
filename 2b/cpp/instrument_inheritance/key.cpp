#include <iostream>
using namespace std;
#include "key.h"

Key::Key() : Instrument(){
    cout<< "Key: " <<endl;
    this-> lowHz = 20;
    this-> highHz = 10000;
}

Key::~Key(){

}

void Key::pitchRangeCheck(){
    if(note >= lowHz && note <= highHz){
        Instrument::play(" is playing", soundDes);
    }else{
        Instrument::play(" pitch is out of range", "*insert crickets");
    }
}