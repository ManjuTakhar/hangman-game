#ifndef HANGMAN_STATISTICS_H
#define HANGMAN_STATISTICS_H

#include <string>
#include <map>
#include <vector>

struct GameStats {
    int totalGames;
    int gamesWon;
    int gamesLost;
    int totalScore;
    int highScore;
    double averageScore;
    int longestWordGuessed;
    // TODO: Add more statistics
};

class Statistics {
private:
    GameStats stats;
    std::map<std::string, int> wordDifficultyStats;
    std::vector<std::string> recentWords;
    
public:
    Statistics();
    ~Statistics() = default;
    
    void recordGame(bool won, int score);
    void recordWord(const std::string& word, const std::string& difficulty);
    
    GameStats getStats() const { return stats; }
    
    bool load(const std::string& filename);
    bool save(const std::string& filename) const;
    
    void reset();
    
    // TODO: Add statistics visualization
    // TODO: Add achievement tracking
};

#endif // HANGMAN_STATISTICS_H

