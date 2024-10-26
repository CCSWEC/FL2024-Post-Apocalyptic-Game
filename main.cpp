/*
Example use case of the random event feature, this would likely be removed for a more organized modular system along with the other features
*/

#include <iostream>
#include <string>
#include "random_event_handler.hpp" // allows use of functions defined in the header file

using namespace std;

int main() {
    /* simple example of a prompt to travel along with getting the user input for the traveling 
    This can be modular like the random events if needed */
    cout << "As you approach a roadsign you see it splits into two paths just shown as \"City\" or \"Farm\"\n";
    cout << "Choose an action.\n"
    << "1. Rest \n"
    << "2. City \n"
    << "3. Farm \n";

    switch(cin.get()) { // cin.get() gets the users input without needing to create a variable
        case '1':
            cout << "You chose to rest.\n";
            break;
        case '2':
            cout << "You chose to travel to the city.\n";
            randomEvent("city");
            break;
        case '3':
            cout << "You chose to travel to the farm.\n";
            randomEvent("farm");
            break;
        default:
            cout << "Invalid Option!\n";
    }

    return 0;
}