#include "spawnfcgi.h"  //use spawn-fcgi
#include "echo-cpp.h"   //use fastcgi demo
#include "echo.h"       //use fastcgi++ demo
#include "RequestHandler.h" //app
#include "URL2ID.h"     //url2id
#include "log.h"

int main(int argc, char **argv) {
    
    if(0 == spawn_fcgi(argc, argv))
    {
        URL2ID::Init();
        common::InitLog();
        //LOG_INFO << "init";
        Log(info, "init,%d,%s", 10, "hello1");
        Log(info, "init,%d,%s", 10, "hello2");
        //fcgi网络框架
        //echo();

        //fastcgipp框架
        //Fastcgipp::Manager<Echo> manager;
        Fastcgipp::Manager<RequestHandler> manager;
        manager.setupSignals();
        manager.listen();
        manager.start();
        manager.join();

        return 0;
    }
}
