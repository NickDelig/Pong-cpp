#pragma once

#include "GameObject.h"

class Paddle : public GameObject {
private:
    float speed;

public:
    Paddle(float x, float y, float width, float height, float speed);

    void updatePlayer();
    void updateCPU(float targetY);
    void draw() const override;

    void setSpeed(float newSpeed);
};

