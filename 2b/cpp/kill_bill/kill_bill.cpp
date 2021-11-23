#include <iostream>
using namespace std; 

string deadlyViperAssassinationSquad[6] = {"BlackMamba", "Cottonmouth", "Copperhead", "Sidewinder", "CalaforniaMountainSnake", "Bill"};
string characters[4] = {"Buck", "SophieFatale", "Crazy88", "GogoYubari"};
string weapons[5] = {"gun", "knife", "door", "katana", "flail"};
string outfits[6] = {"hospitalGown", "weddingDress", "jeans", "motorcycleSuit", "suit", "kimono"};

class Person{
    public:
        Person(string name, string weapon, string outfit);
        ~Person();
        string name;
        string weapon;
        string outfit;
        void print();
};

Person::Person(string name, string weapon, string outfit){
    this-> name = name;
    this-> weapon = weapon;
    this-> outfit = outfit;
}

Person::~Person(){}

class Vol1{
    //do the things in Vol.1
    public:
        Vol1();
        ~Vol1();
};

Vol1::Vol1(){

}

Vol1::~Vol1(){}

class Vol2{
    //do the tings in Vol.2
    public:
        Vol2();
        ~Vol2();
        void print();
};

Vol2::Vol2(){

}

Vol2::~Vol2(){}

void Person::print(){
    cout<< name << weapon << outfit <<endl;
}

int main(){
    /*
    Bride gets shot by Bill weddingdress/jeans
    Bride kills Copperhead with knife jeans/jeans
    Bride kills Buck with door HospitalGown/jeans
    Bride amputates Sophie Fatale with katana motorcyclesuit/kimono
    Bride kills the whole Crazy 88 with katana/katana motorcyclesuit/suit
    Bride kills Gogo katana/flail
    Bride kills Cottonmouth Katana/katana motorcyclesuit/kimono
    */

    Person Bride(deadlyViperAssassinationSquad[0], weapons[3], outfits[3]);
    Bride.print();

    Person VernitaGreen(deadlyViperAssassinationSquad[2], weapons[1], outfits[2]);
    VernitaGreen.print();
}