#pragma once
#include "mysqlwrapper.h"
#include "json/json.h"  //Json

class DataBase : public MySQLWrapper
{
public:
    DataBase();
    ~DataBase();
    bool GetWeTestData(Json::Value& data);
};

