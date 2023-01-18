#ifndef CHATSERVER_H
#define CHATSERVER_H
#include <iostream>
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
using namespace muduo::net;
using namespace muduo;

class ChatServer{
public:
    ChatServer(EventLoop* loop,const InetAddress& address,const string& nameArg);
   
    void start();
       
    

private:
    TcpServer _server;
    EventLoop *_loop;
    void onConnection(const TcpConnectionPtr& con);
    void onMessage(const TcpConnectionPtr& con,Buffer* buf,Timestamp time);

    
};
#endif