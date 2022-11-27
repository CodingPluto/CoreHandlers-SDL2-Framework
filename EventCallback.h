#ifndef SRC_EVENT_CALLBACK_H
#define SRC_EVENT_CALLBACK_H
#include <SDL2/SDL_stdinc.h>
#include <functional>
class EventCallback
{
public:
    const Uint32 eventType;
    std::function<void()> onExecute;
    EventCallback(Uint32 eventType, std::function<void()> onExecute);
protected:
};


#endif