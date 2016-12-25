#include "WriteToSharedData.h"
int main()
{
    
   const char *data = "umit aykurt shared memory test";

   writeDataToSharedMemory(data);

   return 0;
}
