#ifndef HANGMAN_MULTIPLAYERMODE_H
#define HANGMAN_MULTIPLAYERMODE_H

#include "gamemode/GameMode.h"
#include "player/Player.h"
#include <vector>
#include <memory>

class MultiPlayerMode : public GameMode {
private:
    std::vector<std::unique_ptr<Player>> players;
    int currentPlayerIndex;
    
    void switchPlayer();
    void handlePlayerTurn();
    
public:
    MultiPlayerMode();
    ~MultiPlayerMode() override = default;
    
    bool initialize() override;
    void cleanup() override;
    void update() override;
    void render(DisplayManager& display) override;
    void handleInput(InputManager& input) override;
};

#endif // HANGMAN_MULTIPLAYERMODE_H

