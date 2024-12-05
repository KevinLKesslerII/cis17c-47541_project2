// Spell.cpp
#include "Spell.h"
#include <iostream>

// Constructor implementation
Spell::Spell(std::string n, float dmg, float manaCost, Element elem)
    : name(n), damage(dmg), manaCost(manaCost), element(elem) {}