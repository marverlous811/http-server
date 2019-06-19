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

#define BUFFER_SIZE 1024

class TcpConnection : public Event{
private:
    char *buffer;
protected:
    void onRead() override;
    void onWrite() override;
    using CB_parser = std::function<void(TcpConnection *self, char *buffer)>;
    using CB_send = std::function<void(TcpConnection *self, int fd)>;
public:
    TcpConnection(int fd);
    void sendData(char* buffer);
    CB_parser f_parse;
    CB_send f_send;
};

#endif /* TcpConnection_hpp */
