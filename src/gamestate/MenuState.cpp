#include "gamestate/MenuState.h"
#include "gamestate/PlayState.h"
#include "gamestate/SettingsState.h"
#include "utils/Logger.h"

MenuState::MenuState(Game& game) 
    : game(game), selectedOption(0) {
    menuOptions = {"Play", "Settings", "Statistics", "Exit"};
}

bool MenuState::enter() {
    selectedOption = 0;
    Logger::log(LogLevel::INFO, "Entered menu state");
    return true;
}

void MenuState::exit() {
    Logger::log(LogLevel::INFO, "Exited menu state");
}

void MenuState::update() {
    // TODO: Add menu animation updates
    // TODO: Handle menu transitions
}

void MenuState::render(DisplayManager& display) {
    renderMenu(display);
}

void MenuState::renderMenu(DisplayManager& display) {
    // TODO: Implement proper menu rendering with highlighting
    // TODO: Add background graphics
    // TODO: Add menu title display
    
    for (size_t i = 0; i < menuOptions.size(); ++i) {
        if (i == selectedOption) {
            // TODO: Highlight selected option
        }
        // TODO: Render menu option text
    }
}

void MenuState::handleInput(InputManager& input) {
    if (input.isKeyPressed(KeyCode::UP)) {
        selectedOption = (selectedOption - 1 + menuOptions.size()) % menuOptions.size();
    }
    
    if (input.isKeyPressed(KeyCode::DOWN)) {
        selectedOption = (selectedOption + 1) % menuOptions.size();
    }
    
    if (input.isKeyPressed(KeyCode::ENTER)) {
        handleMenuSelection();
    }
    
    // TODO: Handle mouse input for menu selection
    // TODO: Add keyboard shortcuts
}

void MenuState::handleMenuSelection() {
    switch (selectedOption) {
        case 0: // Play
            game.changeState(std::make_unique<PlayState>(game));
            break;
        case 1: // Settings
            game.changeState(std::make_unique<SettingsState>(game));
            break;
        case 2: // Statistics
            // TODO: Implement statistics state
            break;
        case 3: // Exit
            // TODO: Implement proper exit handling
            break;
        default:
            break;
    }
}

