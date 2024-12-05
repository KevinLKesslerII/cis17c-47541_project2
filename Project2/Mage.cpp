// Mage.cpp
#include "Character.h"
#include "Mage.h"
#include "Spell.h"
#include <iostream>
#include <algorithm> 

// Constructor implementation
Mage::Mage(std::string n, float hp, float mp, float intl, SpellSchool ss, SubClass sc)
    : Character(n, hp, mp), intelligence(intl), spellSchool(ss), subClass(sc)
{
    // Assign spells to the spellbook
    assignSpellbook();
}

// Override the attack action
void Mage::attack() {
    std::cout << getName() << " casts a basic attack spell!" << std::endl;
}

// Override the defend action
void Mage::defend() {
    std::cout << getName() << " erects a magical shield!" << std::endl;
}

// Cast a spell from the spellbook
void Mage::castSpell(int spellIndex) {
    // Using iterators and std::next to access the spell
    // Get an iterator to the beginning of the spellbook
    auto it = spellbook.begin();
    
    // Advance the iterator to the specified index
    std::advance(it, spellIndex);

    // Check if the iterator is at the end of the spellbook
    if (it == spellbook.end()) {
        throw InvalidSpellIndexException(); // Throw an exception if the index is invalid
    }

    // Get a reference to the spell to cast
    Spell& spellToCast = *it;
    // Check if the mage has enough mana
    if (spellToCast.getManaCost() > getMana()) {
        // Throw an exception if not enough mana
        throw std::runtime_error("Not enough mana to cast " + spellToCast.getName());
    }
    // Deduct mana cost from the mage's mana
    setMana(getMana() - spellToCast.getManaCost());
    std::cout << getName() << " casts " << spellToCast.getName() << " for "
              << spellToCast.getDamage() << " damage!" << std::endl;
}

// Override the special ability
void Mage::specialAbility() {
    // Use a switch statement for Mage subclasses
    switch (subClass) {
        // Wizard special
        case Wizard:
            std::cout << getName() << " casts Eldritch Blast!" << std::endl;
            break;
        
            // Warlock special
        case Warlock:
            std::cout << getName() << " uses Misty Step to teleport a short distance!" << std::endl;
            break;
        
            // Sorcerer special
        case Sorcerer:
            std::cout << getName() << " unleashes a chaotic Chaos Bolt!" << std::endl;
            break;
    }
}

// Method to assign spells based on SpellSchool
void Mage::assignSpellbook() {
    spellbook.clear();
    // Create a basic attack spell
    Spell basicAttack("Basic Attack", 5.0f, 0.0f, Spell::Force);
    
    // Create a magical shield spell
    Spell magicalShield("Magical Shield", 0.0f, 5.0f, Spell::Force);
    
    // Add the basic attack spell to the spellbook
    spellbook.push_back(basicAttack);
    
    // Add the magical shield spell to the spellbook
    spellbook.push_back(magicalShield);

    switch (spellSchool) {
        // Evocation school
        case Evocation:
            // Add Fire Bolt spell
            spellbook.push_back(Spell("Fire Bolt", 12.5f, 5.0f, Spell::Fire));
            
            // Add Ray of Frost spell
            spellbook.push_back(Spell("Ray of Frost", 10.0f, 5.0f, Spell::Ice));
            
            // Add Shocking Grasp spell
            spellbook.push_back(Spell("Shocking Grasp", 15.0f, 8.0f, Spell::Lightning));
            break;
        
            // Conjuration school
        case Conjuration:
            // Add Acid Splash spell
            spellbook.push_back(Spell("Acid Splash", 8.0f, 3.0f, Spell::Acid));
            
            // Add Poison Spray spell
            spellbook.push_back(Spell("Poison Spray", 10.0f, 5.0f, Spell::Poison));
            
            // Add Mage Hand spell
            spellbook.push_back(Spell("Mage Hand", 0.0f, 2.0f, Spell::Force));
            break;
            
            //Necromancy school
        case Necromancy:
            // Add Chill Touch spell
            spellbook.push_back(Spell("Chill Touch", 8.0f, 5.0f, Spell::Necrotic));
            
            // Add Inflict Wounds spell
            spellbook.push_back(Spell("Inflict Wounds", 10.0f, 7.0f, Spell::Necrotic));
            
            // Add Ray of Sickness spell
            spellbook.push_back(Spell("Ray of Sickness", 12.0f, 8.0f, Spell::Necrotic));
            break;
    }
}