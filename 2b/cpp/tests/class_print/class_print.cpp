#include <iostream>
using namespace std;

// class Word{
//     public:
//         Word(string name);
//         ~Word();
//         void print();
//     protected:
//         string name;
// };

// Word::Word(string name){
//     this-> name = name;
// }
// Word::~Word(){
    
// }
// void Word::print(){
//     cout<< "hoi " << name <<endl;
// }
class A {
    public:
        A();
        ~A();
        float note;
};

A::A(){
    this-> note = 305;
}

A::~A(){}

class B{
    public:
        B();
        ~B();
};

B::B(){
    cout<< A::note <<endl;
}

B::~B(){}

int main(){
    A a;
    B b;
    // cout<< one.note << endl;

    return 0;
}