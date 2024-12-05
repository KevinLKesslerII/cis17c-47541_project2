/* main.cpp
 Author: Kevin L Kessler II*/

#include <iostream>
#include <limits>
#include <string>
#include <list>
#include <iterator>
#include "Character.h"
#include "Warrior.h"
#include "Mage.h"
#include "Berserker.h"
#include "Spell.h"

// Function to display abilities using recursion
void displayAbilities(const std::shared_ptr<AbilityNode>& node) {
    if (node) {
        displayAbilities(node->left);
        std::cout << node->abilityName << std::endl;
        displayAbilities(node->right);
    }
}

int main() {
    std::cout << "Welcome to the D&D Character Creator and Tester!" << std::endl;

    while (true) {
        std::cout << "\nChoose a character type:\n";
        std::cout << "1. Warrior\n2. Mage\n3. Berserker\n4. Exit\n";
        int choice;
        std::cin >> choice;
        if (choice == 4) {
            break;
        }

        try {
            std::string name;
            std::cout << "Enter character name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            if (name.empty()) {
                throw InvalidInputException("Name cannot be empty.");
            }

            switch (choice) {
                case 1: { // Warrior
                    int hp, mp, strength, defense;
                    Warrior::FightingStyle fightingStyle;
                    Warrior::SubClass subClass;

                    std::cout << "Enter HP: ";
                    std::cin >> hp;
                    std::cout << "Enter MP: ";
                    std::cin >> mp;
                    std::cout << "Enter Strength: ";
                    std::cin >> strength;
                    std::cout << "Enter Defense: ";
                    std::cin >> defense;
                    std::cout << "Choose Fighting Style (0: SwordAndShield, 1: TwoHanded, 2: DualWield): ";
                    int fsChoice;
                    std::cin >> fsChoice;
                    fightingStyle = static_cast<Warrior::FightingStyle>(fsChoice);
                    std::cout << "Choose Subclass (0: Paladin, 1: Ranger, 2: Barbarian): ";
                    int scChoice;
                    std::cin >> scChoice;
                    subClass = static_cast<Warrior::SubClass>(scChoice);

                    Warrior warrior(name, hp, mp, strength, defense, fightingStyle, subClass);

                    warrior.addAbility("Slash");
                    warrior.addAbility("Block");
                    warrior.addAbility("Lunge");

                    std::cout << "\n--- Testing " << warrior.getName() << " ---" << std::endl;
                    std::cout << "Subclass: " << warrior.getSubClassAsString() << std::endl;
                    std::cout << "Fighting Style: " << warrior.getFightingStyleAsString() << std::endl;
                    std::cout << "\nAbilities:" << std::endl;
                    displayAbilities(warrior.getAbilities());

                    warrior.attack();
                    warrior.defend();
                    warrior.specialAbility();

                    break;
                }
                case 2: { // Mage
                    float hp, mp, intelligence;
                    Mage::SpellSchool spellSchool;
                    Mage::SubClass subClass;

                    std::cout << "Enter HP: ";
                    std::cin >> hp;
                    std::cout << "Enter MP: ";
                    std::cin >> mp;
                    std::cout << "Enter Intelligence: ";
                    std::cin >> intelligence;
                    std::cout << "Choose Spell School (0: Evocation, 1: Conjuration, 2: Necromancy): ";
                    int ssChoice;
                    std::cin >> ssChoice;
                    spellSchool = static_cast<Mage::SpellSchool>(ssChoice);
                    std::cout << "Choose Subclass (0: Wizard, 1: Warlock, 2: Sorcerer): ";
                    int scChoice;
                    std::cin >> scChoice;
                    subClass = static_cast<Mage::SubClass>(scChoice);

                    Mage mage(name, hp, mp, intelligence, spellSchool, subClass);

                    std::cout << "\n" << mage.getName() << "'s Spellbook:\n";
                    int i = 0;
                    for (auto it = mage.getSpellbook().begin(); it != mage.getSpellbook().end(); ++it, ++i) {
                        std::cout << i << ". " << it->getName() << " ("
                                  << it->getDamage() << " damage, "
                                  << it->getManaCost() << " mana)\n";
                    }

                    mage.attack();
                    mage.defend();
                    mage.specialAbility();

                    // Get spell index input and call castSpell
                    int spellIndex;
                    std::cout << "Enter the index of the spell to cast: ";
                    std::cin >> spellIndex;
                    mage.castSpell(spellIndex); 

                    break;
                }
                case 3: { // Berserker
                    int hp, mp, strength, defense;
                    Warrior::FightingStyle fightingStyle;
                    Warrior::SubClass subClass;

                    std::cout << "Enter HP: ";
                    std::cin >> hp;
                    std::cout << "Enter MP: ";
                    std::cin >> mp;
                    std::cout << "Enter Strength: ";
                    std::cin >> strength;
                    std::cout << "Enter Defense: ";
                    std::cin >> defense;
                    std::cout << "Choose Fighting Style (0: SwordAndShield, 1: TwoHanded, 2: DualWield): ";
                    int fsChoice;
                    std::cin >> fsChoice;
                    fightingStyle = static_cast<Warrior::FightingStyle>(fsChoice);
                    std::cout << "Choose Subclass (0: Paladin, 1: Ranger, 2: Barbarian): ";
                    int scChoice;
                    std::cin >> scChoice;
                    subClass = static_cast<Warrior::SubClass>(scChoice);

                    Berserker berserker(name, hp, mp, strength, defense, fightingStyle, subClass);

                    berserker.attack();
                    berserker.defend();
                    berserker.frenzy();
                    berserker.attack(); // Attack while frenzied
                    berserker.specialAbility();

                    break;
                }
            } 

            // ... (Catch blocks) ...

        } catch (const InvalidAttributeException& e) { 
            std::cerr << "Error: " << e.what() << std::endl; 
        } catch (const InvalidSpellIndexException& e) { 
            std::cerr << "Error: " << e.what() << std::endl; 
        } catch (const std::out_of_range& e) { 
            std::cerr << "Error: Index out of range." << std::endl; 
        } catch (const InvalidInputException& e) { 
            std::cerr << "Error: " << e.what() << std::endl; 
        } catch (const std::runtime_error& e) { 
            std::cerr << "Error: " << e.what() << std::endl; 
        } 

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Exiting program. Goodbye!" << std::endl;
    return 0;
}