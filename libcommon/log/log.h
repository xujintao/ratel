#pragma once
#include <string>

namespace common{
    enum severity_level {
        trace,
        debug,
        info,
        warning,
        error,
        fatal,
        report
    };
    void InitLog();
    int Log(severity_level level, const char* fmt, ...);
}
using namespace common;
