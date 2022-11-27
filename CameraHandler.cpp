#include <cmath>
#include "CameraHandler.h"
#include "SceneHandler.h"

using namespace std;
Camera* CameraHandler::getActiveCamera()
{
    return activeCamera;
}


void CameraHandler::setActiveCamera(Camera *newCamera)
{
    if (newCamera)
    {
        activeCamera = newCamera;
    }
    else
    {
        activeCamera = &defaultCamera;
    }
}

CameraHandler::CameraHandler(): Handler(hp_OnRender)
{
    debugName = "Camera Handler";
    activeCamera = &defaultCamera;
}


HandlerError* CameraHandler::tick()
{
    if (game->sceneHandler->removingScenes())
    {
        vector<const string*> names = game->sceneHandler->getScenesUnloadingNames();
        for (auto name : names)
        {
            if (name == activeCamera->getSceneOwner() || activeCamera->getSceneOwner() == nullptr)
            {
                activeCamera = &defaultCamera;
            }
        }
    }
    cameraOffset = activeCamera->cameraUpdate();

    return nullptr;
    
}

Position2 CameraHandler::getCameraOffset()
{
    return cameraOffset;
}