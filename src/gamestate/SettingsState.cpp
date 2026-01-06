#include "gamestate/SettingsState.h"
#include "utils/Logger.h"

SettingsState::SettingsState(Game& game) : game(game), selectedSetting(0) {
}

bool SettingsState::enter() {
    selectedSetting = 0;
    Logger::log(LogLevel::INFO, "Entered settings state");
    return true;
}

void SettingsState::exit() {
    // TODO: Save settings to file
    Logger::log(LogLevel::INFO, "Exited settings state");
}

void SettingsState::update() {
    // TODO: Update settings preview
}

void SettingsState::render(DisplayManager& display) {
    // TODO: Render settings menu
    // TODO: Show current setting values
    // TODO: Highlight selected setting
}

void SettingsState::handleInput(InputManager& input) {
    if (input.isKeyPressed(KeyCode::ESCAPE)) {
        // TODO: Return to menu
    }
    
    // TODO: Handle setting adjustments
    // TODO: Navigate settings list
}

