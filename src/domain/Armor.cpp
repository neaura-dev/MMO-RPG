#include <stdexcept>
#include "Armor.hpp"

Armor::Armor(int value) : value_(value) {
    if (value < 0) {
        throw std::invalid_argument("Armor: value can not be negative");
    }
}

int Armor::value() const { return value_; }

int Armor::reduce_damage(const Attack& attack) { return attack.value() - value_; }