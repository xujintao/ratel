#include "BaseHandler.h"
#include "log.h"
#include "AK47.h"

BaseHandler::BaseHandler()
{
}


BaseHandler::~BaseHandler()
{
}

std::string BaseHandler::Cookie2String()
{
    std::ostringstream oss;
    if (environment().cookies.size())
    for (const auto& cookie : environment().cookies)
        oss << cookie.first << ":" << cookie.second;
    else
        oss << "";
    return oss.str();
}

void BaseHandler::LogRequest()
{
    const auto& env = environment();

    //remoteAddress
    std::stringstream ssRemoteAddress;
    ssRemoteAddress << env.remoteAddress;

    //postData
    std::stringstream ssPostData;
    write_json(ssPostData, env.jsons);

    std::string strRequset;
    strRequset += "{\"ip\":\"" + ssRemoteAddress.str()
                + "\",\"uri\":\"" + env.requestUri
                + "\",\"host\":\"" + env.host
                + "\",\"postData\":\"" + ssPostData.str()
                + "\",\"cookies\":\"" + Cookie2String()
                + "\",\"userAgent\":\"" + env.userAgent
                + "\",\"referer\":\"" + env.referer
                + "\",\"contentType\":\"" + env.contentType
                + "\",\"requestMethod\":\"" + requestMethodLabels[static_cast<int>(env.requestMethod)]
                + "\",\"scriptName\":\"" + env.scriptName
                + "\",\"contentLength\":\"" + std::to_string(env.contentLength)
                + "\",\"remotePort\":\"" + std::to_string(env.remotePort)
                + "}";
    Log(info, "req-in %s", strRequset.c_str());
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
    std::string strErrMsg = paramMsg.empty() ? AK47::GetErrMsg(errcode) : paramMsg;
    ptree retJson;
    retJson.put("time", time(NULL));
    retJson.put("errcode", errcode);
    retJson.put("errmsg", strErrMsg);
    std::stringstream ss;
    write_json(ss, retJson);
    Response("application/json", ss.str().c_str(), errcode);
    Log(errcode==0?debug:error, "ResponseJson %s %s", environment().requestUri.c_str(), ss.str().c_str());
}
