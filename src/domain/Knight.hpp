#pragma once

#include "Unit.hpp"

class Knight : public Unit {
public:
    Knight(int pos_x, int pos_y);

    ~Knight() override {};
};