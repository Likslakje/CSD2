#include <iostream>

class Speaker
{
public:
    Speaker();
    ~Speaker();
    void make_sound();
    float filter_freq;
    /*
    woofer
    tweeter
    amp
    filter
    */
};

Speaker::Speaker()
{
    filter_freq = 307.2;
}

Speaker::~Speaker()
{
}

void Speaker::make_sound()
{
    std::cout <<"krggg"<< std::endl;
    std::cout <<"filter_freq "<< filter_freq << std::endl;
}

int main()
{
    Speaker speaker_left;
    Speaker speaker_right;
    speaker_left.make_sound();
}