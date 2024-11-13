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
    int bossHealth = 100; //the boss's health 
    int choice; //player's option
    int bossChoice; //boss's auto generated melee moves
    int bossMissedChance = 0; //This is a factor if a boss can hit his target or not during melee combat
    int bossDamageChance = 0; //this is a factor if a boss can dodge the player's hit or not during melee combat

    cout << "Over the toxic fog, you can see a silhouette of a big creature." << endl;
    Sleep(timeDelay);
    cout << "The creature have noticed you and is marching toward your location. There is no escape." << endl;
    Sleep(timeDelay);
    while (true)
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
        if (distance > 0)
        {
            cout << "The creature is slowly walking toward you while roaring."
            Sleep(timeDelay);
            cout << "1. take aim and shoot at the enemy (" << 35 + 10*(3-distance) << "%)" << endl;
            cout << "2. Prepare your knife and walk toward the enemy (30%)" << endl;
            cin >> choice;
            switch (choice)
            {
                case 1:
                    choice = 0;
                    cout << "You decided to take aim at the mutant beast." << endl;
                    hitChance = rand() % 100;
                    if (hitChance >= 100-(35 + 10*(3-distance)))
                    {
                        Sleep(timeDelay);
                        cout << "You managed to shot the mutant beast and damage it." << endl;
                        Sleep(timeDelay);
                        cout << "The beast let out a loud roar as it continue to walk more aggresively toward you." << endl;
                        Sleep(timeDelay);
                        bossHealth -= 10;
                        distance -= 1;
                        if (distance <= 0)
                        {
                            cout << "The beast is standing right in front of you" << endl;
                            Sleep(timeDelay);
                            cout << "You can feel your spine crawling behind your back" << endl;
                            Sleep(timeDelay);
                        }
                    }
                    else
                    {
                        Sleep(timeDelay);
                        cout << "You missed the mutant beast." << endl;
                        Sleep(timeDelay);
                        cout << "The mutant beast walk closer to you, as you can hear the ground shaking from the footsteps" << endl;
                        Sleep(timeDelay);
                        distance -= 1;
                        if (distance <= 0)
                        {
                            cout << "The beast is standing right in front of you" << endl;
                            Sleep(timeDelay);
                            cout << "You can feel your spine crawling behind your back" << endl;
                            Sleep(timeDelay);
                        }
                    }
                    break;
                case 2:
                    choice = 0;
                    cout << "You decided to draw the knife out and walk toward the raid boss." << endl;
                    distance = 0;
                    cout << "The beast is standing right in front of you" << endl;
                    Sleep(timeDelay);
                    cout << "You can feel your spine crawling behind your back" << endl;
                    Sleep(timeDelay);
                    break;
            }       
        }
        else
        {   
            cout << "The Mutant lift its claws up is about to strike you" << endl;
            Sleep(timeDelay);
            cout << "1. Dodge the Mutant's claw " << "(" << 40 + (5*bossMissedChance) << "%)" << endl;
            cout << "2. Strike the Mutant " << "(" << 30 + (10*bossDamageChance) << "%)" << endl;
            cout << "3. Block the Mutant's claw " << "(" << 60 + (5*bossMissedChance) << "%)" << endl;
            cin >> choice;
            switch (choice)
            {
                case 1:
                    choice = 0;
                    cout << "You decided to dodge the Mutant's claw" << endl;
                    Sleep(timeDelay);
                    damageChance = rand() % 100;
                    if (damageChance <= 40 + (5*bossMissedChance))
                    {
                        cout << "You managed to dodge the Mutant's claw" << endl;
                        Sleep(timeDelay);
                        cout << "Missing you make the Mutant lost balance, you decided to strike: " << endl;
                        cout << "1. The leg " << "(" << 50 + (10*bossDamageChance) << "%)" << endl;
                        cout << "2. The arm " << "(" << 50 + (10*bossDamageChance) << "%)" << endl;
                        cout << "3. The torso " << "(" << 70 + (10*bossDamageChance) << "%)" << endl;
                        cout << "4. The head " << "(" << 10 + (10*bossDamageChance) << "%)" << endl;
                        cin >> choice;
                        switch (choice)
                        {
                            case 1:
                                choice = 0;
                                cout << "You decided to stab the Mutant's leg." << endl;
                                Sleep(timeDelay);
                                hitChance = rand() % 100;
                                if (hitChance >= 100-(50 + (10*bossDamageChance)))
                                {
                                    cout << "You managed to hit the Mutant's legs." << endl;
                                    bossHealth -= 5;
                                    Sleep(timeDelay);
                                    cout << "The Mutant have lost some of his stability, making him stumble." << endl;
                                    bossDamageChance += 1;
                                    Sleep(timeDelay);
                                }
                                else
                                {
                                    cout << "You have missed Mutant's legs." << endl;
                                    Sleep(timeDelay);
                                    cout << "The Mutant have regain his balance." << endl;
                                    Sleep(timeDelay);
                                }
                            break;
                            case 2:
                                choice = 0;
                                cout << "You decided to stab the Mutant's arms." << endl;
                                Sleep(timeDelay);
                                hitChance = rand() % 100;
                                if (hitChance >= 100-(50 + (10*bossDamageChance)))
                                {
                                    cout << "You managed to hit the Mutant's arms." << endl;
                                    bossHealth -= 5;
                                    Sleep(timeDelay);
                                    cout << "The Mutant have lost control of his arm, making it swing much slower." << endl;
                                    bossMissedChance += 1;
                                    Sleep(timeDelay);
                                }
                                else
                                {
                                    cout << "You have missed Mutant's arms." << endl;
                                    Sleep(timeDelay);
                                    cout << "The Mutant have regain his balance." << endl;
                                    Sleep(timeDelay);
                                }
                            break;
                            case 3:
                                choice = 0;
                                cout << "You decided to stab the raid Mutant's torso." << endl;
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
                                cout << "You decided to stab the Mutant's head." << endl;
                                Sleep(timeDelay);
                                hitChance = rand() % 100;
                                if (hitChance >= 100-(10 + (10*bossDamageChance)))
                                {
                                    cout << "You managed to hit the Mutant's head." << endl;
                                    Sleep(timeDelay);
                                    bossHealth -= 50;
                                    cout << "The raid boss immediatelly fall onto the ground, bloods spurting from his head." << endl;
                                    Sleep(timeDelay);
                                }
                                else
                                {
                                    cout << "You have missed Mutant's head." << endl;
                                    Sleep(timeDelay);
                                    cout << "The Mutant have regain his balance." << endl;
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
                    cout << "You decided to strike the Mutant while hes charging." << endl;
                    Sleep(timeDelay);
                    hitChance = rand() % 100;
                    if (hitChance = 100 - (30 + (10*bossDamageChance)))
                    {
                        cout << "You managed to blindly strike the Mutant." << endl;
                        Sleep(timeDelay);
                        bossHealth -= 7;
                        cout << "The Mutant got interrupt due to the strike and push you aside." << endl;
                    }
                    else
                    {
                        cout << "The Mutant's hit overcome your strike." << endl;
                        Sleep(timeDelay);
                        playerHealth -= 5;
                        cout << "The Mutant is taunting you as you got injured." << endl;
                        Sleep(timeDelay);
                    }
                break;
                case 3:
                    cout << "You decided to block the Mutant's claw." << endl;
                    Sleep(timeDelay);
                    damageChance = rand() % 100;
                    if (damageChance <= 60 + (5*bossMissedChance))
                    {
                        cout << "You managed to parried and block some of the claw's damage." << endl;
                        playerHealth -= 2;
                        Sleep(timeDelay);
                        cout << "The Mutant's claw have been deflected and its hand is being stunned" << endl;
                        Sleep(timeDelay);
                        cout << "You decided to strike the Mutant while he is exposed:" << endl;
                        cout << "1. The leg " << "(" << 50 + (10*bossDamageChance) << "%)" << endl;
                        cout << "2. The arm " << "(" << 50 + (10*bossDamageChance) << "%)" << endl;
                        cout << "3. The torso " << "(" << 70 + (10*bossDamageChance) << "%)" << endl;
                        cout << "4. The head " << "(" << 10 + (10*bossDamageChance) << "%)" << endl;
                        cin >> choice;
                        switch (choice)
                        {
                            case 1:
                            choice = 0;
                            cout << "You decided to stab the Mutant's leg." << endl;
                            Sleep(timeDelay);
                            hitChance = rand() % 100;
                            if (hitChance >= 100-(50 + (10*bossDamageChance)))
                            {
                                cout << "You managed to hit the Mutant's legs." << endl;
                                bossHealth -= 5;
                                Sleep(timeDelay);
                                cout << "The Mutant have lost some of his stability, making him stumble." << endl;
                                bossDamageChance += 1;
                                Sleep(timeDelay);
                            }
                            else
                            {
                                cout << "You have missed Mutant's legs." << endl;
                                Sleep(timeDelay);
                                cout << "The Mutant have regain his balance." << endl;
                                Sleep(timeDelay);
                            }
                        break;
                        case 2:
                            choice = 0;
                            cout << "You decided to stab the Mutant's arms." << endl;
                            Sleep(timeDelay);
                            hitChance = rand() % 100;
                            if (hitChance >= 100-(50 + (10*bossDamageChance)))
                            {
                                cout << "You managed to hit the Mutant's arms." << endl;
                                bossHealth -= 5;
                                Sleep(timeDelay);
                                cout << "The Mutant have lost control of his arms, making him swing much slower." << endl;
                                bossMissedChance += 1;
                                Sleep(timeDelay);
                            }
                            else
                            {
                                cout << "You have missed the Mutant's arms." << endl;
                                Sleep(timeDelay);
                                cout << "The Mutant have regain his balance." << endl;
                                Sleep(timeDelay);
                            }
                        break;
                        case 3:
                            choice = 0;
                            cout << "You decided to stab the Mutant's torso." << endl;
                            Sleep(timeDelay);
                            hitChance = rand() % 100;
                            if (hitChance >= 100-(70 + (10*bossDamageChance)))
                            {
                                cout << "You managed to hit the Mutant's torso." << endl;
                                Sleep(timeDelay);
                                bossHealth -= 10;
                                cout << "The Mutant yell in pain, and starting to regain his balance again." << endl;
                                Sleep(timeDelay);
                            }
                            else
                            {
                                cout << "You have missed the Mutant's torso." << endl;
                                Sleep(timeDelay);
                                cout << "The Mutant have regain his balance." << endl;
                                Sleep(timeDelay);
                            }
                        break;
                        case 4:
                            choice = 0;
                            cout << "You decided to stab the Mutant's head." << endl;
                            Sleep(timeDelay);
                            hitChance = rand() % 100;
                            if (hitChance >= 100-(10 + (10*bossDamageChance)))
                            {
                                cout << "You managed to hit the Mutant's head." << endl;
                                Sleep(timeDelay);
                                bossHealth -= 50;
                                cout << "The Mutant immediatelly fall onto the ground, bloods spurting from his head." << endl;
                                Sleep(timeDelay);
                            }
                            else
                            {
                                cout << "You have missed Mutant's head." << endl;
                                Sleep(timeDelay);
                                cout << "The Mutant have regain his balance." << endl;
                                Sleep(timeDelay);
                            }
                        break;
                        }
                    }
                    else
                    {
                        cout << "Unable to parry Mutant's strike, you have taken the full force" << endl;
                        Sleep(timeDelay);
                        playerHealth -= 5;
                        cout << "The Mutant is licking its lip, already imagine what you taste like." << endl;
                        Sleep(timeDelay);
                    }
                break;
                default:
                    cout << "You decided to stand infront of the Mutant and do nothing" << endl;
                    Sleep(timeDelay);
                    cout << "The claw's full weight come crashing down on your head" << endl;
                    playerHealth -= 10;
                    Sleep(timeDelay);
                break;
            }
        }
    }
}
