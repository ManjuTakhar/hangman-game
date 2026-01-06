#ifndef HANGMAN_PLAYSTATE_H
#define HANGMAN_PLAYSTATE_H

#include "game/GameState.h"
#include "game/Game.h"
#include "gamemode/GameMode.h"
#include "display/DisplayManager.h"
#include "input/InputManager.h"
#include <memory>

class PlayState : public GameState {
private:
    Game& game;
    std::unique_ptr<GameMode> gameMode;
    
public:
    PlayState(Game& game);
    ~PlayState() override = default;
    
    bool enter() override;
    void exit() override;
    void update() override;
    void render(DisplayManager& display) override;
    void handleInput(InputManager& input) override;
};

#endif // HANGMAN_PLAYSTATE_H

