#include "ShadowArcher.hpp"

ShadowArcher::ShadowArcher(int pos_x, int pos_y)
    : Archer(pos_x, pos_y), type_(UnitType::Undead) {}

UnitType ShadowArcher::type() const { return type_; }

std::unique_ptr<Unit> ShadowArcher::clone() const {
    return std::make_unique<ShadowArcher>(*this);
}