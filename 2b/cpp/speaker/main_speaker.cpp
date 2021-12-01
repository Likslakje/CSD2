#include "speaker.h"
#include <iostream>

int main()
{
    Speaker speaker_left;
    Speaker speaker_right;

    speaker_left.make_sound(400);
    speaker_left.filter_freq = 736.8;
    speaker_left.make_sound(400);
}