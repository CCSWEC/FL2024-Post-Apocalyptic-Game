#ifndef CHARACTERS_H
#define CHARACTERS_H
#include <iostream>
#include <string>

// Base Character class that defines common attributes and methods
class Character {
protected:
	// Basic stats for all characters
	int health;      // Character's health points
	int damage;      // Attack damage
	int defense;     // Defense points
	int accuracy;    // Hit accuracy percentage
	std::string personalityType;    // MBTI personality type
	std::string personalityDesc;    // Description of personality

public:
	// Constructor to initialize all character attributes
	Character(int h, int d, int def, int acc, std::string type, std::string desc)
		: health(h), damage(d), defense(def), accuracy(acc),
		  personalityType(type), personalityDesc(desc) {}

	// Pure virtual function that must be implemented by derived classes
	virtual void displayStats() const = 0;
};

// Guardian class - Tank type character with high health and defense
class Guardian : public Character {
public:
	// Initialize Guardian with specific stats and ISFJ personality
	Guardian() : Character(30, 5, 15, 50, "ISFJ",
		                       "Protective Defender - Dedicated protector who is loyal and caring") {}

	// Display Guardian's specific stats and personality
	void displayStats() const override {
		std::cout << "Guardian Stats:\n"
		          << "Health: " << health << "\n"
		          << "Damage: " << damage << "\n"
		          << "Defense: " << defense << "\n"
		          << "Accuracy: " << accuracy << "\n"
		          << "Personality: " << personalityType << " - " << personalityDesc << "\n\n";
	}
};

// Berserk class - High damage dealer with low defense
class Berserk : public Character {
public:
	// Initialize Berserk with specific stats and ESTP personality

	// Display Berserk's specific stats and personality
	void displayStats() const override {
		std::cout << "Health: " << health << "\n"
		          << "Damage: " << damage << "\n"
		          << "Defense: " << defense << "\n"
		          << "Accuracy: " << accuracy << "\n"
		          << "Personality: " << personalityType << " - " << personalityDesc << "\n\n";
	}
};

// Soldier class - Balanced character with high accuracy
class Soldier : public Character {
public:
	// Initialize Soldier with specific stats and ISTJ personality
	Soldier() : Character(20, 10, 10, 70, "ISTJ",
		                      "Disciplined Logistician - Practical and fact-minded individual") {}

	// Display Soldier's specific stats and personality
	void displayStats() const override {
		std::cout << "Soldier Stats:\n"
		          << "Health: " << health << "\n"
		          << "Damage: " << damage << "\n"
		          << "Defense: " << defense << "\n"
		          << "Accuracy: " << accuracy << "\n"
		          << "Personality: " << personalityType << " - " << personalityDesc << "\n\n";
	}
};

#endif



int main() {
    // Create instances of each character type
    Guardian guardian;
    Soldier soldier;

    // Display header for the character stats
    std::cout << "Game Characters and Their Characteristics\n";
    std::cout << "=========================================\n\n";
    
    // Display stats for each character
    guardian.displayStats();
    soldier.displayStats();

    return 0;
}