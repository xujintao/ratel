#include "BaseHandler.h"
#include "log.h"

BaseHandler::BaseHandler()
{
}


BaseHandler::~BaseHandler()
{
}

void BaseHandler::LogRequest()
{
    //Log(info, "req-in %s", environment().acceptContentTypes);
}

int BaseHandler::Response(const char* contentType, const char* content, int errcode)
{
    out << "Content-type: " << contentType << "; charset=utf-8\r\n\r\n"
        << content;
}

void BaseHandler::ResponseJson(ptree& retJson)
{
    retJson.put("time", time(NULL));
    std::stringstream ss;
    write_json(ss, retJson);

    Response("application/json", ss.str().c_str(), 0);
    Log(debug, "ResponseJson %s %s", environment().requestUri.c_str(), ss.str().c_str());
}

void BaseHandler::ResponseError(int errcode, std::string paramMsg)
{
    std::string strErrMsg = paramMsg.empty() ? "Helper" : paramMsg;
    ptree retJson;
    retJson.put("time", time(NULL));
    retJson.put("errcode", errcode);
    retJson.put("errmsg", strErrMsg);
    std::stringstream ss;
    write_json(ss, retJson);
    Response("application/json", ss.str().c_str(), errcode);
    Log(errcode==0?debug:error, "ResponseJson %s %s", environment().requestUri.c_str(), ss.str().c_str());
}

void BaseHandler::ResponseOpenAPI()
{
    out << \
        "Status: 200 OK\n"\
        "Content-Type: text/html; charset=utf-8\r\n\r\n"\
        "<!DOCTYPE html>"\
        "<html lang='en'>"\
        "<head>"\
        "<title>/OpenAPI/WeTest</title>"\
        "</head>"\
        "<body>"\
        "<h1>/OpenAPI/WeTest</h1>"\
        "</body>"\
        "</html>";
}

void BaseHandler::ResponseUserAuth()
{
    out << \
        "Status: 200 OK\n"\
        "Content-Type: text/html; charset=utf-8\r\n\r\n"\
        "<!DOCTYPE html>"\
        "<html lang='en'>"\
        "<head>"\
        "<title>/UserAuth/LoginByToken</title>"\
        "</head>"\
        "<body>"\
        "<h1>/UserAuth/LoginByToken</h1>"\
        "</body>"\
        "</html>";
}