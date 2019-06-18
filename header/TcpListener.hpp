//
//  TcpListener.hpp
//  httpServer
//
//  Created by Ows on 6/17/19.
//  Copyright © 2019 hieunq. All rights reserved.
//

#ifndef TcpListener_hpp
#define TcpListener_hpp

#include "Event.hpp"
#include <functional>

class TcpListener : public Event{
protected:
    void onRead() override;
    void onWrite() override;
public:
    using CB_Connection = std::function<void(TcpListener *l, int fd)>;
    CB_Connection onConnect;
    
    void connection(int fd);
    TcpListener(unsigned int port);
};

#endif /* TcpListener_hpp */
