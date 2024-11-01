/*
Example use case of the random event feature
*/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <functional>

using namespace std;

/*
Functions for the random events
*/

void medicalSupplyEvent(string location);
void safeTravelEvent(string location);
void findFoodEvent(string location);

struct Event { // creates a new type like int or bool for example
    function<void(string)> eventFunction; // this allows us to store a function connected to a weight to calculate the chances of the function being called
    int weight;
};

void weightedRandomEvent(string location, vector<Event> events) { // functions which takes in a string, and vector of events (basically just multiple events)
    int totalWeight = 0;
    for(Event event : events) { // loops through all "event" inside of "events" const auto& just means it auto detects the type
        totalWeight += event.weight; // adds up the total weight of all events
    }

    int randomValue = rand() % totalWeight; // gets a random value based on weight of all events
    int cumulativeWeight = 0;

    for(Event event : events) {
        cumulativeWeight += event.weight;
        if(randomValue < cumulativeWeight) { // adds up the weight until it finds which function the randomValue is inside.
            event.eventFunction(location); // calls whichever event it was currently on
            return;
        }
    }
}

void safeTravelEvent(string location) { // safe travel event
    cout << "You traveled to the " << location << " without incident.";
}

void findFoodEvent(string location) {
    cout << "While traveling to " << location << ", you come across a hidden stash of food supplies.\n";

    // could call an addInventory function here possibly.
}

void medicalSupplyEvent(string location) { // simple function for getting medical supplies
    cout << "While traveling to " << location << " you find a hidden stash with medical supplies.\n"
    << "This could be useful for later...\n";

    // this is where you would call a function for adding something to the inventory e.g.
    // addInventory("Medical Supplies", 3) or medical supplies could even be an object which the add inventory function would handle by itself
}

int main() {
    srand(time(0)); // Seed for randomization


    // define all the functions with the weight when traveling to a city
    vector<Event> cityEvents = {
        {medicalSupplyEvent, 60},
        {findFoodEvent, 30},
        {safeTravelEvent, 10}
    };

    vector<Event> farmEvents = {
        {medicalSupplyEvent, 15},
        {findFoodEvent, 35},
        {safeTravelEvent, 30}
    };

    /* simple example of a prompt to travel along with getting the user input for the traveling 
    This can be modular like the random events if needed */
    cout << "As you approach a roadsign you see it splits into two paths shown as \"City\" or \"Farm\"\n";
    cout << "Choose an action.\n"
    << "1. Rest \n"
    << "2. City \n"
    << "3. Farm \n";

    switch(cin.get()) { // cin.get() gets the users input without needing to create a variable
        case '1':
            cout << "You chose to rest.\n"; 
            // Rest function
            break;
        case '2':
            cout << "You chose to travel to the city.\n";
            weightedRandomEvent("city", cityEvents);
            break;
        case '3':
            cout << "You chose to travel to the farm.\n";
            weightedRandomEvent("farm", farmEvents);
            break;
        default:
            cout << "Invalid Option!\n";
    }

    cout << "Press enter to exit...";
    cin.get();
    cin.get();

    return 0;
}
