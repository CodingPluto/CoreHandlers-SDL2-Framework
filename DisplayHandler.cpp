#include "DisplayHandler.h"
#include "WindowHandler.h"
#include "ImageHandler.h"
#include "CameraHandler.h"
#include "../gameData/Game.h"
#include <SDL2/SDL.h>
#include <iostream>
using namespace std;
#define DEFAULT_RED 231
#define DEFAULT_GREEN 200
#define DEFAULT_BLUE 241
#define DEFAULT_ALPHA 255

DisplayHandler::DisplayHandler(WindowHandler *windowHandler, CameraHandler *cameraHandler):Handler(hp_OnRender),windowHandler(windowHandler),cameraHandler(cameraHandler)
{
    debugName = "Display Handler";
}



bool DisplayHandler::initalize()
{
    windowHandler->linkToRenderer(this);
    if (window == nullptr)
    {
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr)
    {
        return false;
    }
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    return true;
}

void DisplayHandler::setWindowTarget(SDL_Window* window)
{
    this->window = window;
}


HandlerError* DisplayHandler::tick()
{
    setDrawColour({DEFAULT_RED,DEFAULT_GREEN,DEFAULT_BLUE,DEFAULT_ALPHA});
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
    return nullptr;
}


void DisplayHandler::drawRect(SDL_Rect *rect, ColourRGBA rgba, bool relative, bool filled)
{
    if (relative)
    {
        rect->x -= cameraHandler->getCameraOffset().x;
        rect->y -= cameraHandler->getCameraOffset().y;
    }
    setDrawColour(rgba);
    SDL_RenderDrawRect(renderer,rect);
    if (filled)
    {
        SDL_RenderFillRect(renderer,rect);
    }
}



void DisplayHandler::setDrawColour(ColourRGBA rgba)
{
    SDL_SetRenderDrawColor(renderer,rgba.r,rgba.g,rgba.b,rgba.a);
}