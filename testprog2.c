#include "types.h"
#include "user.h"
#include "stat.h"

int main(void)
{
    uint x = uptime();
    char* a = malloc(1024*1024*10);
    a[0] = 1;
    int i;
    uint y = 1024*1024*10;
    for(i = 1024;i < y;i+=1024)
    {
    	a[i] = 1;
    }
    y = uptime();
    printf(1,"The time taken for 10240 page accesses in the JIT scheme is %d\n",y-x);
    exit();
}
