#pragma once

#include "Archer.hpp"

class Centaur : public Archer {
public:
    Centaur(int pos_x, int pos_y);

    ~Centaur() override {};

    UnitType type() const override;

private:
    UnitType type_;
};