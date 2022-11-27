#ifndef SRC_HANDLER_ERROR_H
#define SRC_HANDLER_ERROR_H
#include <string>
enum et__HandlerErrorType
{
    et_SystemError = 1,
    et_GameError = 2,
    et_Warning = 3
};

class HandlerError
{
private:
    et__HandlerErrorType errorType;
    std::string errorMessage;
    class Handler *originator;
public:
    std::string returnError();
    et__HandlerErrorType getErrorType();
    HandlerError(et__HandlerErrorType errorType, std::string errorMessage, class Handler *originator);
};


#endif