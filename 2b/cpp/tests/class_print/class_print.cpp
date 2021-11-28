#include <iostream>
using namespace std;

class Word{
    public:
        Word(string name);
        ~Word();
        void print();
    protected:
        string name;
};

Word::Word(string name){
    this-> name = name;
}
Word::~Word(){
    
}
void Word::print(){
    cout<< "hoi " << name <<endl;
}

int main(){
    Word word("your mom");
    word.print();

    return 0;
}