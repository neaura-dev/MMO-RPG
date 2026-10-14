#pragma once

class Attack;

class Armor {
public:
    explicit Armor(int value);

    int value() const;

    int reduce_damage(const Attack& attack) const;

private:
    int value_;
};