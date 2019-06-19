//
//  main.cpp
//  httpServer
//
//  Created by Ows on 6/14/19.
//  Copyright © 2019 hieunq. All rights reserved.
//

#include <iostream>
#include "./header/TcpListener.hpp"
#include "./header/EventLoop.hpp"
#include "./header/TcpConnection.hpp"
#include "./header/Request.hpp"
#include "./header/Response.hpp"

int main(int argc, const char * argv[]) {
    printf("hello world\n");
    
//    Request *req = new Request("GET / HTTP/1.1\r\n"
//                               "Host: localhost:8080\r\n"
//                               "Connection: keep-alive\r\n"
//                               "Upgrade-Insecure-Requests: 1\r\n"
//                               "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n"
//                               "User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_13_3) AppleWebKit/604.5.6 (KHTML, like Gecko) Version/11.0.3 Safari/604.5.6\r\n"
//                               "Accept-Language: en-us\r\n"
//                               "DNT: 1\r\n"
//                               "Accept-Encoding: gzip, deflate\r\n"
//                               "\r\n"
//                               "Usually GET requests don\'t have a body\r\n"
//                               "But I don\'t care in this case :)");
//    req->inspect();
    
    EventLoop el;
    TcpListener *listener = new TcpListener(8080);
    listener->onConnect = [](TcpListener *self, int fd){
        TcpConnection *conn = new TcpConnection(fd);

        conn->f_parse = [](TcpConnection *self, char *buffer){
            Request *req = new Request(buffer);
            req->inspect();
            
            Response *res = new Response();
            char *data = res->res();
            self->sendData(data);
        };
        conn->f_send = [](TcpConnection *self, int fd){
        };
        self->el->add_event(conn, EVFILT_READ, EV_ADD | EV_ENABLE);
        self->el->add_event(conn, EVFILT_WRITE, EV_ADD | EV_ENABLE);
    };

    el.add_event(listener, EVFILT_READ, EV_ADD | EV_ENABLE);
    el.run();
    
    return 0;
}
