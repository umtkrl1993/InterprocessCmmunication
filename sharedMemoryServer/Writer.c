



/*
 * shm-client - client program to demonstrate shared memory.
 */

#include "Writer.h"
#define SHMSZ     27

void writeDataToSharedMemory( const char* dataToWrite )
{
  	char c;
    int shmid;
    key_t key;
    char *shm, *s;

    key = 5678;

    
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) 
    {
        perror("shmget");
        exit(1);
    }

     
        if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) 
        {
            perror("shmat");
            exit(1);
        }   
    

    s = shm;

    while ( *dataToWrite != '\n' )
    { 
    *s = *dataToWrite;
     dataToWrite++;
     s++;
	}
	*s = NULL;
    /*
     * Finally, we wait until the other process 
     * changes the first character of our memory
     * to '*', indicating that it has read what 
     * we put there.
     */
    while (*shm != '*')
        sleep(1);

    exit(0);
}