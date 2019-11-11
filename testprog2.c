#include "types.h"
#include "user.h"
#include "stat.h"

int main(void)
{
    uint x = uptime();
    char* a = malloc(4096*1024*10);
    uint y = uptime();
    printf(1,"Time taken to allocate the array is %d\n",y-x);
 	
    x = uptime();
    a[45000] = 65;
    y = uptime();
    printf(1,"Time taken to access Page 11 is %d\n",y-x);

   exit();
}
