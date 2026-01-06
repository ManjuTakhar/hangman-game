#include "game/Game.h"
#include "gamestate/MenuState.h"
#include "utils/Logger.h"
#include <iostream>

Game::Game(const ConfigManager& config) 
    : config(config), isRunning(false) {
    Logger::log(LogLevel::INFO, "Game instance created");
}

Game::~Game() {
    cleanup();
}

bool Game::initialize() {
    if (!displayManager.initialize()) {
        Logger::log(LogLevel::ERROR, "Failed to initialize display manager");
        return false;
    }
    
    if (!inputManager.initialize()) {
        Logger::log(LogLevel::ERROR, "Failed to initialize input manager");
        return false;
    }
    
    // TODO: Initialize audio system
    // TODO: Load game assets (fonts, images)
    
    currentState = std::make_unique<MenuState>(*this);
    if (!currentState->enter()) {
        Logger::log(LogLevel::ERROR, "Failed to enter initial game state");
        return false;
    }
    
    isRunning = true;
    Logger::log(LogLevel::INFO, "Game initialized successfully");
    return true;
}

void Game::run() {
    while (isRunning) {
        processInput();
        update();
        render();
        
        // TODO: Implement frame rate limiting
        // TODO: Add delta time calculation for smooth animations
    }
}

void Game::processInput() {
    inputManager.update();
    
    // TODO: Handle window close events
    // TODO: Process input queue properly
    
    if (currentState) {
        currentState->handleInput(inputManager);
    }
}

void Game::update() {
    if (currentState) {
        currentState->update();
    }
    
    if (currentMode) {
        currentMode->update();
    }
    
    handleGameEvents();
}

void Game::render() {
    displayManager.clear();
    
    if (currentState) {
        currentState->render(displayManager);
    }
    
    if (currentMode) {
        currentMode->render(displayManager);
    }
    
    displayManager.present();
}

void Game::handleGameEvents() {
    // TODO: Implement event system for game state transitions
    // TODO: Handle game over, win, lose events
}

void Game::changeState(std::unique_ptr<GameState> newState) {
    if (currentState) {
        currentState->exit();
    }
    
    currentState = std::move(newState);
    
    if (currentState) {
        // TODO: Add error handling for state entry
        currentState->enter();
    }
}

void Game::setGameMode(std::unique_ptr<GameMode> mode) {
    if (currentMode) {
        currentMode->cleanup();
    }
    
    currentMode = std::move(mode);
    
    if (currentMode) {
        // TODO: Initialize game mode properly
        currentMode->initialize();
    }
}

void Game::cleanup() {
    if (currentState) {
        currentState->exit();
        currentState.reset();
    }
    
    if (currentMode) {
        currentMode->cleanup();
        currentMode.reset();
    }
    
    inputManager.cleanup();
    displayManager.cleanup();
    
    isRunning = false;
    Logger::log(LogLevel::INFO, "Game cleaned up");
}

