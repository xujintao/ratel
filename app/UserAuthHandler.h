#pragma once
#include "BaseHandler.h"

class UserAuthHandler : public virtual BaseHandler
{
public:
    UserAuthHandler();
    virtual ~UserAuthHandler();

protected:
    void HandleUserAuth(RequestPtr request, int id);

private:
    void LoginByToken(RequestPtr request);
};

