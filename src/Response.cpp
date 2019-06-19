//
//  Response.cpp
//  httpServer
//
//  Created by Ows on 6/19/19.
//  Copyright © 2019 hieunq. All rights reserved.
//

#include "../header/Response.hpp"

Response::Response() : status("OK"), statusCode(200){
    
};

char* Response::res(){
    char *buffer;
    buffer = "HTTP/1.1 200 OK\r\n"
            "Server: marverlous/C++\r\n"
            "Content-Type: text/plain\r\n"
            "Content-Length: 11\r\n"
            "\r\n"
            "Hello world\n";
    
    return buffer;
}
