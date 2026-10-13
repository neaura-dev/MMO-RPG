#pragma once

#include "Archer.hpp"

class ShadowArcher : public Archer {
public:
    ShadowArcher(int pos_x, int pos_y);

    ~ShadowArcher() override {};

    UnitType type() const override;

    std::unique_ptr<Unit> clone() const override;

private:
    UnitType type_;
};