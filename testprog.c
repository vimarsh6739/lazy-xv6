#include "types.h"
#include "stat.h"
#include "user.h"
int
main(int argc, char *argv[])
{
  int i;i = count_virtual_pages();
  int j;j = count_physical_pages();
  printf(1, "Count of virtual pages is %d\n", i);
  printf(1, "Count of physical pages is %d\n", j);
  exit();
}
