#! /bin/bash

g++ -c speaker.cpp
g++ -c woofer.cpp
g++ -c tweeter.cpp
g++ -c main_speaker.cpp
g++ -o speaker_program speaker.cpp main_speaker.cpp
