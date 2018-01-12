#include "spawnfcgi.h"  //use spawn-fcgi
//#include "echo-cpp.h"   //use fastcgi demo
//#include "echo.h"       //use fastcgi++ demo
#include "RequestHandler.h" //use RequestHandler(app)
#include "URL2ID.h"     //url2id
#include "log.h"    //Log

int main(int argc, char **argv) {
    
    if(0 == spawn_fcgi(argc, argv))
    {
        URL2ID::Init();
        common::InitLog();
        //fcgi网络框架
        //echo();

        //fastcgipp框架
        //Fastcgipp::Manager<Echo> manager;
        Fastcgipp::Manager<RequestHandler> manager;
        manager.setupSignals();
        manager.listen();
        Log(info, "start");
        manager.start();
        manager.join();

        return 0;
    }
}
