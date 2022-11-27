#ifndef SRC_HANDLERS_SCENE_H
#define SRC_HANDLERS_SCENE_H
#include <string>
#include <functional>
#include <vector>
#include "../gameData/GameObject.h"

typedef std::function<void(std::vector<class GameObject*> *gameObjectsPtr)> SceneFunction;

class Scene
{
private:
    std::vector<GameObject*> gameObjects;
public:
    const std::string name;
    const SceneFunction sceneLoader;
    Scene(const std::string name, SceneFunction sceneLoader);
    void load();
    void unload();


};


#endif