#include "Paladin.hpp"

Paladin::Paladin(int pos_x, int pos_y)
    : Knight(pos_x, pos_y), type_(UnitType::KingdomGuardian) {}

UnitType Paladin::type() const { return type_; }