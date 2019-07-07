//
//  Request.hpp
//  httpServer
//
//  Created by Ows on 6/19/19.
//  Copyright © 2019 hieunq. All rights reserved.
//

#ifndef Request_hpp
#define Request_hpp

#include <map>

enum METHOD{
    UNDEFINED = 0,
    GET
};

class Request{
    std::map<char*, char*> header;
    char* url;
    char* version;
    char* body;
    METHOD method;
public:
    Request();
    Request(char* buffer);
    int parser(char *buffer);
    void setMethod(char *method);
    char* getMethod();
    void inspect();
};

#endif /* Request_hpp */
