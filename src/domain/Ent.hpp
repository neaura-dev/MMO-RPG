#pragma once

#include "Knight.hpp"

class Ent : public Knight {
public:
    Ent(int pos_x, int pos_y);

    ~Ent() override {};

    UnitType type() const override;

    std::unique_ptr<Unit> clone() const override;

private:
    UnitType type_;
};