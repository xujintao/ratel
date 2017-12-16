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
	//验证

	//id处理
	switch (id)
	{
	case URL_ID::LoginByToken:
		ResponseUserAuth();
		break;
	default:
		break;
	}
}