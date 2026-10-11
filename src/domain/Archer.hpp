#pragma once

#include "Unit.hpp"

class Archer : public Unit {
public:
    Archer(int pos_x, int pos_y);
    
    ~Archer() override {};
};