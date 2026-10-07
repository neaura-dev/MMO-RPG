#pragma once

#include <memory>
#include "Knight.hpp"
#include "Archer.hpp"
#include "Mage.hpp"

class UnitFactory {
public:
    virtual ~UnitFactory() = default;

    virtual std::unique_ptr<Knight> create_knight() const = 0;
    virtual std::unique_ptr<Archer> create_archer() const = 0;
    virtual std::unique_ptr<Mage> create_mage() const = 0;
};