//
//  httpHandle.hpp
//  httpServer
//
//  Created by Ows on 6/18/19.
//  Copyright © 2019 hieunq. All rights reserved.
//

#ifndef httpHandle_hpp
#define httpHandle_hpp

#include <stdio.h>
#include "httpRequest.hpp"
#include "httpResponse.hpp"

class HttpHandle{
private:
    FILE* file;
    int sock;
    HttpRequest *req;
    HttpResponse *res;
public:
    HttpHandle(int fd);
    int handle();
};

#endif /* httpHandle_hpp */
