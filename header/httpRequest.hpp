//
//  httpRequest.hpp
//  httpServer
//
//  Created by Ows on 6/18/19.
//  Copyright © 2019 hieunq. All rights reserved.
//

#ifndef httpRequest_hpp
#define httpRequest_hpp

#include <stdio.h>

enum METHOD {
    GET = 0,
    POST
};

class HttpRequest{
private:
    FILE *fsock;
    char* ct = (char *)"text/plain";
    char* url;
    METHOD method;
    
    void setMethod(char* method);
    
public:
    HttpRequest(FILE *fsock);
    int requestParse();
    METHOD getMethod();
};

#endif /* httpRequest_hpp */
