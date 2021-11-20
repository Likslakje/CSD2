// Class programming excercise about my favorite animals

#include <iostream>
#include "animal_class.h"
using namespace std;

int main(){
    /* 
    string typeEyes, string typeEars, string typeNose, 
    string typeTail, string typeTeeth, int numberPaws, 
    int numberLegs, int numberEyes, int numberEars
    */
    //cat
    Animal cat("green", "pointy", "small", "fluffy", "sharp", "paws", 4, 2, 2); //default
    cat.wholeAnimal(); // print whole animal

    //cow
    Animal cow("brown", "round", "big", "brush", "flat", "hooves", 4, 2, 2);
    cow.wholeAnimal();

    //monster
    Animal catCow("none","none","none","none","none","none", 0, 0, 0);
    // make your own
    catCow.eyes(1, "red"); //give it some eyes and an eye color
    catCow.ears(2, "round"); //give it some ears and an ear type
    catCow.nose("small"); //set the size of it's nose
    catCow.tail("fluffy"); //choose a tail
    catCow.teeth("vampire"); //Finally give it some teeth

}