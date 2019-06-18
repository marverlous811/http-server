//
//  util.h
//  httpServer
//
//  Created by Ows on 6/16/19.
//  Copyright © 2019 hieunq. All rights reserved.
//

#ifndef util_h
#define util_h

#include <fcntl.h>
#include <errno.h>

int set_non_block( int fd ) {
    // get flags
    int r;
    do
        r = fcntl( fd, F_GETFL );
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


#endif /* util_h */
