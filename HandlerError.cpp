#include <sstream>
#include <iostream>
#include "HandlerError.h"
#include "Handler.h"
using namespace std;

HandlerError::HandlerError(et__HandlerErrorType errorType, string errorMessage, Handler *originator):errorType(errorType),errorMessage(errorMessage), originator(originator)
{}

std::string HandlerError::returnError()
{
    auto getPrintableErrorType = [this]()
    {
        switch(errorType)
        {
            case et_Warning:
                return "Warning";
                break;
            case et_GameError:
                return "Game Error";
                break;
            case et_SystemError:
                return "System Error";
                break;
            default:
                return "HandlerError Error";
        }
    };
    std::string fullErrorMessage;
    fullErrorMessage = getPrintableErrorType();
    fullErrorMessage += " | ";
    fullErrorMessage += errorMessage;
    fullErrorMessage += " | ";
    fullErrorMessage += "Orignating from ";
    ostringstream address;
    address << (void const *)originator;
    fullErrorMessage += address.str();
    fullErrorMessage += "(";
    fullErrorMessage += originator->getDebugName();
    fullErrorMessage += ")";
    fullErrorMessage += "(";
    fullErrorMessage += typeid(originator).name();
    fullErrorMessage += ")";
    fullErrorMessage += " |";
    return fullErrorMessage;
}

et__HandlerErrorType HandlerError::getErrorType()
{
    return errorType;
}