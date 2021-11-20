#ifndef ANIMAL_CLASS_H
#define ANIMAL_CLASS_H
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

#endif