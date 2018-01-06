#include "AK47.h"
#include "typeDef.h"

std::string AK47::GetErrMsg(int errCode)
{
    switch (errCode)
    {
    case ERR_OK:
        return "成功";
    case ERR_INTERNAL:
        return "数据库逻辑错误";
    case ERR_DB:
        return "数据库异常";
    case ERR_NO_API:
        return "接口不存在";
    case ERR_NO_PARAMETER:
        return "非法参数";
    default:
        return "未知错误";
    }
}

