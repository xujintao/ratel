#include "RequestHandler.h"
#include <boost/algorithm/string.hpp>   //split
#include "URL2ID.h"
#include "typeDef.h"

RequestHandler::RequestHandler()
{
}


RequestHandler::~RequestHandler()
{
}

bool RequestHandler::response()
{
    //log
    LogRequest();

    //处理业务
    std::vector<std::string> path;
    boost::split(path, environment().scriptName, boost::is_any_of("/"));
    if (path.size() < 3)
    {
        ResponseError(ERR_NO_API);
        return false;
    }

    auto moduleId = URL2ID::FindMid(path[1]);
    auto id = URL2ID::FindId(path[2]);
    switch (moduleId)
    {
    case OpenAPI:
        HandleOpenAPI(id);
        break;
    case UserAuth:
        HandleUserAuth(id);
        break;
    default:
        ResponseError(ERR_NO_API);
        break;
    }
    return true;
}