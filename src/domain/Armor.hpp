#pragma once

#include "Attack.hpp"

class Armor {
public:
    Armor(int value);

    int value() const;

    int reduce_damage(const Attack& attack) const;

private:
    int value_;
};