// Berserker.cpp
#include "Berserker.h"
#include <iostream>
#include <stdexcept>

// Constructor implementation
Berserker::Berserker(std::string n, int hp, int mp, int str, int def, FightingStyle fs, SubClass sc)
    : Warrior(n, hp, mp, str, def, fs, sc), isFrenziedState(false), frenzyDuration(0), exhaustion(false), bloodlustActive(false) {}

void Berserker::attack() {
    if (exhaustion) {   // Check if the Berserker is exhausted
        std::cout << getName() << " is exhausted and cannot attack!" << std::endl;
        return;
    }

    // Call base class attack first
    Warrior::attack(); 

    // Check if the Berserker is in a frenzy state
    if (isFrenziedState) {  
        std::cout << " (Frenzied attack!)";
        frenzyDuration--;   // Decrement the frenzy duration

        // Check if bloodlust is active
        if (bloodlustActive) {  
            std::cout << " Bloodlust activates!";
        } else {
            bloodlustActive = true; // Activate bloodlust on the first frenzied attack
        }

        // Check if the frenzy has ended
        if (frenzyDuration <= 0) {  
            isFrenziedState = false;    // Reset frenzy state
            exhaustion = true;  // Set exhaustion state
            bloodlustActive = false;    // Reset bloodlust
            std::cout << "\n" << getName() << "'s frenzy ends and they become exhausted!" << std::endl;
        }
    }
    std::cout << std::endl;
}

// Override the defend action
void Berserker::defend() {
    // Check if the Berserker is exhausted
    if (exhaustion) {
        std::cout << getName() << " is exhausted and cannot defend!" << std::endl;
        return;
    }
    Warrior::defend();  // Call the base class defend
}

// Enter a frenzy state
void Berserker::frenzy() {
    // Check if the Berserker is exhausted
    if (exhaustion) {
        std::cout << getName() << " is exhausted and cannot enter a frenzy!" << std::endl;
        return;
    }
    isFrenziedState = true;
    frenzyDuration = 3; // 3 turns
    bloodlustActive = false; // Reset bloodlust when frenzy starts
    std::cout << getName() << " enters a frenzy!" << std::endl;
}

// Override the special ability (Frenzied Smash
void Berserker::specialAbility() {
    // Check if the Berserker is in a frenzy state
    if (isFrenziedState) {
        std::cout << getName() << " unleashes a devastating Frenzied Smash!" << std::endl;
    } else {
        throw FrenziedSmashUnavailableException();  // Throw an exception if not frenzied
    }
}