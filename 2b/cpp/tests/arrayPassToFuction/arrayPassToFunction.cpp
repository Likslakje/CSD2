#include <iostream>
#include <array>
using namespace std;

  array<string, 4> animals = {"cat", "cow", "frog", "bug"};
  const int animalsLength = animals.size();

void print(array<string, animalsLength> getAnimals, int length){
    cout<< "Animals: ";
    for(int i = 0; i < length; i++){
        cout<< getAnimals[i] << " ";
    }
    cout<<endl;
}

int main(){
    print(animals, animalsLength);
}