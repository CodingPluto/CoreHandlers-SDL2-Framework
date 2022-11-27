#ifndef SRC_WINDOW_HANDLER_H
#define SRC_WINDOW_HANDLER_H
#include "Handler.h"

class WindowHandler : public Handler
{
private:
    unsigned short displayWidth;
    unsigned short displayHeight;
    int windowXPosition;
    int windowYPosition;
    const char *title;
    class SDL_Window *window;
protected:
public:
    float getCentreScreenX(float width);
    float getCentreScreenY(float height);
    void linkToRenderer(class DisplayHandler *displayHandler);
    bool initalize();
    unsigned short getScreenWidth();
    unsigned short getScreenHeight();
    int getWindowXPosition();
    int getWindowYPosition();
    void setWindowPosition(int x, int y);
    HandlerError* tick();
    WindowHandler(const char title[], int xPos, int yPos, unsigned short width, unsigned short height);
};



#endif