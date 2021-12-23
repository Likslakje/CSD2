#include "userInput.h"


bool UserInput::validateSelection(std::string selection,
  std::string selectionOptions[], int numOptions)
{
  // check if the selection occurs inside the options, if so, return true
  for (int i = 0; i < numOptions; ++i) {
    if(selection == selectionOptions[i]) {
      return true;
    }
  }
  // selection does not occur in options --> return false
  return false;
}

std::string UserInput::retrieveMelodyInput()
{
  // get a string from user
  // retrun its length to set the melody charHop size
  std::cout<< "Enter something..." <<std::endl;
  std::string melodyInput;
  // get line allows for spaces to get through
  std::getline(std::cin, melodyInput);
  removeSpaces(melodyInput);
  return melodyInput;
}

void UserInput::removeSpaces(std::string &str)
{
  // Credits for removeSpaces go to 
  // https://www.geeksforgeeks.org/remove-extra-spaces-string/
	// n is length of the original string
	int n = str.length();

	// i points to next position to be filled in
	// output string/ j points to next character
	// in the original string
	int i = 0, j = -1;

	// flag that sets to true is space is found
	bool spaceFound = false;

	// Handles leading spaces
	while (++j < n && str[j] == ' ');

	// read all characters of original string
	while (j < n)
	{
		// if current characters is non-space
		if (str[j] != ' ')
		{
			// remove preceding spaces before dot,
			// comma & question mark
			if ((str[j] == '.' || str[j] == ',' ||
				str[j] == '?') && i - 1 >= 0 &&
				str[i - 1] == ' ')
				str[i - 1] = str[j++];

			else
				// copy current character at index i
				// and increment both i and j
				str[i++] = str[j++];

			// set space flag to false when any
			// non-space character is found
			spaceFound = false;
		}
		// if current character is a space
		else if (str[j++] == ' ')
		{
			// If space is encountered for the first
			// time after a word, put one space in the
			// output and set space flag to true
			if (!spaceFound)
			{
				str[i++] = str[j++];
				spaceFound = true;
			}
		}
	}

	// Remove trailing spaces
	if (i <= 1)
		str.erase(str.begin() + i, str.end());
	else
		str.erase(str.begin() + i - 1, str.end());
}

std::string UserInput::retrieveInput(std::string selectionOptions[],
  int numOptions)
{
  // show user the allowed options
  std::cout << "Please enter your selection. You can choose between: ";
  for(int i = 0; i < numOptions - 1; i++) {
    std::cout<< selectionOptions[i] << ", ";
  }
  // print last option outside forloop
  std::cout<< selectionOptions[numOptions - 1] <<std::endl;

  // retrieve and return choice
  std::string selection = "";
  std::cin>> selection;
  return selection;
}

std::string UserInput::retrieveSelection(std::string selectionOptions[], int numOptions)
{
  bool noCorrectSelection = true;
  std::string userSelection = "";

  while(noCorrectSelection) {
    // let user choice between the allowed options
    userSelection = retrieveInput(selectionOptions, numOptions);
    // check if the selection is correct
    noCorrectSelection = !validateSelection(userSelection, selectionOptions,
      numOptions);
    // if selection is not correct, log message to user to try again
    if(noCorrectSelection) {
      std::cout<< "Incorrect selection, please try again" <<std::endl;
    }
  }
  return userSelection;
}


int UserInput::retrieveSelectionIndex(std::string selectionOptions[], int numOptions)
{
  std::string userSelection = retrieveSelection(selectionOptions, numOptions);
  // find and return the index of userSelection;
  for(int i = 0; i < numOptions; i++) {
    if(userSelection == selectionOptions[i]) return i;
  }
  // NOTE: this code should never be reached --> throw error
  std::cout << "ERROR • UserInput::retrieveUserSelection - "
    << "THIS SHOULD NEVER HAPPEN" << std::endl;
  throw "ERROR • UserInput::retrieveUserSelection";
  return -1;
}


float UserInput::retrieveValueInRange(float min, float max) {
  std::string input;
  float value = 0;
  bool notInRange = true;

  while(notInRange) {
    std::cout << "Please enter a value between " << min << " and " << max
      << std::endl;
    // first capture input in input string
    std::cin >> input;
    // validate if input string can be transformed into a float
    try {
      value = std::stof(input);
      // validate range
      if(value >= min && value <= max) {
        notInRange = false;
      } else {
        // value not in range
        std::cout << "Incorrect range, please try again." << std::endl;
      }
    } catch (const std::exception& e) {
      // no float as input
      std::cout << "Invalid input, this was not a number, please try again"
        << std::endl;
    }
  }

  return value;
}
