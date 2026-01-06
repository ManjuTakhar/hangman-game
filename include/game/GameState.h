#ifndef HANGMAN_GAMESTATE_H
#define HANGMAN_GAMESTATE_H

#include "display/DisplayManager.h"
#include "input/InputManager.h"

class GameState {
public:
    virtual ~GameState() = default;
    
    virtual bool enter() = 0;
    virtual void exit() = 0;
    virtual void update() = 0;
    virtual void render(DisplayManager& display) = 0;
    virtual void handleInput(InputManager& input) = 0;
    
protected:
    // TODO: Add common state properties
    // TODO: Add state transition helpers
};

#endif // HANGMAN_GAMESTATE_H

