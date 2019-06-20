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
#include <sys/types.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <errno.h>

TcpConnection::TcpConnection(int fd) : Event(fd){
    
}

void* TcpConnection::msg_alloc(size_t &size){
    size = ( size + 7 ) & ~7;
    return malloc( size );
}

void TcpConnection::msg_free(const void *ptr){
    free( (void *)ptr );
}

void TcpConnection::onRead(){
    unsigned buffer_size, max_buffer_size = 1u << 20;
    while (true) {
        if(ioctl(this->fd, FIONREAD, &buffer_size) == -1){
            buffer_size = 8192;
        }
        else if(buffer_size > max_buffer_size){
            buffer_size = max_buffer_size;
        }
        break;
    }
    
    size_t off = 0, rese = off + buffer_size;
    if( !this->inp_buffer){
        inp_buffer = (char *)msg_alloc( rese );
        inp_buffer_size = rese - off;
    }
    else if(buffer_size > inp_buffer_size){
        //TODO: check this memory leak in this
        //msg_free(inp_buffer);
        inp_buffer = (char *)msg_alloc( rese );
        inp_buffer_size = rese - off;
    }
    
    ssize_t used = recv(this->fd, inp_buffer, inp_buffer_size, MSG_DONTWAIT);
    if (used <= 0) {
        return onClose();
    }
    
    this->parse(&inp_buffer, used, inp_buffer_size);
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

void TcpConnection::parse(char **data, size_t size, size_t rese){
    if(this->f_parse){
        this->f_parse(this, inp_buffer);
    }
}

void TcpConnection::send(char **data, size_t size, size_t rese){
    if(size == 0)
        return;
    
    iovec iov;
    iov.iov_base = (void *)*data;
    iov.iov_len = size;
    
    msghdr msg;
    bzero(&msg, sizeof(msg));
    msg.msg_iovlen = 1;
    msg.msg_iov = &iov;
    
    // while(true){
        ssize_t real = sendmsg(this->fd, &msg, 0);
        if(real <= 0){
            //TODO: app terminate by signal 23
            // if ( errno == EINTR )
            //     continue;
            // if ( real < 0 and ( errno == EAGAIN or errno == EWOULDBLOCK ) )
            //     return;
            
            close(this->fd);
            return;
        }
    // }
}
