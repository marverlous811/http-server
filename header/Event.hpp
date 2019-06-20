//
//  Event.hpp
//  httpServer
//
//  Created by Ows on 6/17/19.
//  Copyright © 2019 hieunq. All rights reserved.
//

#ifndef Event_hpp
#define Event_hpp

class EventLoop;

class Event{
protected:
    int fd;
    virtual void onRead() = 0;
    virtual void onWrite() = 0;
    void onClose();
    void close_fd();
    
    friend class EventLoop;
public:
    Event(int fd = -1);
    EventLoop *el;
};

#endif /* Event_hpp */
