//
//  util.cpp
//  httpServer
//
//  Created by Ows on 6/19/19.
//  Copyright © 2019 hieunq. All rights reserved.
//

#include "../header/util.hpp"

int set_non_block(int fd){
    // get flags
    int r = 0;
    do
        r = fcntl( fd, F_GETFL, O_NONBLOCK );
    while ( r == -1 && errno == EINTR );
    if ( r == -1 )
        return -errno;
    
    // already non blocking ?
    if ( r & O_NONBLOCK )
        return 0;
    
    // update flags
    int flags = r | O_NONBLOCK;
    do
        r = fcntl( fd, F_SETFL, flags );
    while ( r == -1 && errno == EINTR );
    
    return r ? -errno : 0;
}

char* substring(char* string, int position, int length){
    char *pointer;
    int c;
    
    pointer = (char*)malloc(length+1);
    
    if (pointer == NULL)
    {
        printf("Unable to allocate memory.\n");
        return nullptr;
    }
    
    for (c = 0 ; c < length ; c++)
    {
        *(pointer+c) = *(string+position-1);
        string++;
    }
    
    *(pointer+c) = '\0';
    
    return pointer;
}
