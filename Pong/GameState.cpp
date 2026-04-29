#include "GameState.h"
#include "Globals.h"
#include <sgg/graphics.h>
#include <string>

GameState::GameState() : level(1) {}

void GameState::init() {
    level = 1;
}

void GameState::update() {
    // Check if someone reached the winning score
    if (player_score >= WIN_SCORE || cpu_score >= WIN_SCORE) {
        game_over = true;
    }
}

void GameState::nextLevel() {
    level++;
}

int GameState::getLevel() const {
    return level;
}

void GameState::draw() const {
    graphics::Brush br;
    br.fill_color[0] = 1.0f;
    br.fill_color[1] = 1.0f;
    br.fill_color[2] = 1.0f;

    // Draw scores
    graphics::drawText(200, 50, 30, "Cpu:  " + std::to_string(player_score), br);
    graphics::drawText(600, 50, 30, "Player:  " + std::to_string(cpu_score), br);

    // Draw level
    graphics::drawText(50, 20, 20, "Level: " + std::to_string(level), br);

    // Game Over Message
    if (game_over) {
        graphics::drawText(WINDOW_WIDTH / 2 - 100, WINDOW_HEIGHT / 2 - 100, 40, "GAME OVER!", br);
        graphics::drawText(WINDOW_WIDTH / 2 - 70, WINDOW_HEIGHT / 2 + 50, 20, "Press R to Restart", br);
    }
}
