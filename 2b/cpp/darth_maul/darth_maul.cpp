#include <iostream>

class Darth_maul_legs{
public:
    int horn;
    int tattoo;
    double lightsaber; // ;)
    Darth_maul_legs(std::string _quote); // legs
    ~Darth_maul_legs(); // no legs
    void duel_on_Naboo();
    std::string quote;
};

Darth_maul_legs::Darth_maul_legs(std::string _quote){
    quote = _quote;
}

Darth_maul_legs::~Darth_maul_legs(){

}

void Darth_maul_legs::duel_on_Naboo(){
    std::cout<< quote <<std::endl;
}

int main(){
    Darth_maul_legs before("Jedi! I have been waiting for you.");
    Darth_maul_legs after("Aaarrrggghh!");

    before.duel_on_Naboo();
    after.duel_on_Naboo();
}
