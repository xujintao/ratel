#include "BaseHandler.h"
#include "log.h"
#include "AK47.h"

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

    //序列化postData
    Json::FastWriter fwriter;
    fwriter.omitEndingLineFeed();//去除尾部换行符
    std::string strData = fwriter.write(env.jsons);

    std::string strRequset;
    strRequset += "{\"ip\":\"" + ssRemoteAddress.str()
                + "\",\"uri\":\"" + env.requestUri
                + "\",\"host\":\"" + env.host
                + "\",\"postData\":" + strData
                + ",\"cookies\":\"" + Cookie2String()
                + "\",\"userAgent\":\"" + env.userAgent
                + "\",\"referer\":\"" + env.referer
                + "\",\"contentType\":\"" + env.contentType
                + "\",\"requestMethod\":\"" + requestMethodLabels[static_cast<int>(env.requestMethod)]
                + "\",\"scriptName\":\"" + env.scriptName
                + "\",\"contentLength\":" + std::to_string(env.contentLength)
                + ",\"remotePort\":" + std::to_string(env.remotePort)
                + "}";
    Log(info, "req-in %s", strRequset.c_str());
}

int BaseHandler::Response(const char* contentType, const char* content, int errcode)
{
    out << "Content-type: " << contentType << "; charset=utf-8\r\n\r\n"
        << content;
}

void BaseHandler::ResponseJson(Json::Value& retJson)
{
    retJson["time"] = time(NULL);

    //序列化
    Json::FastWriter fwriter;
    fwriter.omitEndingLineFeed();//去除尾部换行符
    std::string retStr = fwriter.write(retJson);

    Response("application/json", retStr.c_str(), ERR_OK);
    Log(debug, "ResponseJson %s %s", environment().requestUri.c_str(), retStr.c_str());
}

void BaseHandler::ResponseError(int errcode, std::string paramMsg)
{
    std::string strErrMsg = paramMsg.empty() ? AK47::GetErrMsg(errcode) : paramMsg;

    //boostJson
    //ptree retJson;
    //retJson.put("time", time(NULL));
    //retJson.put("errcode", errcode);
    //retJson.put("errmsg", strErrMsg);
    //std::stringstream ss;
    //write_json(ss, retJson, false);

    //rapidJson
    //Document retJson;
    //retJson.AddMember("time", time(NULL), retJson.GetAllocator());
    //retJson.AddMember("errcode", errcode, retJson.GetAllocator());
    ////retJson.AddMember("errmsg", strErrMsg.c_str(), retJson.GetAllocator());
    //retJson.AddMember("errmsg", strErrMsg, retJson.GetAllocator());
    ////Value s;
    ////s.SetString(strErrMsg);
    ////retJson.AddMember("errmsg", s, retJson.GetAllocator());
    //StringBuffer buffer;
    //Writer<StringBuffer> writer(buffer);
    //retJson.Accept(writer);

    //jsoncpp
    Json::Value retJson;
    retJson["time"] = time(NULL);
    retJson["errcode"] = errcode;
    retJson["errmsg"] = strErrMsg;

    //序列化
    Json::FastWriter fwriter;
    fwriter.omitEndingLineFeed();//去除尾部换行符
    std::string retStr = fwriter.write(retJson);

    Response("application/json", retStr.c_str(), errcode);
    Log(errcode == 0 ? debug : error, "ResponseError %s %s", environment().requestUri.c_str(), retStr.c_str());
}
