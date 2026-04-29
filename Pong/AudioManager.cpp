#include "AudioManager.h"
#include "Globals.h"
#include <sgg/graphics.h>

void playBackgroundMusic() {
    if (!music_playing) {
        graphics::playSound("assets/background_music.mp3", 1.0f, true);
        music_playing = true;
    }
}

void playCollisionSound() {
    graphics::playSound("assets/collision_sound.mp3", 0.3f, false);
}
