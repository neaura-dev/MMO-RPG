#include <algorithm>
#include <stdexcept>
#include "Attack.hpp"
#include "Armor.hpp"

Attack::Attack(int value) : value_(value) {
    if (value < 0) {
        throw std::invalid_argument("Attack: value cannot be negative");
    }
}

int Attack::value() const { return value_; }

int Attack::calculate_damage(const Armor& armor) const {
    return std::max(0, value_ - armor.value());
}
