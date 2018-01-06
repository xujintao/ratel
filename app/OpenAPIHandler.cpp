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
    switch (environment().requestMethod)
    {
    case RequestMethod::POST:
        //id处理
        switch (id)
        {
        case URL_ID::WeTest:
            //ResponseOpenAPI();
            break;
        default:
            ResponseError(ERR_NO_API);
            break;
        }
        break;
    case RequestMethod::GET:
    default:
        ResponseError(ERR_NO_API);
        break;
    }
}
