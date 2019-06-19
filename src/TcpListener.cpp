//
//  TcpListener.cpp
//  httpServer
//
//  Created by Ows on 6/17/19.
//  Copyright © 2019 hieunq. All rights reserved.
//

#include "../header/TcpListener.hpp"
#include "../header/util.hpp"
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

TcpListener::TcpListener(unsigned int port) : Event(-1){
    struct sockaddr_in server;
    
    this->fd = socket(AF_INET, SOCK_STREAM, 0);
    if(this->fd < 0){
        printf("create socket error\n");
        return;
    }
    
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    
    int opt_val = 1;
    setsockopt(this->fd, SOL_SOCKET, SO_REUSEADDR, &opt_val, sizeof(opt_val));
    setsockopt(this->fd, SOL_SOCKET, SO_REUSEPORT, &opt_val, sizeof(opt_val));
    
    int ret = bind(this->fd, (struct sockaddr*)&server, sizeof(server));
    if(ret < 0){
        printf("bind port error\n");
        return;
    }
    
    set_non_block(this->fd);
    
    ret = listen(this->fd, 5);
    if(ret < 0){
        printf("listen port err\n");
        return;
    }
    
    printf("server is running in port %d\n",port);
}

void TcpListener::onRead(){
    struct sockaddr client;
    socklen_t client_len = sizeof(client);
    
    int client_fd = accept(this->fd, &client, &client_len);
    if(client_fd < 0){
        printf("accept error\n");
        return;
    }
    
//    printf("accepted connection\n");
    
    set_non_block(client_fd);
    this->connection(client_fd);
}

void TcpListener::onWrite(){
    
}

void TcpListener::connection(int fd){
    if(this->onConnect){
        this->onConnect(this, fd);
    }
}
