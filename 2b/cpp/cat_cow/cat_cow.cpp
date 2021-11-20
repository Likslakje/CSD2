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
        void wholeAnimal();
        void eyes(int numberEyes, string typeEyes); // lefttype and righttype (numbereyes)
        void ears(int numberEars, string typeEars); // lefttype and righttype (numberears)
        void nose(string typeNose);
        void tail(string typeTail);
        void teeth(string typeTeeth);
        void feet(string typeFeet);
        void furColor();
        void legs(int numberLegs);
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
        cout<< "Do you want to make a monster?" <<endl;
    }
}

void Animal::ears(int numberEars, string typeEars){
      if (numberEars <= 2){
        cout<< typeEars <<endl;
    }else{
        cout<< "Do you want to make a monster?" <<endl;
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

int main(){
    // string typeEyes, string typeEars, string typeNose, 
    // string typeTail, string typeTeeth, int numberPaws, 
    // int numberLegs, int numberEyes, int numberEars
    Animal cat("green", "pointy", "small", "fluffy", "sharp", "paws", 4, 2, 2); //default
    cat.wholeAnimal(); // print whole animal

    Animal cow("brown", "round", "big", "brush", "flat", "hooves", 4, 2, 2);
    cow.wholeAnimal();

    Animal catCow("none","none","none","none","none","none", 0, 0, 0);
    catCow.eyes(1, "red");
    catCow.ears(2, "round");
    catCow.nose("small");
    catCow.tail("fluffy");
    catCow.teeth("vampire");

}