#pragma once

#include "Armor.hpp"

class Attack {
public:
    Attack(int value);

    int value() const;

    int calculate_damage(const Armor& armor) const;

private:
    int value_;
};