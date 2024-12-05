// Character.cpp
#include "Character.h"

// Template Constructor Implementation
template<typename T>
Character<T>::Character(std::string n, T hp, T mp) : name(n), health(hp), mana(mp) {
}

// Method to add a special ability to the character
template<typename T>
void Character<T>::addAbility(const std::string& ability) {
    // Check if the ability tree is empty
    if (!abilities) {
        abilities = std::make_shared<AbilityNode>(ability); // Create the root node
    } else {
        std::shared_ptr<AbilityNode> current = abilities;
        while (current) {
            if (ability < current->abilityName) {
                if (!current->left) {
                    current->left = std::make_shared<AbilityNode>(ability);
                    break;
                }
                current = current->left;
            } else {
                if (!current->right) {
                    current->right = std::make_shared<AbilityNode>(ability);
                    break;
                }
                current = current->right;
            }
        }
    }
}

// Get the abilities of the character
template<typename T>
std::shared_ptr<AbilityNode> Character<T>::getAbilities() const {
    // Return the pointer to the root of the ability tree
    return abilities;
}

// Explicit template instantiations
template class Character<int>;
template class Character<float>;