#pragma once
#include "BaseHandler.h"

class OpenAPIHandler : public virtual BaseHandler
{
public:
    OpenAPIHandler();
    virtual ~OpenAPIHandler();

protected:
    void HandleOpenAPI(RequestPtr request, const int id);

private:
    void ResponseWeTest(RequestPtr request);
};

