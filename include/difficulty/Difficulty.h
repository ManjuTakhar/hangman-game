#ifndef HANGMAN_DIFFICULTY_H
#define HANGMAN_DIFFICULTY_H

// Difficulty levels with corresponding lives:
// EASY: 10 lives
// MEDIUM: 6 lives (default)
// HARD: 4 lives
// EXPERT: 3 lives
// See README.md for detailed difficulty level specifications
enum class Difficulty {
    EASY,      // 10 lives
    MEDIUM,    // 6 lives (default)
    HARD,      // 4 lives
    EXPERT     // 3 lives
};

// TODO: Add difficulty settings (lives, time limits, etc.)
// TODO: Add difficulty string conversion utilities

#endif // HANGMAN_DIFFICULTY_H

