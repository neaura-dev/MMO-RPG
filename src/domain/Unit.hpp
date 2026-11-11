#pragma once

#include "GameObject.hpp"

#include <memory>

class Base;

enum class UnitFamily {
    KingdomGuardian,
    ForestKeeper,
    Undead
};

enum class UnitType {
    Knight,
    Archer,
    Mage
};

class Unit : public GameObject {
public:
    Unit(int pos_x, int pos_y, Health health, Armor armor, Attack attack);
    virtual ~Unit() = default;

    void set_owner_base(Base* base) { owner_base_ = base; }
    Base* get_owner_base() const { return owner_base_; }

    virtual UnitType type() const = 0;
    virtual UnitFamily family() const = 0;
    virtual std::unique_ptr<Unit> clone() const = 0;

protected:
    Base* owner_base_ = nullptr;
};

// TYPES
class Knight : public Unit {
protected:
    Knight(int pos_x, int pos_y);
public:
    UnitType type() const override { return UnitType::Knight; }
};

class Archer : public Unit {
protected:
    Archer(int pos_x, int pos_y);
public:
    UnitType type() const override { return UnitType::Archer; }
};

class Mage : public Unit {
protected:
    Mage(int pos_x, int pos_y);
public:
    UnitType type() const override { return UnitType::Mage; }
};

// KINGDOM GUARDIANS
class Paladin : public Knight {
public:
    Paladin(int pos_x, int pos_y);
    UnitFamily family() const override { return UnitFamily::KingdomGuardian; }
    std::unique_ptr<Unit> clone() const override;
};

class CrossbowMan : public Archer {
public:
    CrossbowMan(int pos_x, int pos_y);
    UnitFamily family() const override { return UnitFamily::KingdomGuardian; }
    std::unique_ptr<Unit> clone() const override;
};

class Cleric : public Mage {
public:
    Cleric(int pos_x, int pos_y);
    UnitFamily family() const override { return UnitFamily::KingdomGuardian; }
    std::unique_ptr<Unit> clone() const override;
};

// FOREST KEEPERS
class Ent : public Knight {
public:
    Ent(int pos_x, int pos_y);
    UnitFamily family() const override { return UnitFamily::ForestKeeper; }
    std::unique_ptr<Unit> clone() const override;
};

class Centaur : public Archer {
public:
    Centaur(int pos_x, int pos_y);
    UnitFamily family() const override { return UnitFamily::ForestKeeper; }
    std::unique_ptr<Unit> clone() const override;
};

class Druid : public Mage {
public:
    Druid(int pos_x, int pos_y);
    UnitFamily family() const override { return UnitFamily::ForestKeeper; }
    std::unique_ptr<Unit> clone() const override;
};

// UNDEADS
class Skeleton : public Knight {
public:
    Skeleton(int pos_x, int pos_y);
    UnitFamily family() const override { return UnitFamily::Undead; }
    std::unique_ptr<Unit> clone() const override;
};

class ShadowArcher : public Archer {
public:
    ShadowArcher(int pos_x, int pos_y);
    UnitFamily family() const override { return UnitFamily::Undead; }
    std::unique_ptr<Unit> clone() const override;
};

class Necromancer : public Mage {
public:
    Necromancer(int pos_x, int pos_y);
    UnitFamily family() const override { return UnitFamily::Undead; }
    std::unique_ptr<Unit> clone() const override;
};