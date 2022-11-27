#ifndef SRC_HANDLERS_SCENE_HANDLER_H
#define SRC_HANDLERS_SCENE_HANDLER_H
#include <vector>
#include "Handler.h"
#include "Scene.h"
class SceneHandler : public Handler
{
private:
    void addSceneConfiguration(std::string sceneName, SceneFunction sceneLoader);
    HandlerError* tick();
    std::vector<Scene> scenes;
    std::vector<Scene*> scenesLoaded;
    std::vector<Scene*> scenesPendingLoad;
    std::vector<Scene*> scenesPendingUnload;
public:
    void loadScene(std::string sceneName);
    void unloadScene(std::string sceneName);
    const bool removingScenes();
    const std::vector<const std::string*> getScenesUnloadingNames();
    const std::vector<const std::string*> getLoadedScenesNames();
    SceneHandler();
    ~SceneHandler();
};



#endif