#include <iostream>
#include "EventsHandler.h"
#include "EventCallback.h"
#include "../gameData/Game.h"
using namespace std;


void EventsHandler::exitCallBack()
{
    game->exitGame();
};


EventsHandler::EventsHandler():Handler(hp_OnInput)
{
    debugName = "Events Handler";
    eventCallbacks.emplace_back(new EventCallback(SDL_QUIT,exitCallBack));
}
EventsHandler::~EventsHandler()
{
    for (auto eventCallback : eventCallbacks)
    {
        delete eventCallback;
    }
}


bool EventsHandler::initalize()
{
    return true;
}

HandlerError* EventsHandler::tick()
{
    while (SDL_PollEvent(&event))
    {
        for (EventCallback *eventCallback : eventCallbacks)
        {
            if (eventCallback->eventType == event.type)
            {
                eventCallback->onExecute();
            }
        }
    }

    return nullptr;
}


void EventsHandler::addEventCallback(Uint32 trigger, function<void()> &callBackFunction)
{
    eventCallbacks.emplace_back(new EventCallback(trigger,callBackFunction));
}