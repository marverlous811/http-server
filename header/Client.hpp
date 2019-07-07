//
//  Client.hpp
//  httpServer
//
//  Created by Ows on 7/7/19.
//  Copyright © 2019 hieunq. All rights reserved.
//

#ifndef Client_hpp
#define Client_hpp

#include <stdio.h>
#include "./Request.hpp"
#include "./Response.hpp"

class Client {
    Request* req;
    Response* res;
    
public:
    Client();
    char* action(char* buffer);
};

#endif /* Client_hpp */
