#pragma once

#include "fastcgi++/request.hpp"
#include "fastcgi++/manager.hpp"
#include <iomanip>

class BaseHandler : public Fastcgipp::Request<wchar_t>
{
public:
    BaseHandler();
    virtual ~BaseHandler();
    void LogRequest();
    void ResponseError();
    void ResponseOpenAPI();
    void ResponseUserAuth();
};
