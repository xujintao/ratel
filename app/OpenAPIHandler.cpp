#include "OpenAPIHandler.h"
#include "URL2ID.h"

OpenAPIHandler::OpenAPIHandler()
{
}


OpenAPIHandler::~OpenAPIHandler()
{
}

void OpenAPIHandler::ResponseWeTest(RequestPtr request)
{
    int errCode = ERR_OK;
    Json::Value dataJson;
    if (!m_db->GetWeTestData(dataJson))
    {
        ResponseError(request, ERR_DB);
        return;
    }
    
    Json::Value retJson;
    retJson["errcode"] = errCode;
    retJson["data"] = dataJson;
    ResponseJson(request, retJson);
}

void OpenAPIHandler::HandleOpenAPI(RequestPtr request, const int id)
{
    switch (request->environment().requestMethod)
    {
    case RequestMethod::GET:
        //id处理
        switch (id)
        {
        case URL_ID::WeTest:
            ResponseWeTest(request);
            break;
        default:
            ResponseError(request, ERR_NO_API);
            break;
        }
        break;
    default:
        ResponseError(request, ERR_NO_API);
        break;
    }
}
