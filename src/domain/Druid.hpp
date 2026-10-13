#pragma once

#include "Mage.hpp"

class Druid : public Mage {
public:
    Druid(int pos_x, int pos_y);

    ~Druid() override {};

    UnitType type() const override;

    std::unique_ptr<Unit> clone() const override;

private:
    UnitType type_;
};