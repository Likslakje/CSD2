#include <iostream>
using namespace std;
#include "string.h"

String::String(string name, string soundDes) : Instrument(name, soundDes){
    cout<< "String" <<endl;
}

String::~String(){
    
}