//
//  httpResponse.hpp
//  httpServer
//
//  Created by Ows on 6/18/19.
//  Copyright © 2019 hieunq. All rights reserved.
//

#ifndef httpResponse_hpp
#define httpResponse_hpp

#include <stdio.h>

class HttpResponse{
    FILE *file;
    char *ct = (char *)"text/plain";
public:
    HttpResponse(FILE *file);
    int sendHeader();
    int sendBody();
};

#endif /* httpResponse_hpp */
