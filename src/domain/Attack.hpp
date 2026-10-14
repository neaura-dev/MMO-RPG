#pragma once

class Armor;

class Attack {
public:
    explicit Attack(int value);

    int value() const;

    int calculate_damage(const Armor& armor) const;

private:
    int value_;
};