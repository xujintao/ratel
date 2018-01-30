#include "OpenAPIHandler.h"
#include "URL2ID.h"

OpenAPIHandler::OpenAPIHandler()
{
}


OpenAPIHandler::~OpenAPIHandler()
{
}

void OpenAPIHandler::ResponseWeTest()
{
    int errCode = ERR_OK;
    Json::Value dataJson;
    if (!m_db->GetWeTestData(dataJson))
    {
        ResponseError(ERR_DB);
        return;
    }
    
    Json::Value retJson;
    retJson["errcode"] = errCode;
    retJson["data"] = dataJson;
    ResponseJson(retJson);
}

void OpenAPIHandler::HandleOpenAPI(const int id)
{
    switch (environment().requestMethod)
    {
    case RequestMethod::GET:
        //id处理
        switch (id)
        {
        case URL_ID::WeTest:
            ResponseWeTest();
            break;
        default:
            ResponseError(ERR_NO_API);
            break;
        }
        break;
    default:
        ResponseError(ERR_NO_API);
        break;
    }
}
