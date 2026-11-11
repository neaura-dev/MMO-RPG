#pragma once

#include <vector>

#include "Trait.hpp"
class GameObjectObserver;
class NeutralObject;

class GameObject {
public:
    GameObject(int pos_x, int pos_y, Health health, Armor armor, Attack attack);
    virtual ~GameObject();

    GameObject(const GameObject& other) = default;
    GameObject& operator=(const GameObject& other) = delete;
    GameObject(GameObject&& other) = delete;
    GameObject& operator=(GameObject&& other) = delete;

    int pos_x() const { return pos_x_; }
    int pos_y() const { return pos_y_; }
    Health& health() { return health_; }
    Armor& armor() { return armor_; }
    Attack& attack() { return attack_; }
    const Health& health() const { return health_; }
    const Armor& armor() const { return armor_; }
    const Attack& attack() const { return attack_; }

    void change_pos(int pos_x, int pos_y);

    void attach(GameObjectObserver* observer);
    void detach(GameObjectObserver* observer);

    void operator+(NeutralObject& object);
    void operator-(NeutralObject& object);
    void operator*(NeutralObject& object);
    void operator/(NeutralObject& object);

    virtual void take_damage(int amount);

protected:
    int pos_x_;
    int pos_y_;
    Health health_;
    Armor armor_;
    Attack attack_;
    std::vector<GameObjectObserver*> observers_;
};