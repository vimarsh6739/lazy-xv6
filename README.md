# Course project for CS3500 (Operating Systems)
## About xv6
xv6 is a re-implementation of Dennis Ritchie's and Ken Thompson's Unix
Version 6 (v6). The main repository can be found [here](https://github.com/mit-pdos/xv6-public)

## Our Objective
Being lazy pays off!  
Jokes aside, the idea is to make memory/page allocation in xv6 *lazy*, or in other terms, allocate space only if it's accessed. 
This reduces the amount of space utilized by a process during runtime (by *not allocating* unutilized space)!

## Implementation
In a nutshell, we split the project is divided into 3 parts:  
1. Adding 2 syscalls to return the count of virtual and physical pages mapped to each process.
2. Modifying the `sbrk` syscall to not allocate any memory, but just return the modified size.
3. Handling the eventual page-faults in `trap.c` by allocating memory on encountering trap 13 (or `T_PGFLT`).
The location where the page fault occured is stored in the `rcr2` register.  

The programs can be benchmarked using the syscalls defined in 1.  
The programs `testprog.c` and `testprog2.c` attempt to do the same.
