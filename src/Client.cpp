//
//  Client.cpp
//  httpServer
//
//  Created by Ows on 7/7/19.
//  Copyright © 2019 hieunq. All rights reserved.
//

#include "../header/Client.hpp"

Client::Client(){
    this->req = new Request();
    this->res = new Response();
}

char* Client::action(char *buffer){
    this->req->parser(buffer);
    return this->res->res();
}
