#include "UserAuthHandler.h"
#include "URL2ID.h"

UserAuthHandler::UserAuthHandler()
{
}


UserAuthHandler::~UserAuthHandler()
{
}

void UserAuthHandler::LoginByToken(RequestPtr request)
{
    const Json::Value& params = request->environment().jsons;

    //入口参数检查
    if (!(params.isObject()
        && params["uid"].isUInt()
        && params["token"].isString()
        && params["ver"].isString()))
    {
        return ResponseError(request, ERR_NO_PARAMETER);
    }

    auto uid = params["uid"].asUInt();
    auto token = params["token"].asString();
    auto ver = params["ver"].asString();

    //构造value
    Json::Value retJson;
    retJson["name"] = "你的名字";
    retJson["age"] = (Json::UInt)13;
    retJson["-age"] = -13;
    retJson["bool"] = false;
    retJson["null"] = Json::nullValue;
    retJson["pi"] = 3.1415;
    retJson["a"].append(1);
    retJson["a"].append(2);
    retJson["a"].append(3);
    retJson["a"].append(4);
    //retJson["a"].append(1).append(2).append(3).append(4);//invalid

    ResponseJson(request, retJson);
}

void UserAuthHandler::HandleUserAuth(RequestPtr request, int id)
{
    //验证

    //id处理
    switch (request->environment().requestMethod)
    {
    case RequestMethod::POST:
        switch (id)
        {
        case URL_ID::LoginByToken:
            LoginByToken(request);
            break;
        default:
            ResponseError(request, ERR_NO_API);
            break;
        }
        break;
    case RequestMethod::GET:
    default:
        ResponseError(request, ERR_NO_API);
        break;
    }
}