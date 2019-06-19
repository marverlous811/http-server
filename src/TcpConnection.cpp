//
//  TcpConnection.cpp
//  httpServer
//
//  Created by Ows on 6/17/19.
//  Copyright © 2019 hieunq. All rights reserved.
//

#include "../header/TcpConnection.hpp"
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

TcpConnection::TcpConnection(int fd) : Event(fd){
    
}

void TcpConnection::onRead(){
    size_t inp_buffer = sizeof(char)*BUFFER_SIZE;
    this->buffer = (char *)malloc(sizeof(char)*BUFFER_SIZE);
    ssize_t used = recv(this->fd, this->buffer, inp_buffer, MSG_DONTWAIT);
    if(used < 0){
//        printf("read data error\n");
        return;
    }
//    printf("%s\n",this->buffer);
    
     if(this->f_parse)
         this->f_parse(this, this->buffer);
}

void TcpConnection::sendData(char *buffer){
    printf("%s\n", buffer);
    ssize_t real = write(this->fd, buffer, strlen(buffer));
    if(real < 0){
        printf("send data error\n");
        return;
    }
    
    close(this->fd);
//    if(this->f_send)
//        this->f_send(this, this->fd);
}

void TcpConnection::onWrite(){
    
}
