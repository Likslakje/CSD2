#include <iostream>
using namespace std;
#include "string.h"

String::String(string name, string soundDes, float note) : Instrument(name, soundDes, note){
    cout<< "String" <<endl;
    this-> lowHz = 80;
    this-> highHz = 3500;
}

String::~String(){
    // cout<< lowHz <<endl;
}

bool String::pitchRangeCheck(){
    if(note >= lowHz && note <= highHz){
        return true;
    }else{
        return false;
    }
}