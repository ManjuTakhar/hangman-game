#ifndef HANGMAN_SETTINGSSTATE_H
#define HANGMAN_SETTINGSSTATE_H

#include "game/GameState.h"
#include "game/Game.h"
#include "display/DisplayManager.h"
#include "input/InputManager.h"

class SettingsState : public GameState {
private:
    Game& game;
    int selectedSetting;
    
public:
    SettingsState(Game& game);
    ~SettingsState() override = default;
    
    bool enter() override;
    void exit() override;
    void update() override;
    void render(DisplayManager& display) override;
    void handleInput(InputManager& input) override;
};

#endif // HANGMAN_SETTINGSSTATE_H

