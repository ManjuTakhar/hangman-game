#ifndef HANGMAN_PLAYER_H
#define HANGMAN_PLAYER_H

#include "display/DisplayManager.h"
#include "score/Score.h"
#include <string>

class Player {
private:
    std::string name;
    int lives;
    int maxLives;
    Score score;
    int gamesPlayed;
    int gamesWon;
    
public:
    explicit Player(const std::string& name);
    ~Player() = default;
    
    void setName(const std::string& name) { this->name = name; }
    std::string getName() const { return name; }
    
    void setLives(int lives);
    int getLives() const { return lives; }
    int getMaxLives() const { return maxLives; }
    
    void loseLife();
    void gainLife();
    bool isAlive() const { return lives > 0; }
    
    void addScore(int points);
    Score getScore() const { return score; }
    
    void incrementGamesPlayed();
    void incrementGamesWon();
    int getGamesPlayed() const { return gamesPlayed; }
    int getGamesWon() const { return gamesWon; }
    
    void reset();
    
    void render(DisplayManager& display);
    
    // TODO: Add player statistics tracking
    // TODO: Add achievement system
};

#endif // HANGMAN_PLAYER_H

