#include "RequestHandler.h"
#include <boost/algorithm/string.hpp>   //split
#include "URL2ID.h"

RequestHandler::RequestHandler()
{
}


RequestHandler::~RequestHandler()
{
}

bool RequestHandler::response()
{
    //处理业务
    std::vector<std::string> path;
    boost::split(path, environment().scriptName, boost::is_any_of("/"));
    if (path.size() < 3)
    {
        ResponseError(3);
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
        ResponseError(3);
        break;
    }
    return true;
}