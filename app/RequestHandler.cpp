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

bool RequestHandler::Handle(_RequestPtr _request)
{
    RequestPtr request = std::dynamic_pointer_cast<Fastcgipp::Request<char>>(_request);

    //log
    LogRequest(request);

    //处理业务
    std::vector<std::string> path;
    boost::split(path, request->environment().scriptName, boost::is_any_of("/"));
    if (path.size() < 3)
    {
        ResponseError(request, ERR_NO_API);
        return true;
    }

    auto moduleId = URL2ID::FindMid(path[1]);
    auto id = URL2ID::FindId(path[2]);
    switch (moduleId)
    {
    case OpenAPI:
        HandleOpenAPI(request, id);
        break;
    case UserAuth:
        HandleUserAuth(request, id);
        break;
    default:
        ResponseError(request, ERR_NO_API);
        break;
    }
    return true;
}