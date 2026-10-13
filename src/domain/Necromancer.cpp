#include "Necromancer.hpp"

Necromancer::Necromancer(int pos_x, int pos_y)
    : Mage(pos_x, pos_y), type_(UnitType::Undead) {}

UnitType Necromancer::type() const { return type_; }

std::unique_ptr<Unit> Necromancer::clone() const {
    return std::make_unique<Necromancer>(*this);
}