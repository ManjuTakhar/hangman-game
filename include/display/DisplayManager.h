#ifndef HANGMAN_DISPLAYMANAGER_H
#define HANGMAN_DISPLAYMANAGER_H

#include <string>

struct Color {
    int r, g, b, a;
    Color(int r = 255, int g = 255, int b = 255, int a = 255) 
        : r(r), g(g), b(b), a(a) {}
};

class DisplayManager {
private:
    int width;
    int height;
    bool isInitialized;
    
public:
    DisplayManager();
    ~DisplayManager();
    
    bool initialize();
    void cleanup();
    
    void clear();
    void present();
    
    void renderText(const std::string& text, int x, int y, const Color& color = Color());
    void renderRectangle(int x, int y, int w, int h, const Color& color);
    void renderLine(int x1, int y1, int x2, int y2, const Color& color);
    
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    
    // TODO: Add sprite/image rendering
    // TODO: Add font management
    // TODO: Add animation support
};

#endif // HANGMAN_DISPLAYMANAGER_H

