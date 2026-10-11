#pragma once

#include "Mage.hpp"

class Cleric : public Mage {
public:
    Cleric(int pos_x, int pos_y);

    ~Cleric() override {};

    UnitType type() const override;

private:
    UnitType type_;
};