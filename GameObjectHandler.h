#ifndef SRC_HANDLERS_GAME_OBJECT_HANDLER_H
#define SRC_HANDLERS_GAME_OBJECT_HANDLER_H
#include "Handler.h"
#include <vector>

class GameObjectHandler : public Handler
{
private:
    HandlerError* tick() override;
    bool initalize() override;
    std::vector<class GameObject*> gameObjects;
    std::vector<class GameObject*> pendingGameObjects;
    std::vector<class GameObject*> pendingRemovalGameObjects;
    std::vector<class GameObject*> gameObjectsToBeDeleted;
public:
    void addGameObject(class GameObject *address);
    void removeGameObject(class GameObject *address);
    void deleteAtFrameEnd(GameObject *address);
    void reloadGameObjectPriorities();

    GameObjectHandler();
    ~GameObjectHandler();

};





#endif