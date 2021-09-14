#include "types.h"
#include "x86.h"
#include "defs.h"
#include "param.h"
#include "mmu.h"
#include "proc.h"
#include "sysfunc.h"

int counter = 0; // Increments after getPID
int counterB =0; //Increments after every system call

int
sys_fork(void)
{
  counterB++;
  return fork();
}

int
sys_exit(void)
{
  counterB++;
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  counterB++;
  return wait();
}

int
sys_kill(void)
{
  counterB++;
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  counterB++;
  counter++;
  return proc->pid;
}

int
sys_partACount(void)
{
  counterB++;
  return counter;
}

int
sys_partBCount(void)
{
  counterB++;
  return counterB;
}

int
sys_sbrk(void)
{
  counterB++;
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = proc->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  counterB++;
  int n;
  uint ticks0;
  
  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(proc->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since boot.
int
sys_uptime(void)
{
  counterB++;
  uint xticks;
  
  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
