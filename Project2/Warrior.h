#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"
#include <memory> 

// Warrior class, inherits from Character with int type for health and mana
class Warrior : public Character<int> {
public:
    // Enum for different fighting styles
    enum FightingStyle {
    SwordAndShield,
    TwoHanded,
    DualWield
};
    // Enum for different warrior subclasses
    enum SubClass {
    Paladin,
    Ranger,
    Barbarian
};
    // Constructor
    Warrior(std::string n, int hp, int mp, int str, int def, FightingStyle fs, SubClass sc);

    // Accessors (Getters)
    // Get Warrior strength
    int getStrength() const { return strength; }
    
    // Get WArrior defense
    int getDefense() const { return defense; }
    
    // Get Warrior Fighting Style
    FightingStyle getFightingStyle() const { return fightingStyle; }
    
    // Get WArrior Subclass
    SubClass getSubClass() const { return subClass; }

    // Mutators (Setters)
    // Set Warrior strength
    void setStrength(int str);
    
    // Set WArrior Defense
    void setDefense(int def);
    
    // Set Warrior fighting style
    void setFightingStyle(FightingStyle fs);
    
    // Set Warrior subclass
    void setSubClass(SubClass sc) { subClass = sc; }

    // For displaying enums as strings
    std::string getFightingStyleAsString() const;
    std::string getSubClassAsString() const;

    // Warrior specific actions
    // warrior attack override
    void attack() override;
    
    // warrior defend override
    void defend() override;
    
    // warrior special override
    void specialAbility() override;

private:
    //WArrior strength
    int strength;
    
    //warrior defense
    int defense;
    
    // warrior fighting stryle
    FightingStyle fightingStyle;
    
    // warrior subclass
    SubClass subClass;
};

#endif // WARRIOR_H