#include "URL2ID.h"

#define STR(x) #x

std::map<std::string, int> URL2ID::m_mapURL2Mid;
std::map<std::string, int> URL2ID::m_mapURL2Id;

int URL2ID::FindMid(const std::string& str)
{
    return m_mapURL2Mid[str];
}

int URL2ID::FindId(const std::string& str)
{
    return m_mapURL2Id[str];
}

void URL2ID::Init()
{
    //module
    m_mapURL2Mid[STR(OpenAPI)] = OpenAPI;
    m_mapURL2Mid[STR(UserAuth)] = UserAuth;

    //id
    m_mapURL2Id[STR(WeTest)] = WeTest;
    m_mapURL2Id[STR(LoginByToken)] = LoginByToken;
}
