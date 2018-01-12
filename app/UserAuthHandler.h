#pragma once
#include "BaseHandler.h"

class UserAuthHandler : public virtual BaseHandler
{
public:
    UserAuthHandler();
    virtual ~UserAuthHandler();

protected:
    void HandleUserAuth(int id);

private:
    void LoginByToken();
};

