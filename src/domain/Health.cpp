#include <stdexcept>
#include "Health.hpp"

Health::Health(int value) : value_(value) {
    if (value < 0) {
        throw std::invalid_argument("Health: value can not be negative");
    }
}

int Health::value() const { return value_; }

void Health::decrease(int amount) {
    if (amount < 0) {
        throw std::invalid_argument("Health: amount can not be negative");
    }
    value_ += amount;
}

void Health::increase(int amount) {
    if (amount < 0) {
        throw std::invalid_argument("Health: amount can not be negative");
    }
    if (amount > value_) {
        value_ = 0;
    }
    else {
        value_ -= amount;
    }
}

bool Health::isZero() const { return value_ == 0; }