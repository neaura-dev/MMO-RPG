#include "Ent.hpp"

Ent::Ent(int pos_x, int pos_y)
    : Knight(pos_x, pos_y), type_(UnitType::ForestKeeper) {}

UnitType Ent::type() const { return type_; }

std::unique_ptr<Unit> Ent::clone() const {
    return std::make_unique<Ent>(*this);
}