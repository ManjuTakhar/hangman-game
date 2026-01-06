# Hangman Game

A classic Hangman game implementation in C++ with a modular architecture.

## Interface

The game is designed as a **graphical user interface (GUI)** application with a window-based display. The architecture supports window rendering, keyboard input, and graphical elements. Currently, the graphics implementation is in progress - the game framework is set up for GUI rendering with configurable window dimensions (default: 800x600) as specified in `config/game.cfg`.

## Features

- Single player and multiplayer modes
- Multiple difficulty levels
- Word list management
- Statistics tracking
- Save/Load functionality
- Hint system
- Configurable settings

## Game Rules

### How to Play

1. **Objective**: Guess the hidden word by suggesting letters one at a time
2. **Guessing**: Players input a single letter (case-insensitive)
3. **Correct Guess**: If the letter exists in the word, all occurrences are revealed
4. **Incorrect Guess**: The letter is added to the incorrect guesses list and you lose one life
5. **Winning**: Complete the word by guessing all letters before running out of lives
6. **Losing**: Game ends when you run out of lives (default: 6 lives)

### Word Validation Rules

Words used in the game must meet the following criteria:
- **Minimum Length**: 2 characters
- **Maximum Length**: 20 characters (to ensure reasonable gameplay)
- **Allowed Characters**: 
  - Letters (a-z, A-Z) - case insensitive
  - Spaces (for multi-word phrases)
  - Hyphens (for compound words)
- **Invalid Characters**: Numbers, special characters (except space and hyphen), and empty strings are rejected
- **Input Sanitization**: All user input is automatically converted to lowercase

### Difficulty Levels

The game supports four difficulty levels, each affecting the number of lives available:

- **EASY**: 10 lives
- **MEDIUM**: 6 lives (default)
- **HARD**: 4 lives
- **EXPERT**: 3 lives

Difficulty can be configured in `config/game.cfg` or changed during gameplay.

### Hint System

- Players can request hints to help guess the word
- Maximum number of hints per game: 3 (configurable)
- Hints can be disabled in settings
- Each hint reveals progressively more information about the word

### Save/Load Functionality

Game state can be saved and loaded. Saved games include:
- Player name
- Current word (partially revealed)
- Guessed letters (correct and incorrect)
- Remaining lives/attempts
- Current difficulty level
- Game statistics

Save files are stored in JSON format in the `data/` directory.

### Game Modes

- **Single Player**: Play against the computer with words from the word list
- **Multiplayer**: One player enters a word, another player guesses it

## Building

```bash
make
```

## Running

```bash
make run
```

## Project Structure

- `src/` - Source files
- `include/` - Header files
- `data/` - Game data files (word lists, save files)
- `config/` - Configuration files (game settings)

## Configuration

Game settings can be modified in `config/game.cfg`:
- `window_width`: Display window width (default: 800)
- `window_height`: Display window height (default: 600)
- `fullscreen`: Enable fullscreen mode (default: false)
- `sound_enabled`: Enable sound effects (default: true)
- `music_enabled`: Enable background music (default: true)
- `difficulty`: Default difficulty level (easy/medium/hard/expert)
- `max_lives`: Maximum lives for current difficulty (default: 6)

## Requirements

- C++17 compatible compiler
- Make
