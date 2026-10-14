#include <limits>
#include <stdexcept>
#include "Health.hpp"

Health::Health(int value) : value_(value) {
    if (value < 0) {
        throw std::invalid_argument("Health: value cannot be negative");
    }
}

int Health::value() const { return value_; }

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
