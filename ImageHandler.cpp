#include <iostream>
#include <SDL2/SDL_image.h>
#include "ImageHandler.h"
#include "DisplayHandler.h"
#include "../components/ImageComponent.h"
#include "CameraHandler.h"
#include "WindowHandler.h"

using namespace std;


ImageHandler::ImageHandler(WindowHandler *windowHandler, CameraHandler *cameraHandler, string workspacePath):DisplayHandler(windowHandler,cameraHandler), workspacePath(workspacePath)
{
    debugName = "Image Handler";
}

bool ImageHandler::initalize()
{
    if (!DisplayHandler::initalize())
    {
        return false;
    }
    IMG_Init(IMG_INIT_PNG);
    return true;
}

void ImageHandler::loadImage(string imagePath)
{

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer,IMG_Load((workspacePath + imagePath).c_str()));
    if (texture)
    {
        textureBank[imagePath] = texture;
    }
    else
    {
        throw out_of_range("Image file at the path: " + string(imagePath) + " was not found!");
    }
}


SDL_Texture* ImageHandler::getImageTexture(string imageName)
{
    return textureBank.at(imageName);
}

void ImageHandler::drawImage(SDL_Rect *rect, string imageName, bool relative)
{
    if (relative)
    {
        rect->x -= cameraHandler->getCameraOffset().x;
        rect->y -= cameraHandler->getCameraOffset().y;
    }
    bool insideScreen =
    (rect->x < windowHandler->getScreenWidth())
    && (rect->x + rect->w > 0)
    && (rect->y < windowHandler->getScreenHeight())
    && (rect->y + rect->h > 0);
    SDL_RenderCopyEx(renderer,textureBank[imageName],nullptr,rect,0,nullptr,SDL_FLIP_NONE);
}
void ImageHandler::drawImage(SDL_Rect *rect, string imageName, bool relative, SDL_RendererFlip flipTags)
{
    if (relative)
    {
        rect->x -= cameraHandler->getCameraOffset().x;
        rect->y -= cameraHandler->getCameraOffset().y;
    }
    bool insideScreen =
    (rect->x < windowHandler->getScreenWidth())
    && (rect->x + rect->w > 0)
    && (rect->y < windowHandler->getScreenHeight())
    && (rect->y + rect->h > 0);
    SDL_RenderCopyEx(renderer,textureBank[imageName],nullptr,rect,0,nullptr,flipTags);
}

void ImageHandler::drawImage(int x, int y, int width, int height, string imageName, bool relative)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
    if (relative)
    {
        rect.x -= cameraHandler->getCameraOffset().x;
        rect.y -= cameraHandler->getCameraOffset().y;
    }
    bool insideScreen =
    (rect.x < game->windowHandler->getScreenWidth())
    && (rect.x + rect.w > 0)
    && (rect.y < game->windowHandler->getScreenHeight())
    && (rect.y + rect.h > 0);
    SDL_RenderCopyEx(renderer,textureBank[imageName],nullptr,&rect,0,nullptr,SDL_FLIP_NONE);
}

HandlerError *ImageHandler::tick()
{
    DisplayHandler::tick();
    for (auto imageDrawer : imageDrawers)
    {
        imageDrawer->draw();
    }
    return nullptr;
}


void ImageHandler::addImageDrawer(ImageComponent *address)
{
    imageDrawers.emplace_back(address);
}

void ImageHandler::removeImageDrawer(ImageComponent *address)
{
    for (auto it = imageDrawers.begin(); it != imageDrawers.end(); ++it)
    {
        if (*it == address)
        {
            imageDrawers.erase(it);
            break;
        }
    }
}

void ImageHandler::reloadImageDrawerProrities()
{
    int previousUpdateOrder = numeric_limits<int>::max();
    int updateOrder;
    for (vector<ImageComponent*>::size_type i = 0; i < imageDrawers.size(); ++i)
    {
        updateOrder = imageDrawers[i]->getDrawOrder();
        if (i > 0)
        {
            previousUpdateOrder = imageDrawers[i - 1]->getDrawOrder();
        }
        else
        {
            previousUpdateOrder = numeric_limits<int>::max();
        }
        while (updateOrder > previousUpdateOrder)
        {
            ImageComponent *movingObject = imageDrawers[i];
            i --;
            ImageComponent *displacedObject = imageDrawers[i];
            imageDrawers[i] = movingObject;
            imageDrawers[i + 1] = displacedObject;
            if (i > 0)
            {
                previousUpdateOrder = imageDrawers[i - 1]->getDrawOrder();
            }
            else
            {
                previousUpdateOrder = numeric_limits<int>::max();
            }
            updateOrder = imageDrawers[i]->getDrawOrder();
        }
    }
}