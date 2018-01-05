#include "UserAuthHandler.h"
#include "URL2ID.h"

UserAuthHandler::UserAuthHandler()
{
}


UserAuthHandler::~UserAuthHandler()
{
}

void UserAuthHandler::LoginByToken()
{
    const ptree& params = environment().jsons;
    //if (params.get)
}

void UserAuthHandler::HandleUserAuth(const int id)
{
    //验证

    //id处理
    switch (environment().requestMethod)
    {
    case RequestMethod::POST:
        switch (id)
        {
        case URL_ID::LoginByToken:
            ResponseUserAuth();
            break;
        default:
            ResponseError(3);
            break;
        }
        break;
    default:
        ResponseError(3);
        break;
    }
}