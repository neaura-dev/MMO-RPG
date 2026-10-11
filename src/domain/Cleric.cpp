#include "Cleric.hpp"

Cleric::Cleric(int pos_x, int pos_y)
    : Mage(pos_x, pos_y), type_(UnitType::KingdomGuardian) {}

UnitType Cleric::type() const { return type_; }