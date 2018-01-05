#include "OpenAPIHandler.h"
#include "URL2ID.h"

OpenAPIHandler::OpenAPIHandler()
{
}


OpenAPIHandler::~OpenAPIHandler()
{
}

void OpenAPIHandler::HandleOpenAPI(const int id)
{
    //不验证

    //id处理
    switch (id)
    {
    case URL_ID::WeTest:
        ResponseOpenAPI();
        break;
    default:
        break;
    }
}
