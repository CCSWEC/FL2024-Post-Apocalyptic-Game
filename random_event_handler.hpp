/*
The use of a header file allows us to better organize different events that can happen when traveling, and makes it easier to add more if needed
all that's needed is creating a new function here and then adding the functionality of the function in the c++ file
*/

#ifndef RANDOM_EVENT_HANDLER_H // makes sure RANDOM_EVENT_HANDLER_H isnt defined anywhere else "ifndef" stands for if not defined
#define RANDOM_EVENT_HANDLER_H // if the handler isn't defined then define it here

#include <string> // allows use of std::string

void medicalSupplyEvent(std::string location); // needs to use std:: because we aren't using namespace std
void randomEvent(std::string location); // this will be used to randomize the events

#endif