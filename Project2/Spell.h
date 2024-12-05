// Spell.h
#ifndef SPELL_H
#define SPELL_H

#include <string>

// Spell class
class Spell {
public:
    // Enum for different spell elements
    enum Element {
        Fire,
        Ice,
        Lightning,
        Acid,
        Poison,
        Force,
        Necrotic,
        Radiant
    };

    // Constructor
    Spell(std::string n, float dmg, float manaCost, Element elem);

    // Accessors (Getters)
    // Get Spell name
    std::string getName() const { return name; }
    
    //Get spell damage
    float getDamage() const { return damage; }
    
    // Get spell mana cost
    float getManaCost() const { return manaCost; }
    
    // Get spell element
    Element getElement() const { return element; }

private:
    // Name
    std::string name;
    
    // Damage
    float damage;
    
    // Mana Cost
    float manaCost;
    
    // Element
    Element element;
};

#endif // SPELL_H