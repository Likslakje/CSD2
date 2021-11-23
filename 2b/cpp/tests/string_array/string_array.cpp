#include <iostream>
#include <array>
using namespace std;

string typesMotorcycle[3] = {"ducati", "triumph", "honda"};

class Motorcycle{
public:
    Motorcycle(string typesMotorcycle[3]);
    ~Motorcycle();
    string typesMotorcycle[3];
    void print();
};

Motorcycle::Motorcycle(string typesMotorcycle[3]){
   for (int i = 0; i < 3; i++){
       this-> typesMotorcycle[i] = typesMotorcycle[i];
   }
}

Motorcycle::~Motorcycle(){
    
}

void Motorcycle::print(){
    for (int i = 0; i < 3; i++){
        cout<< typesMotorcycle[i] <<endl;
    };
}

int main(){
    Motorcycle motor(typesMotorcycle);
    motor.print();
}