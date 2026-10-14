#pragma once

#include <memory>
#include "Health.hpp"
#include "Armor.hpp"
#include "Attack.hpp"

enum class UnitType {
    KingdomGuardian,
    ForestKeeper,
    Undead
};

class Unit {
public:
    Unit(int pos_x, int pos_y, Health health, Armor armor, Attack attack);

    virtual ~Unit() = default;

    Unit(const Unit& other) = default;
    Unit& operator=(const Unit& other) = delete;

    Unit(Unit&& other) = delete;
    Unit& operator=(Unit&& other) = delete;

    int pos_x() const;
    int pos_y() const;
    Health& health();
    const Health& health() const;
    const Armor& armor() const;
    const Attack& attack() const;

    void change_pos(int pos_x, int pos_y);

    virtual UnitType type() const = 0;

    virtual std::unique_ptr<Unit> clone() const = 0;

private:
    int pos_x_;
    int pos_y_;
    Health health_;
    Armor armor_;
    Attack attack_;
};