#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_count_virtual_pages(void)
{
  uint vsize;
  vsize = myproc()->sz;
  vsize = vsize/PGSIZE;
  return vsize;
}

int sys_count_physical_pages(void)
{
  struct proc *curproc = myproc();
  pde_t *pgdir = curproc->pgdir;
  pde_t *pde;
  pte_t *pgtab;

  int j;
  int cnt;
  cnt=0;
  pde = &pgdir[0];
  if(*pde & PTE_P){
    pgtab = (pte_t*)P2V(PTE_ADDR(*pde));
    for(j=0;j<NPTENTRIES;++j){
      if(*(pgtab+j) & PTE_P){
        cnt++;
      }
    }
  }  

  

  //pde_t *pde;
  //pte_t *pgtab;
  //cprintf("Directory is %p",*pg_dir);
  //int i;//int j;//int cnt;cnt=0;

  //for(i=0;i<1;++i){
    //pde = &pgdir[i];
    //if(dir_base[i] & (PTE_P | PTE_U) ){
      // cprintf("Directory %d --> %p --> ",i,dir_base[i]);
      // pgtab = (pte_t*)P2V(PTE_ADDR(dir_base[i]));
      //for(j=0;j<NPTENTRIES;++j){
      //  if(pgtab[j] & (PTE_P|PTE_U)){
      //    cnt++;
      //  }
      // cprintf("%p \n",*pgtab);
      //}
    //}
  //}
  //returns count of all current physical pages
  return cnt;
}