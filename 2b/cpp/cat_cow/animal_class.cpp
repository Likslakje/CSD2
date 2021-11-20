#include <iostream>
#include "animal_class.h"
using namespace std;

Animal::Animal(string typeEyes, string typeEars, string typeNose, string typeTail, string typeTeeth, string typeFeet, int numberLegs, int numberEyes, int numberEars){
    this-> typeEyes = typeEyes;
    this-> typeEars = typeEars;
    this-> typeNose = typeNose;
    this-> typeTail = typeTail;
    this-> typeTeeth = typeTeeth;
    this-> typeFeet = typeFeet;
    // furColor = {"blackWhite", "black", "white", "orange"};
    this-> numberLegs = numberLegs;
    this-> numberEyes = numberEyes;
    this-> numberEars = numberEars;
}

Animal::~Animal(){

}

void Animal::wholeAnimal(){
    cout<< typeEyes + " "
        << typeEars + " "
        << typeNose + " "
        << typeTail + " "
        << typeTeeth + " "
        << typeFeet + " "
        << numberLegs
        << " "
        << numberEyes
        << " "
        << numberEars <<endl;
}

void Animal::eyes(int numberEyes, string typeEyes){
    if (numberEyes <= 2){
        cout<< typeEyes <<endl;
    }else{
        cout<< "Do you want to make a scary monster?" <<endl;
    }
}

void Animal::ears(int numberEars, string typeEars){
      if (numberEars <= 2){
        cout<< typeEars <<endl;
    }else{
        cout<< "Do you want to make a scary monster?" <<endl;
    }
}

void Animal::nose(string typeNose){
    cout<< typeNose <<endl;
}

void Animal::tail(string typeTail){
    cout<< typeTail <<endl;
}

void Animal::teeth(string typeTeeth){
    cout<< typeTeeth <<endl;
}
