//
//  EventLoop.hpp
//  httpServer
//
//  Created by Ows on 6/17/19.
//  Copyright © 2019 hieunq. All rights reserved.
//

#ifndef EventLoop_hpp
#define EventLoop_hpp

#include <sys/event.h>
#include "Event.hpp"

class EventLoop{
public:
    EventLoop();
    int run();
    
    EventLoop& add_event(Event *event, int filter, int flags);
    
private:
    struct kevent *events;
    int events_used = 0;
    int events_alloc = 0;
    int kq;
};

#endif /* EventLoop_hpp */
