#pragma once

#include "fastcgi++/request.hpp"
#include "fastcgi++/manager.hpp"
#include <iomanip>
#include <sstream>
#include "typeDef.h"
#include "json/json.h"  //Json

using namespace Fastcgipp::Http;        //export RequestMethod::POST

class BaseHandler : public Fastcgipp::Request<char>
{
public:
    BaseHandler() : Fastcgipp::Request<char>(5 * 1024){}
    virtual ~BaseHandler(){}

    std::string Cookie2String();
    void LogRequest();
    int Response(const char* contentType, const char* content, int errcode);
    void ResponseJson(Json::Value& retJson);
    void ResponseError(int errcode, std::string paramMsg="");
};
