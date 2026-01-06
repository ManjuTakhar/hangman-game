#ifndef HANGMAN_MENUSTATE_H
#define HANGMAN_MENUSTATE_H

#include "game/GameState.h"
#include "game/Game.h"
#include "input/InputManager.h"
#include <vector>
#include <string>

class MenuState : public GameState {
private:
    Game& game;
    int selectedOption;
    std::vector<std::string> menuOptions;
    
    void handleMenuSelection();
    void renderMenu(DisplayManager& display);
    
public:
    MenuState(Game& game);
    ~MenuState() override = default;
    
    bool enter() override;
    void exit() override;
    void update() override;
    void render(DisplayManager& display) override;
    void handleInput(InputManager& input) override;
};

#endif // HANGMAN_MENUSTATE_H

