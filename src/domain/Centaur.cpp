#include "Centaur.hpp"

Centaur::Centaur(int pos_x, int pos_y)
    : Archer(pos_x, pos_y), type_(UnitType::ForestKeeper) {}

UnitType Centaur::type() const { return type_; }

std::unique_ptr<Unit> Centaur::clone() const {
    return std::make_unique<Centaur>(*this);
}