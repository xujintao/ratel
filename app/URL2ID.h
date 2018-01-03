#pragma once
#include <string>
#include <map>

enum URL_MODULE_ID
{
    OpenAPI = 1,
    UserAuth,
};

enum URL_ID
{
    WeTest = 1,
    LoginByToken,
};

class URL2ID
{
public:
    static void Init();
    static int FindMid(const std::string& str);
    static int FindId(const std::string& str);

private:
    static std::map<std::string, int> m_mapURL2Mid;
    static std::map<std::string, int> m_mapURL2Id;
};

