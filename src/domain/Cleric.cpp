#include "Cleric.hpp"

Cleric::Cleric(int pos_x, int pos_y)
    : Mage(pos_x, pos_y), type_(UnitType::KingdomGuardian) {}

UnitType Cleric::type() const { return type_; }

std::unique_ptr<Unit> Cleric::clone() const {
    return std::make_unique<Cleric>(*this);
}