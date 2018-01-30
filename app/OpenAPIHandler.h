#pragma once
#include "BaseHandler.h"

class OpenAPIHandler : public virtual BaseHandler
{
public:
    OpenAPIHandler();
    virtual ~OpenAPIHandler();

protected:
    void HandleOpenAPI(const int id);

private:
    void ResponseWeTest();
};

