// Mage.h
#ifndef MAGE_H
#define MAGE_H

#include "Character.h"
#include "Spell.h"
#include <list>

// Exception class for invalid spell school selection
class InvalidSpellSchoolException : public std::runtime_error {
public:
    InvalidSpellSchoolException() : std::runtime_error("Invalid spell school selected.") {}
};

// Exception class for invalid spellbook selection
class InvalidSpellBookSelectionException : public std::runtime_error {
public:
    InvalidSpellBookSelectionException() : std::runtime_error("Invalid spellbook selection. Spell not found in the current spellbook.") {}
};

// Mage class, inherits from Character with float type for health and mana
class Mage : public Character<float> {
public:
    // Enum for different spell schools
    enum SpellSchool {
        Evocation,
        Conjuration,
        Necromancy
    };

    // Enum for different mage subclasses
    enum SubClass {
        Wizard,
        Warlock,
        Sorcerer
    };

    // Constructor
    Mage(std::string n, float hp, float mp, float intl, SpellSchool ss, SubClass sc);

    // Accessors
    // Get the intelligence of the mage
    float getIntelligence() const { return intelligence; }
    
    // Get the spell school of the mage
    SpellSchool getSpellSchool() const { return spellSchool; }
    
    // Get the subclass of the mage
    SubClass getSubClass() const { return subClass; }
    
     // Get the spellbook of the mage
    const std::list<Spell>& getSpellbook() const { return spellbook; } // Changed to std::list

    // Mutators
    // Set the intelligence of the mage
    void setIntelligence(float intl);
    
    // Set the spell school of the mage
    void setSpellSchool(SpellSchool ss);
    
    // Set the subclass of the mage
    void setSubClass(SubClass sc) { subClass = sc; }

    // Mage specific actions
    // Override the attack action
    void attack() override;
    
    // Override the defend action
    void defend() override;
    
    // Cast a spell from the spellbook
    void castSpell(int spellIndex);
    
    // Override the special ability
    void specialAbility() override;

private:
    // Assign spells to the spellbook based on spell school
    void assignSpellbook();

    // Intelligence of the mage
    float intelligence;
    
    // Spell school of the mage
    SpellSchool spellSchool;
    
    // Subclass of the mage
    SubClass subClass;
    
    // List of spells in the mage's spellbook
    std::list<Spell> spellbook;
};

#endif // MAGE_H