#include "Ball.h"
#include "Globals.h"
#include <sgg/graphics.h>
#include <cstdlib>

Ball::Ball(float x, float y, float radius)
    : GameObject(x, y, radius * 2, radius * 2), speed_x(0), speed_y(0), radius(radius)
{
}

void Ball::init() {
    reset();
}

void Ball::update(float dt) {
    if (!active || game_over) return;

    x += speed_x * dt;
    y += speed_y * dt;

    // Bounce off top and bottom walls
    if (y - radius <= 0 || y + radius >= WINDOW_HEIGHT) {
        speed_y = -speed_y;
    }

    // Check scoring
    if (x - radius <= 0) {
        cpu_score++;
        reset();
    }
    else if (x + radius >= WINDOW_WIDTH) {
        player_score++;
        reset();
    }
}

void Ball::draw() const {
    graphics::Brush br;
    br.fill_color[0] = 1.0f;
    br.fill_color[1] = 1.0f;
    br.fill_color[2] = 1.0f;
    br.outline_opacity = 0.0f;
    graphics::drawDisk(x, y, radius, br);
}

void Ball::reset() {
    x = WINDOW_WIDTH / 2;
    y = WINDOW_HEIGHT / 2;
    speed_x = initial_speed * ((rand() % 2 == 0) ? 1 : -1);
    speed_y = initial_speed * ((rand() % 2 == 0) ? 1 : -1);
}

void Ball::reverseX() {
    speed_x = -speed_x;
}
