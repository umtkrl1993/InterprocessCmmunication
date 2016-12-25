/*
 * shm-client - client program to demonstrate shared memory.
 */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SHMSZ     27
#include "ReadFromSharedMemory.h"

int main()
{
    char* data = new char[10];
    readDataFromSharedMemory( data );
    //printf( "read data is %s\n", data );

    return 0;
}
