//
//  EventLoop.cpp
//  httpServer
//
//  Created by Ows on 6/17/19.
//  Copyright © 2019 hieunq. All rights reserved.
//

#include "../header/EventLoop.hpp"
#include <stdio.h>
#include <stdlib.h>

EventLoop::EventLoop(){
    this->kq = kqueue();
    if(this->kq < 0){
        printf("create queue error\n");
        return;
    }
}

int EventLoop::run(){
    if(this->kq < 0)
        return -1;
    
    int newEvent;
    while (true) {
        newEvent = kevent(this->kq, events, events_used, events, events_alloc, NULL);
        if(newEvent < 0){
            printf("event loop failed: \n");
            return -1;
        }
        
        events_used = 0;
        
        for (int i = 0; i < newEvent ; i++) {
            struct kevent *e = &events[i];
            Event *event = (Event *)e->udata;
            
            if(e->filter == EVFILT_READ){
                event->onRead();
            }
            else if(e->filter == EVFILT_WRITE){
                event->onWrite();
            }
        }
    }
    
    return 1;
}

EventLoop& EventLoop::add_event(Event *event, int filter, int flags){
    struct kevent *e;
    
    event->el = this;
    
    if(this->events_alloc == 0){
        this->events_alloc = 32;
        this->events = (struct kevent*)malloc(events_alloc * sizeof(struct kevent));
    }
    
    if(this->events_alloc < this->events_used){
        this->events_alloc *= 2;
        this->events = (struct kevent*)malloc(events_alloc * sizeof(struct kevent));
    }
    
    int index = events_used++;
    e = &events[index];
    
    e->ident = event->fd;
    e->filter = filter;
    e->flags = flags;
    e->fflags = 0;
    e->data = 0;
    e->udata = event;
    
    return *this;
}
