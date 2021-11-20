// Class programming excercise about my favorite animals
#include <iostream>
#include <string>
using namespace std;

class Animal{
    public:
        Animal(string typeEyes, string typeEars, string typeNose, string typeTail, string typeTeeth, string typeFeet, int numberLegs, int numberEyes, int numberEars);
        ~Animal();
        string typeEyes;
        string typeEars;
        string typeNose;
        string typeTail;
        string typeTeeth;
        string typeFeet;
        // string furColor[4];
        int numberLegs;
        int numberEyes;
        int numberEars;
        void print();
        void typeEyes(); // lefttype and righttype (numbereyes)
        void typeEars(); // lefttype and righttype (numberears)
        void typeNose();
        void typeTail();
        void typeTeeth();
        void typeFeet();
        void furColor();
        void numberLegs();
};

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

void Animal::print(){
    cout<< typeFeet <<endl;
    cout<< typeEars <<endl;
}

void typeEyes(){
    // if (numberEyes =< 2){
    //     cout<< ty
    // }
}

void typeEars(){

}

void typeNose(){

}

void typeTail(){

}

void typeTeeth(){

}

int main(){
    // string typeEyes, string typeEars, string typeNose, 
    // string typeTail, string typeTeeth, int numberPaws, 
    // int numberLegs, int numberEyes, int numberEars
    Animal cat("green", "pointy", "small", "fluffy", "sharp", "paws", 4, 2, 2);
    Animal cow("brown", "round", "big", "brush", "flat", "hooves", 4, 2, 2);
    cat.print();
    cow.print();

}