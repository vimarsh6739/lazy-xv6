#include "types.h"
#include "stat.h"
#include "user.h"
int
main(int argc, char *argv[])
{
  char* arr = (char*)malloc(4096*1000);
  int i;i = count_virtual_pages();
  
  arr[0] = 'a';
  arr[5000] = 'a';
  arr[10000] = 'a';

  int j;j = count_physical_pages();
  printf(1, "Count of virtual pages is %d\n", i);
  printf(1, "Count of physical pages is %d\n", j);
  exit();
}
