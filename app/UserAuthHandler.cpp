#include "UserAuthHandler.h"
#include "URL2ID.h"

UserAuthHandler::UserAuthHandler()
{
}


UserAuthHandler::~UserAuthHandler()
{
}

void UserAuthHandler::HandleUserAuth(const int id)
{
	//��֤

	//id����
	switch (id)
	{
	case URL_ID::LoginByToken:
		ResponseUserAuth();
		break;
	default:
		break;
	}
}