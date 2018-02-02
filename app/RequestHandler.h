#pragma once

#include "UserAuthHandler.h"
#include "OpenAPIHandler.h"

class RequestHandler : public OpenAPIHandler
                     , public UserAuthHandler
{
public:
    RequestHandler();
    virtual ~RequestHandler();
    bool Handle(_RequestPtr _request) override;//实现Handle接口
};

