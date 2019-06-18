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

TcpConnection::TcpConnection(int fd) : Event(fd){
    
}

void TcpConnection::onRead(){
     if(this->f_parse)
         this->f_parse(this, this->fd);
}

void TcpConnection::onWrite(){
    
}
