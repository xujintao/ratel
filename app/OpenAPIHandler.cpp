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
    //����֤

    //id����
    switch (id)
    {
    case URL_ID::WeTest:
        ResponseOpenAPI();
        break;
    default:
        break;
    }
}
