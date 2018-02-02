#pragma once

#include "fastcgi++/request.hpp"
#include "fastcgi++/manager.hpp"
#include <iomanip>
#include <sstream>
#include "typeDef.h"
#include "json/json.h"  //Json
#include "DataBase.h"

using namespace Fastcgipp::Http;        //export RequestMethod::POST
typedef std::shared_ptr<Fastcgipp::Request<char>> RequestPtr;
typedef std::shared_ptr<Fastcgipp::Request_base> _RequestPtr;

class BaseHandler : public Fastcgipp::RequestHandler_base
{
public:
    BaseHandler();
    virtual ~BaseHandler();

    std::string Cookie2String(RequestPtr request);
    void LogRequest(RequestPtr request);
    int Response(RequestPtr request, const char* contentType, const char* content, int errcode);
    void ResponseJson(RequestPtr request, Json::Value& retJson);
    void ResponseError(RequestPtr request, int errcode, std::string paramMsg = "");

protected:
    std::shared_ptr<DataBase> m_db;
};
