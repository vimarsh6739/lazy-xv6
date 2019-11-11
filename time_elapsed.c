#include "types.h"
#include "user.h"
#include "stat.h"

int main(void)
{
    uint x = get_ticks();
    int* a = (int*)malloc(sizeof(int)*1024*1024);
    uint y = get_ticks();
    printf(1,"Time taken to allocate the array is %d\n",y-x);
    //int i;
    x = get_ticks();
    a[0] = 1;
    y = get_ticks();
    printf(1,"Time taken to access Page 0 is %d\n",y-x);
    /*for(i = 55;i < 512*1024;i += 1024)
    {
        x = get_ticks();
        a[i] =1;
        y = get_ticks();
        printf(1,"Time taken to access index %d is %d\n",i,y-x);

        x = get_ticks();
        a[i+1] =1;
        y = get_ticks();
        printf(1,"Time taken to access index %d is %d\n",i+1,y-x);
    }*/
    exit();
}
