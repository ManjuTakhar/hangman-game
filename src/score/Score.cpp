#include "score/Score.h"
#include <algorithm>

Score::Score() : currentScore(0), highScore(0) {
}

void Score::addPoints(int points) {
    if (points > 0) {
        currentScore += points;
        if (currentScore > highScore) {
            highScore = currentScore;
        }
    }
}

void Score::subtractPoints(int points) {
    if (points > 0) {
        currentScore = std::max(0, currentScore - points);
    }
}

void Score::reset() {
    currentScore = 0;
    // TODO: Persist high score before reset
}

void Score::setHighScore(int score) {
    highScore = std::max(highScore, score);
}

bool Score::isNewHighScore() const {
    return currentScore > highScore;
}

std::string Score::toString() const {
    return std::to_string(currentScore);
}

