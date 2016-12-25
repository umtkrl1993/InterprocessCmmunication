#ifndef _Writer_H
#define _Writer_H
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void writeDataToSharedMemory( const char* );


#endif