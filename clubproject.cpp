#include <iostream>
using namespace std;

void restArea();
void shop();


int main() 
{
    restArea();
    return 0;
}

// Rest Area Function
void restArea() 
{
    int choice;

    cout << "You have entered the rest area. What would you like to do?" << endl;
    cout << "1. Heal" << endl;
    cout << "2. Visit shop" << endl;
    cout << "3. Exit rest area" << endl;
    cin >> choice;
    
    switch(choice) 
    {
        case 1:
            cout << "You are now healed!" << endl;
            // Add healing logic here
            break;
        case 2:
            //calling shop function within restArea function
            shop(); 
            break;
        case 3:
            cout << "Exiting rest area..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
            restArea(); // Recalling restArea() in case of invalid input
    }
}

// Shop Function
void shop() 
{
    cout << "Welcome to the shop! What would you like to do?" << endl;
    cout << "1. Buy item" << endl;
    cout << "2. Sell item" << endl;
    cout << "3. Exit shop" << endl;
    
    int choice;
    cin >> choice;
    
    switch(choice) 
    {
        case 1:
            cout << "You bought an item!" << endl;
            // Add buying logic here
            break;
        case 2:
            cout << "You sold an item!" << endl;
            // Add selling logic here
            break;
        case 3:
            cout << "Exiting shop..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
            shop(); // Recalling shop() in case of invalid input
    }
}