#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
int main()
{
    srand(time(0));
    char anyKey;
    int timeDelay = 2000;
    int hitChance;
    int damageChance;
    int distance = 3;
    int playerHealth = 20;
    int bossHealth = 50;
    int choice;

    cout << "The raid boss who is wielding a minigun is standing before you and is taunting you" << endl;
    Sleep(timeDelay);
    cout << "Without saying a word, you know a battle is inevitable." << endl;
    Sleep(timeDelay);
    while (true)
    {
        cout << "Status: " << endl;
        cout << "Distance: " << distance << setw(30) << "Player's healh: " << playerHealth << setw(30) << "Boss's health: " << bossHealth << endl;
        Sleep(timeDelay);
        if (playerHealth <= 0)
        {
            cout << "You have been defeated.";
            cin >> anyKey;
            return 0;
        }
        if (bossHealth <= 0)
        {
            cout << "the raid boss have been defeated.";
            cin >> anyKey;
            return 0;
        }
        if (distance > 0)
        {
            cout << "The raid boss's minigun is spinning and is pointing at your direction" << endl;
            Sleep(timeDelay);
            cout << "1. Take cover at a nearby wall (85%)" << endl;
            cout << "2. take aim and shoot at the enemy (" << 35 + 10*(3-distance) << "%)" << endl;
            cout << "3. Run toward the enemy (30%)" << endl;
            cin >> choice;
            switch (choice)
            {
                case 1:
                    choice = 0;
                    cout << "You decided to take cover at a nearby wall as the raid boss's minigun start firing at your direction" << endl;
                    Sleep(timeDelay);
                    damageChance = rand() % 100;
                    if (damageChance >= 15)
                    {
                        cout << "You succesfully take cover as the enemy's bullet fly pass your head" << endl;
                        Sleep(timeDelay);
                    }
                    else
                    {
                        cout << "Despite taking cover, you have been hit by some the bullets" << endl;
                        playerHealth -= 2;
                        Sleep(timeDelay);
                    }
                    cout << "You look up and see the raid boss's minigun is being overheated" << endl;
                    cout << "1. Run toward to raid boss (100%)" << endl;
                    cout << "2. Aim and shoot at the raid boss (" << 45 + 10*(3-distance) << "%)" << endl;
                    cin >> choice;
                    switch (choice)
                        {
                            case 1:
                                choice = 0;
                                cout << "You decided to run toward the raid boss while his minigun is cooling down." << endl;
                                if (distance == 0)
                                {
                                    Sleep(timeDelay);
                                    cout << "However, you cant move foward because you are infront of the raid boss." << endl;
                                }
                                else
                                {
                                    distance -= 1;
                                    Sleep(timeDelay);
                                    cout << "You have gotten closer to the raid boss." << endl;
                                }
                
                                break;
                            case 2:
                                choice = 0;
                                cout << "You decided to take aim at the raid boss." << endl;;
                                hitChance = rand() % 100;
                                if (hitChance >= 100-(45 + 10*(3-distance)))
                                {
                                    Sleep(timeDelay);
                                    cout << "You managed to shot the raid boss." << endl;
                                    bossHealth -= 10;
                                }
                                else
                                {
                                    Sleep(timeDelay);
                                    cout << "You missed the raid boss." << endl;
                                }
                                break;
                            default:
                                Sleep(timeDelay);
                                cout << "You decided to stand around doing nothing" << endl;
                                Sleep(timeDelay);
                                cout << "The raid boss's minigun has finished cooling down" << endl;
                                break;
                        }
                    break;
                case 2:
                    choice = 0;
                    cout << "You decided to take aim at the raid boss." << endl;
                    hitChance = rand() % 100;
                    if (hitChance >= 100-(35 + 10*(3-distance)))
                    {
                        Sleep(timeDelay);
                        cout << "You managed to shot the raid boss and interrupt him." << endl;
                        bossHealth -= 10;
                    }
                    else
                    {
                        Sleep(timeDelay);
                        cout << "You missed the raid boss." << endl;
                        Sleep(timeDelay);
                        cout << "The raid boss is firing at your location, you have been hit because you have no cover." << endl;
                        playerHealth -= 6;
                        Sleep(timeDelay);
                    }
                    break;
                case 3:
                    choice = 0;
                    cout << "You decided to run toward the raid boss." << endl;
                    damageChance = rand() % 100;
                    if (damageChance >= 70)
                    {
                        Sleep(timeDelay);
                        cout << "You have run closer to the raid boss." << endl;
                        distance -= 1;
                        Sleep(timeDelay);
                        cout << "None of the bullet that the raid boss fired have hit you." << endl;
                    }
                    else
                    {
                        Sleep(timeDelay);
                        cout << "You have run closer to the raid boss." << endl;
                        distance -= 1;
                        Sleep(timeDelay);
                        cout << "Unfortunately, some of the raid boss's bullet have hit you." << endl;
                        playerHealth -= 6;
                    }
                    break;
                default:
                    choice = 0;
                    cout << "You decided to stand there and do nothing" << endl;
                    Sleep(timeDelay);
                    cout << "This lead you open as you got hit by multiple rounds of bullets." << endl;
                    playerHealth -= 10;
                    Sleep(timeDelay);
                    break;
            }
        }
        else
        {
            cout << "The raid boss throw away the minigun and wield an battle axe.";
            
        }


                        


                        


                         

                    

                    

                

                
    

    }
    Sleep(timeDelay);

}