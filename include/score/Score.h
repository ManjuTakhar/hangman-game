#ifndef HANGMAN_SCORE_H
#define HANGMAN_SCORE_H

#include <string>

class Score {
private:
    int currentScore;
    int highScore;
    
public:
    Score();
    ~Score() = default;
    
    void addPoints(int points);
    void subtractPoints(int points);
    void reset();
    
    int getCurrentScore() const { return currentScore; }
    int getHighScore() const { return highScore; }
    
    void setHighScore(int score);
    bool isNewHighScore() const;
    
    std::string toString() const;
    
    // TODO: Add score multiplier system
    // TODO: Add combo scoring
};

#endif // HANGMAN_SCORE_H

