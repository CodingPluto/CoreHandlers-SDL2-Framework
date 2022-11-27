#ifndef SRC_CAMERA_HANDLER_H
#define SRC_CAMERA_HANDLER_H
#include "Handler.h"
#include "../cameras/Camera.h"
#include "../utils/Position.h"
class CameraHandler : public Handler
{
private:
    
    Camera* activeCamera;
    Camera defaultCamera;
    Position2 cameraOffset;
public:
    CameraHandler();
    Camera* getActiveCamera();
    void setActiveCamera(Camera *newCamera);
    Position2 getCameraOffset();
    HandlerError* tick();
    
};


#endif