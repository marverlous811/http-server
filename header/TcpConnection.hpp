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
    void* msg_alloc(size_t &size);
    void msg_free(const void *ptr);
    void parse( char **data, size_t size, size_t rese );
protected:
    void onRead() override;
    void onWrite() override;
    using CB_parser = std::function<void(TcpConnection *self, char *buffer)>;
    using CB_send = std::function<void(TcpConnection *self, int fd)>;
public:
    TcpConnection(int fd);
    void sendData(char* buffer);
    void send(char **data, size_t size, size_t rese = 0);
    CB_parser f_parse;
    CB_send f_send;
    
    unsigned inp_buffer_size;
    char *inp_buffer;
};

#endif /* TcpConnection_hpp */
