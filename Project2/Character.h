// Character.h
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <memory>
#include <list> 

// Exception Classes
// Exception class for invalid input
class InvalidInputException : public std::runtime_error {
public:
    InvalidInputException(const std::string& message) : std::runtime_error(message) {}
};

// Exception class for invalid attributes, inherits from InvalidInputException
class InvalidAttributeException : public InvalidInputException {
public:
    InvalidAttributeException(const std::string& attributeName)
        : InvalidInputException("Invalid value for " + attributeName + ".") {}
};

// Exception class for invalid spell index, inherits from std::out_of_range
class InvalidSpellIndexException : public std::out_of_range {
public:
    InvalidSpellIndexException() : std::out_of_range("Invalid spell index.") {}
};

// Struct to represent a node in the ability tree
struct AbilityNode {
    // Name of the ability
    std::string abilityName;
    
    // Pointer to the left child node
    std::shared_ptr<AbilityNode> left;
    
    // Pointer to the right child node
    std::shared_ptr<AbilityNode> right;

     // Constructor
    AbilityNode(const std::string& ability) : abilityName(ability), left(nullptr), right(nullptr) {}

    // Comparison operator for alphabetical ordering
    bool operator<(const AbilityNode& other) const {
        return abilityName < other.abilityName;
    }
};

// Template class for Character
template <typename T>
class Character {
public:
    // Constructor
    Character(std::string n, T hp, T mp);

    // Accessors (Getters)
    // Get the name of the character
    std::string getName() const { return name; }
    
    // Get the health of the character
    T getHealth() const { return health; }
    
    // Get the mana of the character
    T getMana() const { return mana; }

    // Mutators (Setters) with Validation
    
    // Set the name of the character
    void setName(const std::string& n);
    
    // Set the health of the character
    void setHealth(T hp);
    
    // Set the mana of the character
    void setMana(T mp) { 
        if (mp >= 0) {
            mana = mp; 
        } else {
            throw InvalidAttributeException("Mana"); 
        }
    }

     // Pure virtual function for attack action
    virtual void attack() = 0;
     
    // Pure virtual function for defend action
    virtual void defend() = 0;
    
    // Pure virtual function for special ability
    virtual void specialAbility() = 0;
    
    

    // Add an ability to the character
    void addAbility(const std::string& ability);

    // Get the abilities of the character
    std::shared_ptr<AbilityNode> getAbilities() const;

private:
    std::string name;
    T health;
    T mana;

    // Using a tree to store abilities (alphabetically)
    std::shared_ptr<AbilityNode> abilities;
};

#endif // CHARACTER_H