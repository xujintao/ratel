#include "DataBase.h"

DataBase::DataBase()
{
}


DataBase::~DataBase()
{
}

bool DataBase::GetWeTestData(Json::Value& data)
{
    bool ret = false;
    std::string sql = "select * from t_user";
    try
    {
        //format sql
        std::unique_ptr<sql::ResultSet> pRes(ExecuteQuery(sql));
        if (pRes && pRes->next())
        {
            data["name"] = pRes->getString("name").asStdString();
            data["phone"] = pRes->getString("phone").asStdString();
            ret = true;
        }
    }
    catch (sql::SQLException& e)
    {
        LogSqlException(e, "GetWeTestData", sql);
        HandleException(e);
    }
    return ret;
}
