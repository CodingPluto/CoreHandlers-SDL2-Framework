#include "Handler.h"
#include "../gameData/Game.h"
#include <iostream>
using namespace std;
Game *Handler::game = nullptr;

Handler::Handler(hp__HandlerTickPoint handlerTickPoint)
{
    if (game == nullptr)
    {
        throw runtime_error("Handlers haven't been linked to the game instance.");
    }
    game->addHandler(this,handlerTickPoint);
}

Handler::~Handler()
{}

HandlerError* Handler::tick()
{
    return nullptr;
}

bool Handler::initalize()
{
    return true;
}
void Handler::linkHandlersToGame(Game *game)
{
    Handler::game = game;
}

std::string Handler::getDebugName()
{
    return debugName;
}