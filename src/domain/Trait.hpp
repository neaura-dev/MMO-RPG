#pragma once

class Attack;

class Trait {
public:
    explicit Trait (int value);
    virtual ~Trait() = default;

    void decrease(int amount);
    void increase(int amount);

    int value() const;

protected:
    int value_;
};

class Health : public Trait {
public:
    explicit Health(int value);

    bool isZero() const;
};

class Armor : public Trait {
public:
    explicit Armor(int value);

    int reduce_damage(const Attack& attack) const;
};

class Attack : public Trait {
public:
    explicit Attack(int value);

    int calculate_damage(const Armor& armor) const;
};