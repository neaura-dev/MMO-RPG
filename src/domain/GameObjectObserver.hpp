#pragma once

class GameObject;

class GameObjectObserver {
public:
    virtual ~GameObjectObserver() = default;

    virtual void on_object_created(GameObject* object) = 0;
    virtual void on_object_destroyed(GameObject* object) = 0;
};