#ifndef SRC_DISPLAY_HANDLER_H
#define SRC_DISPLAY_HANDLER_H
#include "Handler.h"
#include "../utils/Colour.h"
class DisplayHandler : public Handler
{
private:
    class SDL_Window *window;
protected:
    class CameraHandler *cameraHandler;
    class WindowHandler *windowHandler;
    class SDL_Renderer *renderer;
public:
    DisplayHandler(class WindowHandler *windowHandler, class CameraHandler *cameraHandler);
    void setWindowTarget(class SDL_Window* window);
    bool initalize();
    HandlerError* tick();
    void drawRect(class SDL_Rect *rect, ColourRGBA rgba, bool relative, bool filled);
    void setDrawColour(ColourRGBA rgba);

};

#endif