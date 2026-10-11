#pragma once

#include "Knight.hpp"

class Skeleton : public Knight {
public:
    Skeleton(int pos_x, int pos_y);

    ~Skeleton() override {};

    UnitType type() const override;

private:
    UnitType type_;
};