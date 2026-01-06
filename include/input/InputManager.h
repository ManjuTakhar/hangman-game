#ifndef HANGMAN_INPUTMANAGER_H
#define HANGMAN_INPUTMANAGER_H

enum class KeyCode {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    ENTER,
    ESCAPE,
    SPACE,
    BACKSPACE,
    UNKNOWN
};

class InputManager {
private:
    bool keys[256];
    bool keysPressed[256];
    char lastCharInput;
    bool isInitialized;
    
    KeyCode charToKeyCode(char c) const;
    
public:
    InputManager();
    ~InputManager();
    
    bool initialize();
    void cleanup();
    void update();
    
    bool isKeyDown(KeyCode key) const;
    bool isKeyPressed(KeyCode key) const;
    char getLastCharInput() const { return lastCharInput; }
    
    // TODO: Add mouse input support
    // TODO: Add gamepad support
    // TODO: Add input event queue
};

#endif // HANGMAN_INPUTMANAGER_H

