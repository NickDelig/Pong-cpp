#pragma once

#include "GameObject.h"

class Ball : public GameObject {
private:
    float speed_x, speed_y;
    float radius;
    const float initial_speed = 0.5f;

public:
    Ball(float x, float y, float radius);

    void init() override;
    void update(float dt) override;
    void draw() const override;

    void reset();
    void reverseX();
};









