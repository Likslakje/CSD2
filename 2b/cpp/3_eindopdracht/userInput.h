#pragma once

#include <iostream>

class UserInput
{
public:
  // static cus no UserInput object is created
  // returns the users choice, which depends on the passed selectionOptions
  static std::string retrieveSelection(std::string selectionOptions[],
    int numOptions);

  // returns the index of the users choice in the passed selectionOptions array
  static int retrieveSelectionIndex(std::string selectionOptions[],
    int numOptions);

  // returns the users input value, which has to be in the range of [min, max]
  static float retrieveValueInRange(float min, float max);
  //gets user input and returns input length
  static int retrieveMelodyInput();

protected:
  // hide default constructor and destructor
  UserInput() {};
  ~UserInput() {};

  // retruns false if userInput doesn't occur in passed options array
  static bool validateSelection(std::string selection, std::string selectionOptions[],
      int numOptions);

  // get input from user to use as rhythm and note "algorithm"
  static std::string retrieveInput(std::string selectionOptions[], int numOptions);
};
