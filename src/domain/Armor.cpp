#include <algorithm>
#include <stdexcept>
#include "Armor.hpp"
#include "Attack.hpp"

Armor::Armor(int value) : value_(value) {
    if (value < 0) {
        throw std::invalid_argument("Armor: value cannot be negative");
    }
}

int Armor::value() const { return value_; }

int Armor::reduce_damage(const Attack& attack) const {
    return std::max(0, attack.value() - value_);
}
