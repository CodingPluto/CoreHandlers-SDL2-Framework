#include "Scene.h"
#include <iostream>
using namespace std;

Scene::Scene(const string name, const SceneFunction sceneLoader): name(name), sceneLoader(sceneLoader)
{}


void Scene::load()
{
    sceneLoader(&gameObjects);
    for (GameObject *gameObject : gameObjects)
    {
        gameObject->setSceneName(&name);
    }
}


void Scene::unload()
{
    for (const GameObject *gameObject : gameObjects)
    {
        delete gameObject;
    }
}