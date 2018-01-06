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
    if (0 == params.get("uid", 0)
        || "" == params.get("token", "")
        || "" == params.get("ver", ""))
    {
        return ResponseError(ERR_NO_PARAMETER);
    }

    auto uid = params.get("uid", 0);
    auto token = params.get("token", "");
    auto ver = params.get("ver", "");

    ptree retJson;
    retJson.get("uid", 123);
    retJson.get("token", "123");
    retJson.get("ver", "1.2.3");
    ResponseJson(retJson);
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
            LoginByToken();
            break;
        default:
            ResponseError(ERR_NO_API);
            break;
        }
        break;
    case RequestMethod::GET:
    default:
        ResponseError(ERR_NO_API);
        break;
    }
}