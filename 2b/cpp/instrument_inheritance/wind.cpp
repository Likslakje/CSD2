#include <iostream>
using namespace std;
#include "wind.h"

Wind::Wind() : Instrument(){
    cout<< "Wind: " <<endl;
    this-> lowHz = 40;
    this-> highHz = 2500;
}

Wind::~Wind(){

}

void Wind::pitchRangeCheck(){
    if(note >= lowHz && note <= highHz){
        Instrument::play(" is playing", soundDes);
    }else{
        Instrument::play(" pitch is out of range", "*insert crickets");
    }
}