//
//  Response.hpp
//  httpServer
//
//  Created by Ows on 6/19/19.
//  Copyright © 2019 hieunq. All rights reserved.
//

#ifndef Response_hpp
#define Response_hpp

class Response{
    char* status;
    int statusCode;
    
public:
    Response();
    char *res();
};

#endif /* Response_hpp */
