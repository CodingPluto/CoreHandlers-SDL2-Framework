#ifndef SRC_HANDLERS_INPUT_HANDLER_H
#define SRC_HANDLERS_INPUT_HANDLER_H
#include "Handler.h"
#include <SDL2/SDL.h>
class InputHandler : Handler
{
private:
    HandlerError *tick();
    bool initalize();
    const bool *keysPressed;
    bool keysPressedLastFrame[SDL_NUM_SCANCODES];
    bool keysJustPressed[SDL_NUM_SCANCODES];
    std::pair<int,int> mousePosition;
    Uint32 mouseButtonsPressed;
    bool leftClickThisFrame;
    bool leftClickLastFrame;
    bool rightClickThisFrame;
    bool rightClickLastFrame;

public:
    const bool keyPressed(SDL_Scancode keyID);
    const bool keyJustPressed(SDL_Scancode keyID);
    const bool isLMBPress();
    const bool isRMBPress();
    const bool isLMBOneClick();
    const bool isRMBOneClick();
    const unsigned int getMouseX();
    const unsigned int getMouseY();
    static const SDL_Scancode numberScancodes[10];
    InputHandler();
    ~InputHandler();
};


#endif