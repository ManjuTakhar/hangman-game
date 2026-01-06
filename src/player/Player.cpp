#include "player/Player.h"
#include "display/DisplayManager.h"
#include <algorithm>

Player::Player(const std::string& name) 
    : name(name), lives(6), maxLives(6), gamesPlayed(0), gamesWon(0) {
}

void Player::setLives(int lives) {
    this->lives = std::max(0, std::min(lives, maxLives));
    this->maxLives = lives;
}

void Player::loseLife() {
    if (lives > 0) {
        lives--;
    }
    // TODO: Trigger life lost event/notification
}

void Player::gainLife() {
    if (lives < maxLives) {
        lives++;
    }
    // TODO: Trigger life gained event/notification
}

void Player::addScore(int points) {
    score.addPoints(points);
    // TODO: Update high score if applicable
}

void Player::incrementGamesPlayed() {
    gamesPlayed++;
}

void Player::incrementGamesWon() {
    gamesWon++;
}

void Player::reset() {
    lives = maxLives;
    score.reset();
    // TODO: Reset other game-specific stats
}

void Player::render(DisplayManager& display) {
    // TODO: Render player name
    // TODO: Render lives indicator
    // TODO: Render score display
    // display.renderText(name + " - Lives: " + std::to_string(lives), x, y);
}

