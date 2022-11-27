#include <SDL2/SDL.h>
#include "WindowHandler.h"
#include "DisplayHandler.h"
#include <iostream>
using namespace std;

bool WindowHandler::initalize()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(title,windowXPosition,windowYPosition,displayWidth,displayHeight,0);
    if (window == nullptr)
    {
        return false;
    }
    return true;
}

float WindowHandler::getCentreScreenX(float width)
{
    return (getScreenWidth() / 2) - (width / 2);
}
float WindowHandler::getCentreScreenY(float height)
{
    return (getScreenHeight() / 2) - (height / 2);
}

unsigned short WindowHandler::getScreenWidth()
{
    return SDL_GetWindowSurface(window)->w;
}
unsigned short WindowHandler::getScreenHeight()
{
    return SDL_GetWindowSurface(window)->h;
}
int WindowHandler::getWindowXPosition()
{
    SDL_GetWindowPosition(window,&windowXPosition,&windowYPosition);
    return windowXPosition;
}
int WindowHandler::getWindowYPosition()
{
    SDL_GetWindowPosition(window,&windowXPosition,&windowYPosition);
    return windowYPosition;
}
void WindowHandler::setWindowPosition(int x, int y)
{
    SDL_SetWindowPosition(window,x,y);
}

WindowHandler::WindowHandler(const char title[], int xPos, int yPos, unsigned short width, unsigned short height):Handler(hp_OnRender),displayWidth(width),displayHeight(height),windowXPosition(xPos),windowYPosition(yPos),title(title)
{
    debugName = "Window Handler";
}

HandlerError* WindowHandler::tick()
{
    return nullptr;
}

void WindowHandler::linkToRenderer(DisplayHandler *displayHandler)
{
    if (window == nullptr)
    {
        throw "Window handler has not been initalized.";
    }
    displayHandler->setWindowTarget(window);
}