#pragma once

#include <memory>
#include "Trait.hpp"

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

class Knight : public Unit {
public:
    Knight(int pos_x, int pos_y);

    ~Knight() override {};
};

class Archer : public Unit {
public:
    Archer(int pos_x, int pos_y);
    
    ~Archer() override {};
};

class Mage : public Unit {
public:
    Mage(int pos_x, int pos_y);

    ~Mage() override {};
};

// Kingdom Guardians

class Paladin : public Knight {
public:
    Paladin(int pos_x, int pos_y);

    ~Paladin() override {};

    UnitType type() const override;

    std::unique_ptr<Unit> clone() const override;

private:
    UnitType type_;
};

class CrossbowMan : public Archer {
public:
    CrossbowMan(int pos_x, int pos_y);

    ~CrossbowMan() override {};

    UnitType type() const override;

    std::unique_ptr<Unit> clone() const override;

private:
    UnitType type_;
};

class Cleric : public Mage {
public:
    Cleric(int pos_x, int pos_y);

    ~Cleric() override {};

    UnitType type() const override;

    std::unique_ptr<Unit> clone() const override;

private:
    UnitType type_;
};

// Forest Keepers

class Ent : public Knight {
public:
    Ent(int pos_x, int pos_y);

    ~Ent() override {};

    UnitType type() const override;

    std::unique_ptr<Unit> clone() const override;

private:
    UnitType type_;
};

class Centaur : public Archer {
public:
    Centaur(int pos_x, int pos_y);

    ~Centaur() override {};

    UnitType type() const override;

    std::unique_ptr<Unit> clone() const override;

private:
    UnitType type_;
};

class Druid : public Mage {
public:
    Druid(int pos_x, int pos_y);

    ~Druid() override {};

    UnitType type() const override;

    std::unique_ptr<Unit> clone() const override;

private:
    UnitType type_;
};

// Undeads

class Skeleton : public Knight {
public:
    Skeleton(int pos_x, int pos_y);

    ~Skeleton() override {};

    UnitType type() const override;

    std::unique_ptr<Unit> clone() const override;

private:
    UnitType type_;
};

class ShadowArcher : public Archer {
public:
    ShadowArcher(int pos_x, int pos_y);

    ~ShadowArcher() override {};

    UnitType type() const override;

    std::unique_ptr<Unit> clone() const override;

private:
    UnitType type_;
};

class Necromancer : public Mage {
public:
    Necromancer(int pos_x, int pos_y);

    ~Necromancer() override {};

    UnitType type() const override;

    std::unique_ptr<Unit> clone() const override;

private:
    UnitType type_;
};