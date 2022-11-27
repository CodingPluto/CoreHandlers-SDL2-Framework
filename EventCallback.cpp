#include <iostream>
#include "EventCallback.h"
#include "EventsHandler.h"

using namespace std;

EventCallback::EventCallback(Uint32 eventType, std::function<void()> onExecute): eventType(eventType),onExecute(onExecute)
{}