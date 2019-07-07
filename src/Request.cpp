//
//  Request.cpp
//  httpServer
//
//  Created by Ows on 6/19/19.
//  Copyright © 2019 hieunq. All rights reserved.
//

#include "../header/Request.hpp"
#include "../header/util.hpp"
#include <string.h>

Request::Request(char* buffer){
    this->parser(buffer);
}

Request::Request(){
    
}

int Request::parser(char *buffer){
    //Method
    this->setMethod(buffer);
    size_t meth_len = strcspn(buffer, " ");
    buffer += meth_len + 1;
    
    //uri
    size_t url_len = strcspn(buffer, " ");
    this->url = (char *)malloc(url_len + 1);
    memcpy(this->url, buffer, url_len);
    this->url[url_len] = '\0';
    buffer += url_len + 1;
    
    size_t ver_len = strcspn(buffer, "\r\n");
    this->version = (char *)malloc(ver_len + 1);
    memcpy(this->version, buffer, ver_len);
    this->version[ver_len] = '\0';
    buffer += ver_len + 2;
    
//    printf("%s\n", buffer);
    while (buffer[0] != '\r' && buffer[1] != '\n') {
        size_t name_len = strcspn(buffer, ":");
        char* name = (char *)malloc(name_len + 1);
        memcpy(name, buffer, name_len);
        name[name_len] = '\0';
        buffer += name_len + 1;

        size_t value_len = strcspn(buffer, "\r\n");
        char* value = (char *)malloc(value_len + 1);
        memcpy(value, buffer, value_len);
        value[value_len] = '\0';

        this->header.insert(std::pair<char *, char *>(name, value));
        buffer += value_len + 2;
    
    }
    
    size_t body_len = strlen(buffer);
    this->body = (char *)malloc(body_len + 1);
    memcpy(this->body, buffer, body_len);
    this->body[body_len] = '\0';
    
    return 1;
}

void Request::setMethod(char* buffer){
    if(memcmp(buffer, "GET", strlen("GET")) == 0){
        this->method = GET;
    }
    else{
        this->method = UNDEFINED;
    }
}

void Request::inspect(){
    printf("Method: %d\n", this->method);
    printf("Url: %s\n", this->url);
    printf("Version: %s\n", this->version);
    printf("Headers: \n");
    std::map<char*, char*>::iterator temp;
    for(temp = this->header.begin(); temp != this->header.end(); temp++){
        printf("%s: %s\n",temp->first, temp->second);
    }
    
    printf("body message: %s\n", this->body);
}
