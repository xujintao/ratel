#pragma once

#include "mysql_connection.h"
#include "cppconn/driver.h"
#include "cppconn/exception.h"
#include "cppconn/resultset.h"
#include "cppconn/statement.h"
#include "cppconn/prepared_statement.h"
#include <mutex>

class MySQLWrapper
{
public:
    MySQLWrapper();
    virtual ~MySQLWrapper();

    bool Init(std::string&& host, std::string&& user, std::string&& password, std::string&& dbname);
    void LogSqlException(const sql::SQLException& e, const std::string& prefix, const std::string& sql);
    bool HandleException(sql::SQLException& e);
    sql::Statement* CreateStatement();
    sql::PreparedStatement* PrepareStatement(const std::string& sql);
    sql::ResultSet* ExecuteQuery(const std::string& sql);
    sql::ResultSet* ExecuteQuery(std::shared_ptr<sql::Statement> stmt, const std::string& sql);
    int ExecuteUpdate(const std::string& sql);
    int ExecuteUpdate(std::shared_ptr<sql::Statement> stmt, const std::string& sql);

private:
    std::mutex m_mutex;
    sql::Driver* m_driver;
    std::shared_ptr<sql::Connection> m_con;
    std::string m_host;
    std::string m_user;
    std::string m_password;
    std::string m_dbname;
};


