#include <iostream>
using namespace std;
#include "perc.h"

Percussion::Percussion(string name, string soundDes) : Instrument(name, soundDes){
    cout<< "Percussion" <<endl;
}

Percussion::~Percussion(){
    
}