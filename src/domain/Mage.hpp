#pragma once

#include "Unit.hpp"

class Mage : public Unit {
public:
    Mage(int pos_x, int pos_y);

    ~Mage() override {};
};