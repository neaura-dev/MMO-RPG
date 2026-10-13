#include "Druid.hpp"

Druid::Druid(int pos_x, int pos_y)
    : Mage(pos_x, pos_y), type_(UnitType::ForestKeeper) {}

UnitType Druid::type() const { return type_; }

std::unique_ptr<Unit> Druid::clone() const {
    return std::make_unique<Druid>(*this);
}