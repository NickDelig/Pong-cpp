#pragma once

class GameState {
private:
    int level;

public:
    GameState();
    void init();
    void update();
    void nextLevel();
    int getLevel() const;
    void draw() const;
};

