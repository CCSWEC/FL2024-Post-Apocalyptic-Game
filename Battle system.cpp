#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
int main()
{
    srand(time(0));
    char anyKey; //for the user to know that they have been defeated before ending the code
    int timeDelay = 2000; //used for the Sleep() function
    int hitChance; //the chance of the player hitting the boss
    int damageChance; //the chance of the player taking damage
    int distance = 3; //the distance between the player and the boss (Affect hit chance)
    int playerHealth = 20; //the player's health
    int bossHealth = 50; //the boss's health 
    int choice; //player's option
    int bossChoice; //boss's auto generated melee moves
    int bossMissedChance = 0; //This is a factor if a boss can hit his target or not during melee combat
    int bossDamageChance = 0; //this is a factor if a boss can dodge the player's hit or not during melee combat

    cout << "The raid boss who is wielding a minigun is standing before you and is taunting you" << endl;
    Sleep(timeDelay);
    cout << "Without saying a word, you know a battle is inevitable." << endl;
    Sleep(timeDelay);
    while (true) //run indefinitely until either the boss or the player is defeated.
    {
        cout << "Status: " << endl;
        cout << "Distance: " << distance << setw(30) << "Player's healh: " << playerHealth << setw(30) << "Boss's health: " << bossHealth << endl;
        Sleep(timeDelay);
        if (playerHealth <= 0) //player's defeated
        {
            cout << "You have been defeated.";
            cin >> anyKey;
            return 0;
        }
        else if (bossHealth <= 0) //boss's defeated
        {
            cout << "the raid boss have been defeated.";
            cin >> anyKey;
            return 0;
        }
        if (distance > 0) //this will run if the distance between the boss and the player is more than 0 (range battle)
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
                    damageChance = rand() % 100; //this will return a number between 0 and 100
                    if (damageChance >= 15) //player will be safe is damageChance is more or equal to 15
                    {
                        cout << "You succesfully take cover as the enemy's bullet fly pass your head" << endl;
                        Sleep(timeDelay);
                    }
                    else //if damageChance is less than 15, player will take damage.
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
                                if (distance <= 0)
                                {
                                    cout << "The raid boss throw away the minigun and wield an makeshift battle axe." << endl;
                                    Sleep(timeDelay);
                                    cout << "You also take out a knife and assume your combat stance." << endl;
                                }
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
                        if (distance <= 0)
                        {
                            cout << "The raid boss throw away the minigun and wield an makeshift battle axe." << endl;
                            Sleep(timeDelay);
                            cout << "You also take out a knife and assume your combat stance." << endl;
                        }
                    }
                    else
                    {
                        Sleep(timeDelay);
                        cout << "You have run closer to the raid boss." << endl;
                        distance -= 1;
                        Sleep(timeDelay);
                        cout << "Unfortunately, some of the raid boss's bullet have hit you." << endl;
                        playerHealth -= 6;
                        Sleep(timeDelay);
                        if (distance <= 0)
                        {
                            cout << "The raid boss throw away the minigun and wield an makeshift battle axe." << endl;
                            Sleep(timeDelay);
                            cout << "You also take out a knife and assume your combat stance." << endl;
                            Sleep(timeDelay);
                        }
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
        else //if distance is equal to zero, this mean you're entering melee combat.
        {   
            cout << "The boss is preparing to swing his battle axe" << endl;
            Sleep(timeDelay);
            cout << "1. Dodge the swinging axe " << "(" << 40 + (5*bossMissedChance) << "%)" << endl;
            cout << "2. Strike the raid boss " << "(" << 30 + (10*bossDamageChance) << "%)" << endl;
            cout << "3. Block the hit " << "(" << 60 + (5*bossMissedChance) << "%)" << endl;
            cin >> choice;
            switch (choice)
            {
                case 1:
                    choice = 0;
                    cout << "You decided to dodge the swinging axe" << endl;
                    Sleep(timeDelay);
                    damageChance = rand() % 100;
                    if (damageChance <= 40 + (5*bossMissedChance))
                    {
                        cout << "You managed to dodge the raid boss's axe." << endl;
                        Sleep(timeDelay);
                        cout << "Missing you make the raid boss lost balance, you decided to strike: " << endl;
                        cout << "1. The leg " << "(" << 50 + (10*bossDamageChance) << "%)" << endl;
                        cout << "2. The arm " << "(" << 50 + (10*bossDamageChance) << "%)" << endl;
                        cout << "3. The torso " << "(" << 70 + (10*bossDamageChance) << "%)" << endl;
                        cout << "4. The head " << "(" << 10 + (10*bossDamageChance) << "%)" << endl;
                        cin >> choice;
                        switch (choice)
                        {
                            case 1:
                                choice = 0;
                                cout << "You decided to stab the raid boss's leg." << endl;
                                Sleep(timeDelay);
                                hitChance = rand() % 100;
                                if (hitChance >= 100-(50 + (10*bossDamageChance)))
                                {
                                    cout << "You managed to hit the raid boss's legs." << endl;
                                    bossHealth -= 5;
                                    Sleep(timeDelay);
                                    cout << "The raid boss have lost some of his stability, making him stumble." << endl;
                                    bossDamageChance += 1;
                                    Sleep(timeDelay);
                                }
                                else
                                {
                                    cout << "You have missed the boss's legs." << endl;
                                    Sleep(timeDelay);
                                    cout << "The boss have regain his balance." << endl;
                                    Sleep(timeDelay);
                                }
                            break;
                            case 2:
                                choice = 0;
                                cout << "You decided to stab the raid boss's arms." << endl;
                                Sleep(timeDelay);
                                hitChance = rand() % 100;
                                if (hitChance >= 100-(50 + (10*bossDamageChance)))
                                {
                                    cout << "You managed to hit the raid boss's arms." << endl;
                                    bossHealth -= 5;
                                    Sleep(timeDelay);
                                    cout << "The raid boss have lost control of his arms, making him swing much slower." << endl;
                                    bossMissedChance += 1;
                                    Sleep(timeDelay);
                                }
                                else
                                {
                                    cout << "You have missed the boss's arms." << endl;
                                    Sleep(timeDelay);
                                    cout << "The boss have regain his balance." << endl;
                                    Sleep(timeDelay);
                                }
                            break;
                            case 3:
                                choice = 0;
                                cout << "You decided to stab the raid boss's torso." << endl;
                                Sleep(timeDelay);
                                hitChance = rand() % 100;
                                if (hitChance >= 100-(70 + (10*bossDamageChance)))
                                {
                                    cout << "You managed to hit the raid boss's torso." << endl;
                                    Sleep(timeDelay);
                                    bossHealth -= 10;
                                    cout << "The raid boss yell in pain, and starting to regain his balance again." << endl;
                                    Sleep(timeDelay);
                                }
                                else
                                {
                                    cout << "You have missed the boss's torso." << endl;
                                    Sleep(timeDelay);
                                    cout << "The boss have regain his balance." << endl;
                                    Sleep(timeDelay);
                                }
                            break;
                            case 4:
                                choice = 0;
                                cout << "You decided to stab the raid boss's head." << endl;
                                Sleep(timeDelay);
                                hitChance = rand() % 100;
                                if (hitChance >= 100-(10 + (10*bossDamageChance)))
                                {
                                    cout << "You managed to hit the raid boss's head." << endl;
                                    Sleep(timeDelay);
                                    bossHealth -= 50;
                                    cout << "The raid boss immediatelly fall onto the ground, bloods spurting from his head." << endl;
                                    Sleep(timeDelay);
                                }
                                else
                                {
                                    cout << "You have missed the boss's head." << endl;
                                    Sleep(timeDelay);
                                    cout << "The boss have regain his balance." << endl;
                                    Sleep(timeDelay);
                                }
                            break;
                        }
                    }
                    else
                    {
                        cout << "You got hit by the full force of the battle axe" << endl;
                        Sleep(timeDelay);
                        playerHealth -= 5;
                    }
                break;
                case 2:
                    cout << "You decided to strike the boss while hes charging." << endl;
                    Sleep(timeDelay);
                    hitChance = rand() % 100;
                    if (hitChance = 100 - (30 + (10*bossDamageChance)))
                    {
                        cout << "You managed to blindly strike the raid boss." << endl;
                        Sleep(timeDelay);
                        bossHealth -= 7;
                        cout << "The raid boss got interrupt due to the strike and push you aside." << endl;
                    }
                    else
                    {
                        cout << "The raid boss's hit overcome your strike." << endl;
                        Sleep(timeDelay);
                        playerHealth -= 5;
                        cout << "The raid boss is taunting you as you got injured." << endl;
                        Sleep(timeDelay);
                    }
                break;
                case 3:
                    cout << "You decided to bloc the boss's axe." << endl;
                    Sleep(timeDelay);
                    damageChance = rand() % 100;
                    if (damageChance <= 60 + (5*bossMissedChance))
                    {
                        cout << "You managed to parried and block some of the axe's damage." << endl;
                        playerHealth -= 2;
                        Sleep(timeDelay);
                        cout << "The raid boss's axe have been deflected and is now trying to wield it up again" << endl;
                        Sleep(timeDelay);
                        cout << "You decided to strike the boss while he is exposed:" << endl;
                        cout << "1. The leg " << "(" << 50 + (10*bossDamageChance) << "%)" << endl;
                        cout << "2. The arm " << "(" << 50 + (10*bossDamageChance) << "%)" << endl;
                        cout << "3. The torso " << "(" << 70 + (10*bossDamageChance) << "%)" << endl;
                        cout << "4. The head " << "(" << 10 + (10*bossDamageChance) << "%)" << endl;
                        cin >> choice;
                        switch (choice)
                        {
                            case 1:
                            choice = 0;
                            cout << "You decided to stab the raid boss's leg." << endl;
                            Sleep(timeDelay);
                            hitChance = rand() % 100;
                            if (hitChance >= 100-(50 + (10*bossDamageChance)))
                            {
                                cout << "You managed to hit the raid boss's legs." << endl;
                                bossHealth -= 5;
                                Sleep(timeDelay);
                                cout << "The raid boss have lost some of his stability, making him stumble." << endl;
                                bossDamageChance += 1;
                                Sleep(timeDelay);
                            }
                            else
                            {
                                cout << "You have missed the boss's legs." << endl;
                                Sleep(timeDelay);
                                cout << "The boss have regain his balance." << endl;
                                Sleep(timeDelay);
                            }
                        break;
                        case 2:
                            choice = 0;
                            cout << "You decided to stab the raid boss's arms." << endl;
                            Sleep(timeDelay);
                            hitChance = rand() % 100;
                            if (hitChance >= 100-(50 + (10*bossDamageChance)))
                            {
                                cout << "You managed to hit the raid boss's arms." << endl;
                                bossHealth -= 5;
                                Sleep(timeDelay);
                                cout << "The raid boss have lost control of his arms, making him swing much slower." << endl;
                                bossMissedChance += 1;
                                Sleep(timeDelay);
                            }
                            else
                            {
                                cout << "You have missed the boss's arms." << endl;
                                Sleep(timeDelay);
                                cout << "The boss have regain his balance." << endl;
                                Sleep(timeDelay);
                            }
                        break;
                        case 3:
                            choice = 0;
                            cout << "You decided to stab the raid boss's torso." << endl;
                            Sleep(timeDelay);
                            hitChance = rand() % 100;
                            if (hitChance >= 100-(70 + (10*bossDamageChance)))
                            {
                                cout << "You managed to hit the raid boss's torso." << endl;
                                Sleep(timeDelay);
                                bossHealth -= 10;
                                cout << "The raid boss yell in pain, and starting to regain his balance again." << endl;
                                Sleep(timeDelay);
                            }
                            else
                            {
                                cout << "You have missed the boss's torso." << endl;
                                Sleep(timeDelay);
                                cout << "The boss have regain his balance." << endl;
                                Sleep(timeDelay);
                            }
                        break;
                        case 4:
                            choice = 0;
                            cout << "You decided to stab the raid boss's head." << endl;
                            Sleep(timeDelay);
                            hitChance = rand() % 100;
                            if (hitChance >= 100-(10 + (10*bossDamageChance)))
                            {
                                cout << "You managed to hit the raid boss's head." << endl;
                                Sleep(timeDelay);
                                bossHealth -= 50;
                                cout << "The raid boss immediatelly fall onto the ground, bloods spurting from his head." << endl;
                                Sleep(timeDelay);
                            }
                            else
                            {
                                cout << "You have missed the boss's head." << endl;
                                Sleep(timeDelay);
                                cout << "The boss have regain his balance." << endl;
                                Sleep(timeDelay);
                            }
                        break;
                        }
                    }
                    else
                    {
                        cout << "Unable to parry the boss's strike, you have taken the full force" << endl;
                        Sleep(timeDelay);
                        playerHealth -= 5;
                        cout << "The boss is swinging his axe around, waiting for you to get up." << endl;
                        Sleep(timeDelay);
                    }
                break;
                default:
                    cout << "You decided to stand infront of the boss and do nothing" << endl;
                    Sleep(timeDelay);
                    cout << "The axe's full weight come crashing down on your head" << endl;
                    playerHealth -= 10;
                    Sleep(timeDelay);
                break;
            }
        }
    }
}