#pragma once

#include <memory>

class GameObject;
class Unit;

class NeutralObject {
public:
    virtual ~NeutralObject() = default;
    
    virtual void interact(GameObject* object) = 0;
    virtual std::unique_ptr<NeutralObject> clone() const = 0;
};

class Chest : public NeutralObject {
public:
    void interact(GameObject* object) override;
    std::unique_ptr<NeutralObject> clone() const override;
};

class Trap : public NeutralObject {
private:
    int damage_;
public:
    Trap(int damage = 30) : damage_(damage) {}
    
    void interact(GameObject* object) override;
    std::unique_ptr<NeutralObject> clone() const override;
};

class Mines : public NeutralObject {
public:
    void interact(GameObject* object) override;
    std::unique_ptr<NeutralObject> clone() const override;
};

class AltarStrategy {
public:
    virtual ~AltarStrategy() = default;
    
    virtual void apply_effect(Unit* unit) = 0;
    virtual std::unique_ptr<AltarStrategy> clone() const = 0;
};

class KnightBuffStrategy : public AltarStrategy {
public:
    void apply_effect(Unit* unit) override;
    std::unique_ptr<AltarStrategy> clone() const override;
};

class ArcherBuffStrategy : public AltarStrategy {
public:
    void apply_effect(Unit* unit) override;
    std::unique_ptr<AltarStrategy> clone() const override;
};

class MageBuffStrategy : public AltarStrategy {
public:
    void apply_effect(Unit* unit) override;
    std::unique_ptr<AltarStrategy> clone() const override;
};

class Altar : public NeutralObject {
public:
    Altar(std::unique_ptr<AltarStrategy> strategy) : strategy_(std::move(strategy)) {}
    
    Altar(const Altar& other);
    
    Altar& operator=(const Altar& other);
    
    void interact(GameObject* object) override;
    std::unique_ptr<NeutralObject> clone() const override;

private:
    std::unique_ptr<AltarStrategy> strategy_;
};