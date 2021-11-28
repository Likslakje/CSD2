#include <iostream>
using namespace std;
#include "key.h"

Key::Key(string name) : Instrument(name){
    cout<< "Key" <<endl;
}

Key::~Key(){

}