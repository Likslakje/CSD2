#include <iostream>
using namespace std;
#include "string.h"

String::String() : Instrument(){
    cout<< "String: " <<endl;
    this-> lowHz = 80;
    this-> highHz = 3500;
}

String::~String(){

}

void String::pitchRangeCheck(){
    if(note >= lowHz && note <= highHz){
        Instrument::play(" is playing", soundDes);
    }else{
        Instrument::play(" pitch is out of range", "*insert crickets");
    }
}