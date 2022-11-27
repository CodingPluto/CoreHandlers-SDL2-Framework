#ifndef SRC_HANDLER_H
#define SRC_HANDLER_H
#include "HandlerError.h"
enum hp__HandlerTickPoint
{
    hp_OnInput = 0,
    hp_OnUpdate = 1,
    hp_OnRender = 2,
    hp_NoTick = 3
};

class Handler
{
private:
public:
    std::string getDebugName();
    static void linkHandlersToGame(class Game *game);
    virtual ~Handler();
    virtual HandlerError* tick();
    virtual bool initalize();
    static class Game *game;
protected:
    std::string debugName;
    Handler(hp__HandlerTickPoint handlerTickPoint);
};


#endif