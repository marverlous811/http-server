//
//  httpResponse.cpp
//  httpServer
//
//  Created by Ows on 6/18/19.
//  Copyright © 2019 hieunq. All rights reserved.
//

#include "../header/httpResponse.hpp"

HttpResponse::HttpResponse(FILE *file) : file(file){}

int HttpResponse::sendHeader(){
    if(this->file == nullptr){
        printf("not have file\n");
        return -1;
    }
    
    fprintf(this->file, "HTTP/1.0 200 OK\r\n");
    fprintf(this->file, "Content-Type: %s\r\n", this->ct);
    fprintf(this->file, "Connection: close\r\n");
    fprintf(this->file, "\r\n");
    
    return 0;
}

int HttpResponse::sendBody(){
    fprintf(this->file, "hello world\n");
    
    return 0;
}
