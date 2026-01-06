#include "stats/Statistics.h"
#include "utils/Logger.h"
#include <fstream>
#include <algorithm>

Statistics::Statistics() {
    reset();
}

void Statistics::recordGame(bool won, int score) {
    stats.totalGames++;
    
    if (won) {
        stats.gamesWon++;
    } else {
        stats.gamesLost++;
    }
    
    stats.totalScore += score;
    stats.highScore = std::max(stats.highScore, score);
    
    // TODO: Calculate average score
    if (stats.totalGames > 0) {
        stats.averageScore = static_cast<double>(stats.totalScore) / stats.totalGames;
    }
}

void Statistics::recordWord(const std::string& word, const std::string& difficulty) {
    wordDifficultyStats[difficulty]++;
    
    recentWords.push_back(word);
    if (recentWords.size() > 10) {
        recentWords.erase(recentWords.begin());
    }
    
    // TODO: Update longest word guessed
    stats.longestWordGuessed = std::max(stats.longestWordGuessed, 
                                        static_cast<int>(word.length()));
}

bool Statistics::load(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        Logger::log(LogLevel::WARNING, "Statistics file not found: " + filename);
        return false;
    }
    
    // TODO: Parse statistics from file
    // TODO: Load all stat fields
    
    file.close();
    return true;
}

bool Statistics::save(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        Logger::log(LogLevel::ERROR, "Failed to save statistics: " + filename);
        return false;
    }
    
    // TODO: Write statistics to file
    // TODO: Format data properly
    
    file.close();
    return true;
}

void Statistics::reset() {
    stats = {};
    wordDifficultyStats.clear();
    recentWords.clear();
}

