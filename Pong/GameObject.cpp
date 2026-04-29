#include "GameObject.h"
#include <algorithm>

GameObject::GameObject(float x, float y, float width, float height)
    : x(x), y(y), width(width), height(height), active(true)
{
}

bool GameObject::isActive() const {
    return active;
}

void GameObject::setActive(bool active) {
    this->active = active;
}

float GameObject::getX() const {
    return x;
}

float GameObject::getY() const {
    return y;
}

float GameObject::getWidth() const {
    return width;
}

float GameObject::getHeight() const {
    return height;
}

bool GameObject::intersects(const GameObject& other) const {
    return !(x + width / 2 < other.x - other.width / 2 ||
        x - width / 2 > other.x + other.width / 2 ||
        y + height / 2 < other.y - other.height / 2 ||
        y - height / 2 > other.y + other.height / 2);
}
