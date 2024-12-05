// Warrior.cpp
#include "Warrior.h"
#include <iostream>

// Constructor implementation
Warrior::Warrior(std::string n, int hp, int mp, int str, int def, FightingStyle fs, SubClass sc)
    : Character(n, hp, mp), strength(str), defense(def), fightingStyle(fs), subClass(sc) {}

// Override the attack action
void Warrior::attack() {
    std::cout << getName() << " attacks with their " << getFightingStyleAsString() << "!";
}

// Override the defend action
void Warrior::defend() {
    std::cout << getName() << " raises their shield!" << std::endl;
}

// Override the special ability
void Warrior::specialAbility() {
    switch (subClass) {
        // Paladin subclass
        case Paladin:
            std::cout << getName() << " casts Holy Light!" << std::endl;
            break;
        // Ranger subclass
        case Ranger:
            std::cout << getName() << " fires a piercing arrow!" << std::endl;
            break;
        // Barbarian subclass
        case Barbarian:
            std::cout << getName() << " enters a rage!" << std::endl;
            break;
    }
}

// Get the fighting style as a string
std::string Warrior::getFightingStyleAsString() const {
    switch (fightingStyle) {
        case SwordAndShield: return "Sword and Shield";
        case TwoHanded: return "Two-Handed Weapon";
        case DualWield: return "Dual Wielded Weapons";
        default: return "Unknown Fighting Style";
    }
}

// Get the subclass as a string
std::string Warrior::getSubClassAsString() const {
    switch (subClass) {
        case Paladin: return "Paladin";
        case Ranger: return "Ranger";
        case Barbarian: return "Barbarian";
        default: return "Unknown Subclass";
    }
}