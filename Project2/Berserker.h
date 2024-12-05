#ifndef BERSERKER_H
#define BERSERKER_H

#include "Warrior.h"

// Exception class for when Frenzied Smash is unavailable
class FrenziedSmashUnavailableException : public std::runtime_error {
public:
    FrenziedSmashUnavailableException()
        : std::runtime_error("Berserker is not frenzied. Frenzied Smash is unavailable.") {}
};

// Berserker class, inherits from Warrior
class Berserker : public Warrior {
public:
    // Constructor
    Berserker(std::string n, int hp, int mp, int str, int def, FightingStyle fs, SubClass sc);

    // Accessor (Getter)
    bool isFrenzied() const { return isFrenziedState; }

    // Mutator (Setter)
    void setFrenzied(bool f) { isFrenziedState = f; }

    // Berserker-specific actions
    // Override the attack action
    void attack() override;
    
    // Override the defend action
    void defend() override;
    
    // Enter a frenzy state
    void frenzy();
    
    // Frenzied Smash
    void specialAbility() override;  

private:
    // Flag to track if the Berserker is frenzie
    bool isFrenziedState;
    
    // Duration of the frenzy state
    int frenzyDuration;
    
    // Flag to track if the Berserker is exhausted
    bool exhaustion;
    
    // Flag to track if bloodlust is active
    bool bloodlustActive;
};

#endif // BERSERKER_H