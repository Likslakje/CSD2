#include <iostream>
using namespace std;
#include "wind.h"

Wind::Wind(string name) : Instrument(name, soundDes){
    cout<< "Wind" <<endl;
}

Wind::~Wind(){

}