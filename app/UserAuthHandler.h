#pragma once
#include "BaseHandler.h"

class UserAuthHandler : public virtual BaseHandler
{
public:
	UserAuthHandler();
	virtual ~UserAuthHandler();

protected:
	void HandleUserAuth(const int id);
};
