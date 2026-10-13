#pragma once

#include "Mage.hpp"

class Necromancer : public Mage {
public:
    Necromancer(int pos_x, int pos_y);

    ~Necromancer() override {};

    UnitType type() const override;

    std::unique_ptr<Unit> clone() const override;

private:
    UnitType type_;
};