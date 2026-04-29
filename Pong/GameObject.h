#pragma once

#include <sgg/graphics.h>

class GameObject {
protected:
    float x, y, width, height;
    bool active;

public:
    GameObject(float x, float y, float width, float height);
    virtual ~GameObject() = default;

    virtual void init() {}
    virtual void update(float dt) {}
    virtual void draw() const {}

    bool isActive() const;
    void setActive(bool active);

    float getX() const;
    float getY() const;
    float getWidth() const;
    float getHeight() const;

    bool intersects(const GameObject& other) const;
};

