# include <iostream>
using namespace std;
#include "string.h"

String::String(string name) : Instrument(name){
    cout<< "string constructor \n" << name <<endl;
}

String::~String(){
    
}