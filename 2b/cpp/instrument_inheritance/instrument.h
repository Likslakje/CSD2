# include <iostream>
using namespace std;

class Instrument{
    public:
        Instrument(string name);
        ~Instrument();
        void play();
    protected:
        string name;
};