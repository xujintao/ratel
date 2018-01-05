#pragma once

#include "fastcgi++/request.hpp"
#include "fastcgi++/manager.hpp"
#include <iomanip>
#include <sstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
using namespace boost::property_tree;   //export ptree
using namespace Fastcgipp::Http;        //export RequestMethod::POST

class BaseHandler : public Fastcgipp::Request<char>
{
public:
    BaseHandler();
    virtual ~BaseHandler();

    void LogRequest();
    int Response(const char* contentType, const char* content, int errcode);
    void ResponseJson(ptree& retJson);
    void ResponseError(int errcode, std::string paramMsg="");
    void ResponseOpenAPI();
    void ResponseUserAuth();
};
