#include <stdexcept>
#include <limits>
#include "Trait.hpp"

Trait::Trait(int value) : value_(value) {
    if (value < 0) {
        throw std::invalid_argument("Trait: value cannot be negative");
    }
}

int Trait::value() const { return value_; }

Health::Health(int value) : Trait(value) {
    if (value < 0) {
        throw std::invalid_argument("Health: value cannot be negative");
    }
}

void Health::decrease(int amount) {
    if (amount < 0) {
        throw std::invalid_argument("Health: amount cannot be negative");
    }
    value_ = (amount >= value_) ? 0 : value_ - amount;
}

void Health::increase(int amount) {
    if (amount < 0) {
        throw std::invalid_argument("Health: amount cannot be negative");
    }
    if (amount > std::numeric_limits<int>::max() - value_) {
        throw std::overflow_error("Health: value would overflow");
    }
    value_ += amount;
}

bool Health::isZero() const { return value_ == 0; }

Armor::Armor(int value) : Trait(value) {
    if (value < 0) {
        throw std::invalid_argument("Armor: value cannot be negative");
    }
}

int Armor::reduce_damage(const Attack& attack) const {
    return std::max(0, attack.value() - value_);
}

Attack::Attack(int value) : Trait(value) {
    if (value < 0) {
        throw std::invalid_argument("Attack: value cannot be negative");
    }
}

int Attack::calculate_damage(const Armor& armor) const {
    return std::max(0, value_ - armor.value());
}