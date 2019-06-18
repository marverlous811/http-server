//
//  httpHandle.cpp
//  httpServer
//
//  Created by Ows on 6/18/19.
//  Copyright © 2019 hieunq. All rights reserved.
//

#include "../header/httpHandle.hpp"
#include <unistd.h>

HttpHandle::HttpHandle(int fd) : sock(fd){
    
}

int HttpHandle::handle(){
    if((this->file = fdopen(this->sock, "r+b")) == nullptr){
        printf("open fd error\n");
        return -1;
    }
    
    this->req = new HttpRequest(this->file);
    int ret = this->req->requestParse();
    if(ret < 0){
        fclose(this->file);
        return -1;
    }
    
    this->res = new HttpResponse(this->file);
    ret = this->res->sendHeader();
    if(ret == 0){
        ret = this->res->sendBody();
    }
    
    fflush(this->file);
    fclose(this->file);
    
    close(this->sock);
    
    return 1;
}
