#pragma once

#include "Armor.hpp"

class Attack {
public:
    Attack(int value);

    int value() const;

    int calculateDamage(const Armor& armor);

private:
    int value_;
};