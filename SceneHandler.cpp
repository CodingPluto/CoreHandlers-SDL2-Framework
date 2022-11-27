#include <iostream>
#include "CameraHandler.h"
#include "SceneHandler.h"
#include "GameObjectHandler.h"
#include "../gameData/GameObject.h"
#include "../allScenes.h"


using namespace std;
SceneHandler::SceneHandler():Handler(hp_OnInput)
{
    debugName = "Scene Handler";
    addSceneConfiguration("awake1",awake1);
    addSceneConfiguration("player",player);
    addSceneConfiguration("developer",developer);
    addSceneConfiguration("awake2",awake2);
    addSceneConfiguration("testArea", testArea);
}
void SceneHandler::addSceneConfiguration(const string sceneName, SceneFunction sceneLoader)
{

    for (int i = 0; i < scenes.size(); ++i)
    {
        if (scenes[i].name == sceneName)
        {
            cout << "Duplicate scene name attempted to be loaded. Failed." << endl;
            return;
        }
    }
    Scene scene(sceneName, sceneLoader);
    scenes.emplace_back(scene);
}

void SceneHandler::loadScene(std::string sceneName)
{
    for (Scene *scene : scenesLoaded)
    {
        if (scene->name == sceneName)
        {
            throw runtime_error("Scene \'" + sceneName + "\' was loaded twice!!");
        }
    }
    bool checkScenesPendingLoad = true;
    for (Scene *scene : scenesPendingLoad)
        {
            if (scene->name == sceneName)
            {
                throw runtime_error("Scene \'" + sceneName + "\' was loaded twice!!");
            }
        }
    for (Scene &scene : scenes)
    {
        if (scene.name == sceneName)
        {
            scenesPendingLoad.emplace_back(&scene);
            return;
        }
    }
    throw runtime_error("Tried to load scene \'" + sceneName + "\' that doesn't exist!");
}
void SceneHandler::unloadScene(std::string sceneName)
{
    for (int i = 0; i < scenesLoaded.size(); ++i)
    {
        if (scenesLoaded[i]->name == sceneName)
        {
            cout << "Added to scenes pending unload" << endl;
            scenesPendingUnload.emplace_back(scenesLoaded[i]);
            return;
        }
    }
    for (int i = 0; i < scenesPendingLoad.size(); ++i)
    {
        if (scenesPendingLoad[i]->name == sceneName)
        {
            scenesPendingLoad.erase(scenesPendingLoad.begin() + i);
            return;
        }
    }
    throw runtime_error("Tried to unload scene \'" + sceneName + "\' that isn't loaded or doesn't exist!");
}

const bool SceneHandler::removingScenes()
{
    return scenesPendingUnload.size() > 0;
}

SceneHandler::~SceneHandler()
{
    for (int i = 0; i < scenesLoaded.size(); ++i)
    {
        cout << "Unloading Scene: " << scenesLoaded[i]->name << endl;
        scenesLoaded[i]->unload();
    }
    scenesLoaded.clear();
}


HandlerError* SceneHandler::tick()
{
    for (auto scenePendingLoad : scenesPendingLoad)
    {
        scenePendingLoad->load();
        scenesLoaded.emplace_back(scenePendingLoad);
    }
    scenesPendingLoad.clear();
    for (int i = 0; i < scenesLoaded.size(); ++i)
    {
        for (auto scenePendingUnload : scenesPendingUnload)
        {
            if (scenesLoaded[i] == scenePendingUnload)
            {
                scenePendingUnload->unload();
                scenesLoaded.erase(scenesLoaded.begin() + i);
            }
        }
    }
    scenesPendingUnload.clear();
    return nullptr;
}

const vector<const string*> SceneHandler::getScenesUnloadingNames()
{
    vector<const string*> scenesUnloadingNames;
    for (auto scene : scenesPendingUnload)
    {
        scenesUnloadingNames.emplace_back(&scene->name);
    }
    return scenesUnloadingNames;
}

const vector<const string*> SceneHandler::getLoadedScenesNames()
{
    vector<const string*> sceneNames;
    for (auto scene : scenesLoaded)
    {
        sceneNames.emplace_back(&(scene->name));
    }
    for (auto scene : scenesPendingLoad)
    {
        sceneNames.emplace_back(&(scene->name));
    }
    return sceneNames;
}
