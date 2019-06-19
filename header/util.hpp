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
#include <stdlib.h>
#include <stdio.h>

int set_non_block( int fd );
char* substring(char* string, int position, int length);

#endif /* util_h */
