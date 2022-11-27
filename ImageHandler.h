#ifndef SRC_IMAGE_HANDLER_H
#define SRC_IMAGE_HANDLER_H
#include <map>
#include <vector>
#include <SDL2/SDL.h>
#include "DisplayHandler.h"
class ImageHandler : public DisplayHandler
{
private:
    std::map<std::string,class SDL_Texture*> textureBank;
    bool initalize();
    std::vector<class ImageComponent*> imageDrawers;
    HandlerError *tick();
public:
    void reloadImageDrawerProrities();
    void addImageDrawer(class ImageComponent *address);
    void removeImageDrawer(class ImageComponent *address);
    const std::string workspacePath;
    ImageHandler(class WindowHandler *windowHandler, class CameraHandler *cameraHandler, std::string workspacePath);
    void loadImage(std::string imagePath);
    SDL_Texture* getImageTexture(std::string imageName);
    void drawImage(SDL_Rect *rect, std::string imageName, bool relative);
    void drawImage(SDL_Rect *rect, std::string imageName, bool relative, SDL_RendererFlip flipTags);
    void drawImage(int x, int y, int width, int height, std::string imageName, bool relative);
};









#endif