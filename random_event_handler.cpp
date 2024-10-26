/*
File for adding new functions to the random event feature when traveling, make sure to add the function in random_event_handler.hpp as well
*/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "random_event_handler.hpp" // needs this preprocessor to use the functions

using namespace std;

void medicalSupplyEvent(string location) { // very simple example of how this could be used
    cout << "While traveling to " << location << " you find a hidden stash with medical supplies.\n"
    << "This could be useful for later...\n";

    // this is where you would call a function for adding something to the inventory e.g.
    // addInventory("Medical Supplies", 3) or medical supplies could even be an object which the add inventory function would handle by itself
}

void randomEvent(string location) {
    srand(time(0)); // generates a random seed to ensure true randomization each time to program is run
    int eventChance = rand() % 100; // random number between 0 and 99

    if(eventChance < 80) { // 80% chance
        medicalSupplyEvent(location);
    } else { // 20% chance no event occurs
        cout << "You travel to the " << location << " without incident.\n";
    }
}