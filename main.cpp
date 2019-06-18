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
#include "./header/httpHandle.hpp"

int main(int argc, const char * argv[]) {
    printf("hello world\n");
    
    EventLoop el;
    TcpListener *listener = new TcpListener(8080);
    listener->onConnect = [](TcpListener *self, int fd){
        TcpConnection *conn = new TcpConnection(fd);
        
        conn->f_parse = [](TcpConnection *self, int fd){
            HttpHandle *handle = new HttpHandle(fd);
            handle->handle();
        };
        self->el->add_event(conn, EVFILT_READ);
        self->el->add_event(conn, EVFILT_WRITE);
    };
    
    el.add_event(listener, EVFILT_READ);
    el.run();
    
    return 0;
}
