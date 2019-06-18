//
//  TcpConnection.hpp
//  httpServer
//
//  Created by Ows on 6/17/19.
//  Copyright © 2019 hieunq. All rights reserved.
//

#ifndef TcpConnection_hpp
#define TcpConnection_hpp

#include "Event.hpp"
#include <functional>

class TcpConnection : public Event{
protected:
    void onRead() override;
    void onWrite() override;
    using CB_parser = std::function<void(TcpConnection *self, int fd)>;
public:
    TcpConnection(int fd);
    CB_parser f_parse;
};

#endif /* TcpConnection_hpp */
