#include "game/Game.h"
#include "config/ConfigManager.h"
#include "utils/Logger.h"
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    Logger::initialize();
    
    ConfigManager config;
    if (!config.load("config/game.cfg")) {
        std::cerr << "Warning: Could not load config file, using defaults\n";
    }
    
    Game game(config);
    
    if (argc > 1) {
        // TODO: Implement command line argument parsing
        // TODO: Add support for --help, --version, --config flags
    }
    
    if (!game.initialize()) {
        std::cerr << "Failed to initialize game\n";
        return EXIT_FAILURE;
    }
    
    game.run();
    game.cleanup();
    
    return EXIT_SUCCESS;
}

