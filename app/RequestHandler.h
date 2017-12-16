#pragma once

#include "UserAuthHandler.h"
#include "OpenAPIHandler.h"

class RequestHandler : public OpenAPIHandler
					 , public UserAuthHandler
{
public:
	RequestHandler();
	virtual ~RequestHandler();
	bool response();//实现response接口
};

