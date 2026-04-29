#include <sgg/graphics.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <vector>

#include "Globals.h"
#include "GameObject.h"
#include "Ball.h"
#include "Paddle.h"
#include "GameState.h"
#include "AudioManager.h"


static std::vector<std::unique_ptr<GameObject>> gameObjects;
static GameState gameState;


void resetGame() {
    player_score = 0;
    cpu_score = 0;
    game_over = false;

    
    gameState.nextLevel();

   
    for (auto& obj : gameObjects) {
        if (Paddle* p = dynamic_cast<Paddle*>(obj.get())) {
            if (p->getX() > WINDOW_WIDTH / 2) {
                p->setSpeed(5); 
            }
            else {
                p->setSpeed(1 + gameState.getLevel()); // CPU paddle speed increases
            }
        }
        obj->init();
    }
}


void update(float dt) {
   
    Ball* ball = nullptr;
    Paddle* playerPaddle = nullptr;
    Paddle* cpuPaddle = nullptr;

    for (auto& obj : gameObjects) {
        if (Ball* b = dynamic_cast<Ball*>(obj.get())) {
            ball = b;
        }
        else if (Paddle* p = dynamic_cast<Paddle*>(obj.get())) {
           
            if (p->getX() > WINDOW_WIDTH / 2) {
                playerPaddle = p;
            }
            else {
                cpuPaddle = p;
            }
        }
    }

    if (ball && playerPaddle && cpuPaddle) {
        
        ball->update(dt);

        
        playerPaddle->updatePlayer();
        cpuPaddle->updateCPU(ball->getY());

        // Check collision
        if (ball->intersects(*playerPaddle) || ball->intersects(*cpuPaddle)) {
            playCollisionSound();
            ball->reverseX();
        }
    }

    // Check if the game ended
    gameState.update();

    // Press R to restart game if game over
    if (game_over && graphics::getKeyState(graphics::SCANCODE_R)) {
        resetGame();
    }
}


void draw() {
    graphics::Brush br;

    // Draw the background
    br.fill_color[0] = 0.1f;
    br.fill_color[1] = 0.1f;
    br.fill_color[2] = 0.1f;
    graphics::drawRect(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT, br);

    // Center line
    br.fill_color[0] = 1.0f;
    br.fill_color[1] = 1.0f;
    br.fill_color[2] = 1.0f;
    br.outline_opacity = 0.8f;
    graphics::drawLine(WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT, br);

    
    for (auto& obj : gameObjects) {
        obj->draw();
    }

    // Draw UI 
    gameState.draw();
}

// Entry point
int main(int argc, char** argv) {
    
    srand(static_cast<unsigned>(time(nullptr)));

    
    graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Pong Game with Levels");

    
    graphics::setFont("assets/arial.ttf");

    
    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);

    
    playBackgroundMusic();

    
    gameObjects.push_back(std::make_unique<Ball>(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 15));
    gameObjects.push_back(std::make_unique<Paddle>(WINDOW_WIDTH - 30, WINDOW_HEIGHT / 2, 25, 120, 4)); // Player
    gameObjects.push_back(std::make_unique<Paddle>(30, WINDOW_HEIGHT / 2, 25, 120, 2));               // CPU

    // Initialize objects
    for (auto& obj : gameObjects) {
        obj->init();
    }

    
    gameState.init();

    
    graphics::startMessageLoop();

    return 0;
}






























