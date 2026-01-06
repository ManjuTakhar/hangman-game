#ifndef HANGMAN_GAME_H
#define HANGMAN_GAME_H

#include "GameState.h"
#include "gamemode/GameMode.h"
#include "display/DisplayManager.h"
#include "input/InputManager.h"
#include "config/ConfigManager.h"
#include <memory>
#include <string>

class Game {
private:
    std::unique_ptr<GameState> currentState;
    std::unique_ptr<GameMode> currentMode;
    DisplayManager displayManager;
    InputManager inputManager;
    ConfigManager config;
    bool isRunning;
    
    void processInput();
    void update();
    void render();
    void handleGameEvents();
    
public:
    Game(const ConfigManager& config);
    ~Game();
    
    bool initialize();
    void run();
    void cleanup();
    
    void changeState(std::unique_ptr<GameState> newState);
    void setGameMode(std::unique_ptr<GameMode> mode);
    
    DisplayManager& getDisplayManager() { return displayManager; }
    InputManager& getInputManager() { return inputManager; }
    ConfigManager& getConfig() { return config; }
};

#endif // HANGMAN_GAME_H

