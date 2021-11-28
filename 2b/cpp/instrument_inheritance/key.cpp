#include <iostream>
using namespace std;
#include "key.h"

Key::Key(string name, string soundDes) : Instrument(name, soundDes){
    cout<< "Key" <<endl;
}

Key::~Key(){

}