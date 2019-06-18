//
//  httpRequest.cpp
//  httpServer
//
//  Created by Ows on 6/18/19.
//  Copyright © 2019 hieunq. All rights reserved.
//

#include "../header/httpRequest.hpp"
#include <string.h>

HttpRequest::HttpRequest(FILE *file) : fsock(file){}

int HttpRequest::requestParse(){
    char* ret;
    char* method;
    char* url;
    char buf[4096];
    char cmd[2048];
    
    ret = fgets(cmd, sizeof(cmd), this->fsock);
    if(ret != nullptr){
        method = strtok(ret, " ");
        url = strtok(nullptr, " ");
        
        if(method == nullptr || url == nullptr){
            printf("request have no info\n");
            return -1;
        }
        
        this->setMethod(method);
        this->url = url;
    }
    
    ret = fgets(buf, sizeof(buf), this->fsock);
    while ((ret != nullptr) && (buf[0] != '\r') && (buf[0] = '\n')) {
        ret = fgets(buf, sizeof(buf), this->fsock);
    }
    
    return 1;
}

void HttpRequest::setMethod(char* method){
    if(strcmp(method, "GET") == 0){
        this->method = GET;
    }
    else if(strcmp(method, "POST") == 0){
        this->method = POST;
    }
}
