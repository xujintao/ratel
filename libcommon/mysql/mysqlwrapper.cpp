#pragma once

#include "mysqlwrapper.h"
#include "log.h"

MySQLWrapper::MySQLWrapper() : m_driver(nullptr)
{
}
MySQLWrapper::~MySQLWrapper()
{
    if (m_con)
    {
        if (!m_con->isClosed())
            m_con->close();
    }
    m_con.reset();
}

bool MySQLWrapper::Init(std::string&& host, std::string&& user, std::string&& password, std::string&& dbname)
{
    std::unique_lock<std::mutex> lock(m_mutex);
    m_driver = get_driver_instance();
    lock.unlock();

    if (m_driver)
        m_con.reset(m_driver->connect(host, user, password));

    if (m_con)
    {
        m_con->setSchema(dbname);
        std::unique_ptr<sql::Statement> stmt(m_con->createStatement());
        stmt->execute("SET NAMES UTF8");

        m_host = host;
        m_user = user;
        m_password = password;
        m_dbname = dbname;
        Log(info, "connect mysql ok");
    }
    return m_con ? true : false;
}

void MySQLWrapper::LogSqlException(const sql::SQLException& e, const std::string& prefix, const std::string& sql)
{
    Log(error, "in %s.mysql ERROR %d (%s).sql:%s", prefix.c_str(), e.getErrorCode(), e.getSQLStateCStr(), e.what(), sql.c_str());
}

bool MySQLWrapper::HandleException(sql::SQLException& e)
{
    bool ret = false;
    if (2006 == e.getErrorCode() || 2014 == e.getErrorCode() || "lost" == e.getSQLState())
    {
        try{
            m_con.reset(m_driver->connect(m_host, m_user, m_password));
            if (m_con)
            {
                m_con->setSchema(m_dbname);
                std::unique_ptr<sql::Statement> stmt(m_con->createStatement());
                stmt->execute("SET NAMES UTF8");
                Log(info, "reconnect mysql ok");
                ret = true;
            }
            else
            {
                Log(error, "reconnect mysql failed");
                ret = false;
            }
        }
        catch (sql::SQLException& e)
        {
            Log(error, "SQLException in %s(%s) on line %d ErrCode %d SQLState %s Reason %s"
                , __FILE__, __FUNCTION__, __LINE__, e.getErrorCode(), e.getSQLStateCStr(), e.what());
            ret = false;
        }
        return ret;
    }
}

sql::Statement* MySQLWrapper::CreateStatement()
{
    if (!m_con)
        throw sql::SQLException("DB not available", "lost");
    return m_con->createStatement();
}

sql::PreparedStatement* MySQLWrapper::PrepareStatement(const std::string& sql)
{
    if (!m_con)
        throw sql::SQLException("DB not available", "lost");
    return m_con->prepareStatement(sql);
}

sql::ResultSet* MySQLWrapper::ExecuteQuery(const std::string& sql)
{
    if (!m_con)
        throw sql::SQLException("DB not available", "lost");
    std::unique_ptr<sql::Statement> stmt(m_con->createStatement());
    return stmt->executeQuery(sql);
}

sql::ResultSet* MySQLWrapper::ExecuteQuery(std::shared_ptr<sql::Statement> stmt, const std::string& sql)
{
    if (!stmt)
        throw sql::SQLException("Transaction not available");
    return stmt->executeQuery(sql);
}

int MySQLWrapper::ExecuteUpdate(const std::string& sql)
{
    if (!m_con)
        throw sql::SQLException("DB not available", "lost");
    std::unique_ptr<sql::Statement> stmt(m_con->createStatement());
    return stmt->executeUpdate(sql);
}

int MySQLWrapper::ExecuteUpdate(std::shared_ptr<sql::Statement> stmt, const std::string& sql)
{
    if (!stmt)
        throw sql::SQLException("Transaction not available");
    return stmt->executeUpdate(sql);
}

