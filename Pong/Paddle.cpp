#include "Paddle.h"
#include "Globals.h"
#include <sgg/graphics.h>
#include <algorithm>

Paddle::Paddle(float x, float y, float width, float height, float speed)
    : GameObject(x, y, width, height), speed(speed)
{
}

void Paddle::updatePlayer() {
    if (graphics::getKeyState(graphics::SCANCODE_UP)) {
        y -= speed;
    }
    if (graphics::getKeyState(graphics::SCANCODE_DOWN)) {
        y += speed;
    }

    // Clamp paddle within window bounds
    y = std::max(height / 2, std::min(static_cast<float>(WINDOW_HEIGHT - height / 2), y));
}

void Paddle::updateCPU(float targetY) {
    if (targetY > y + 10) {
        y += speed;
    }
    else if (targetY < y - 10) {
        y -= speed;
    }

    // Clamp paddle within window bounds
    y = std::max(height / 2, std::min(static_cast<float>(WINDOW_HEIGHT - height / 2), y));
}

void Paddle::draw() const {
    graphics::Brush br;
    br.fill_color[0] = 0.0f;
    br.fill_color[1] = 0.0f;
    br.fill_color[2] = 1.0f;
    br.outline_opacity = 0.0f;
    graphics::drawRect(x, y, width, height, br);
}

void Paddle::setSpeed(float newSpeed) {
    speed = newSpeed;
}
