#include <stdexcept>
#include <limits>
#include "Trait.hpp"

// ----- TRAIT -----

Trait::Trait(int value) : value_(value) {
    if (value < 0) {
        throw std::invalid_argument("Trait: value cannot be negative");
    }
}

void Trait::increase(int amount) {
    if (amount < 0) {
        throw std::invalid_argument("Trait: amount cannot be negative");
    }
    if (amount > std::numeric_limits<int>::max() - value_) {
        throw std::overflow_error("Trait: value would overflow");
    }
    value_ += amount;
}

void Trait::decrease(int amount) {
    if (amount < 0) {
        throw std::invalid_argument("Trait: amount cannot be negative");
    }
    if (amount >= value_) {
        value_ = 0;
    }
    else {
        value_ -= amount;
    }
}

int Trait::value() const { return value_; }

// ----- HEALTH -----

Health::Health(int value) : Trait(value) {
    if (value < 0) {
        throw std::invalid_argument("Health: value cannot be negative");
    }
}

bool Health::isZero() const { return value_ == 0; }

// ----- ARMOR -----

Armor::Armor(int value) : Trait(value) {
    if (value < 0) {
        throw std::invalid_argument("Armor: value cannot be negative");
    }
}

int Armor::reduce_damage(const Attack& attack) const {
    return std::max(0, attack.value() - value_);
}

// ----- ATTACK -----

Attack::Attack(int value) : Trait(value) {
    if (value < 0) {
        throw std::invalid_argument("Attack: value cannot be negative");
    }
}

int Attack::calculate_damage(const Armor& armor) const {
    return std::max(0, value_ - armor.value());
}