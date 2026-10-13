#pragma once

#include "Knight.hpp"

class Paladin : public Knight {
public:
    Paladin(int pos_x, int pos_y);

    ~Paladin() override {};

    UnitType type() const override;

    std::unique_ptr<Unit> clone() const override;

private:
    UnitType type_;
};