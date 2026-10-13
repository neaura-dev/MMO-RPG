#pragma once

#include "Archer.hpp"

class CrossbowMan : public Archer {
public:
    CrossbowMan(int pos_x, int pos_y);

    ~CrossbowMan() override {};

    UnitType type() const override;

    std::unique_ptr<Unit> clone() const override;

private:
    UnitType type_;
};