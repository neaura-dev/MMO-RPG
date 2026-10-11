#pragma once

#include "Archer.hpp"

class ShadowArcher : public Archer {
public:
    ShadowArcher(int pos_x, int pos_y);

    ~ShadowArcher() override {};

    UnitType type() const override;

private:
    UnitType type_;
};