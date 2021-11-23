#include "speaker.h"
#include <iostream>

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
