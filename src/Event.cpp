//
//  Event.cpp
//  httpServer
//
//  Created by Ows on 6/17/19.
//  Copyright © 2019 hieunq. All rights reserved.
//

#include "../header/Event.hpp"
#include <unistd.h>

Event::Event(int fd) : fd(fd){}

void Event::onClose(){
    close_fd();
}

void Event::close_fd(){
    close(this->fd);
}
