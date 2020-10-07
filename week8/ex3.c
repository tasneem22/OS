#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>



#define MB (1000*1000)

int main()
{
    int *arr = NULL; // I initialized it with NULL inorder to be able to always use realloc
    int  i;
    size_t sz = 0;
    for( i =0;i < 10;++i){
        sz+=MB;
        arr = (int *)realloc(arr , sz);// I use realloc to reallocate memory after adding 10MB at each iteration
        if(arr == NULL) // in order to segmentation fault (core dumped)
		{
			printf("Error occured!\n");
			exit(1);
		}

        memset(arr , 0 , sz);
        sleep(1);
    }
    free(arr);
    return 0;
}
/*
top - 03:18:44 up  3:01,  0 users,  load average: 0.52, 0.58, 0.59
Tasks:   8 total,   1 running,   4 sleeping,   3 stopped,   0 zombie
%Cpu(s): 17.7 us, 25.8 sy,  0.0 ni, 56.5 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
MiB Mem :   7129.1 total,    511.2 free,   6394.0 used,    224.0 buff/cache
MiB Swap:  21504.0 total,  20616.0 free,    888.0 used.    604.5 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
    1 root      20   0    8936    316    272 S   0.0   0.0   0:00.25 init
    7 root      20   0    8936    224    176 S   0.0   0.0   0:00.01 init
    8 tasneem   20   0   18212   3832   3704 S   0.0   0.1   0:01.29 bash
  123 tasneem   20   0   17260   3052   1592 T   0.0   0.0   0:00.13 nano
  168 tasneem   20   0   18904   2064   1604 T   0.0   0.0   0:00.23 top
  219 tasneem   20   0   16748   2568   1560 T   0.0   0.0   0:00.30 nano
  231 tasneem   20   0   11516   1484    376 S   0.0   0.0   0:00.01 ex2
  232 tasneem   20   0   18772   2064   1504 R   0.0   0.0   0:00.09 top

top - 03:18:45 up  3:01,  0 users,  load average: 0.52, 0.58, 0.59
Tasks:   8 total,   1 running,   4 sleeping,   3 stopped,   0 zombie
%Cpu(s): 17.2 us, 17.9 sy,  0.0 ni, 62.8 id,  0.0 wa,  2.1 hi,  0.0 si,  0.0 st
MiB Mem :   7129.1 total,    511.2 free,   6394.0 used,    224.0 buff/cache
MiB Swap:  21504.0 total,  20616.0 free,    888.0 used.    604.5 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
  231 tasneem   20   0   12492   2468    384 S   2.0   0.0   0:00.03 ex2
  232 tasneem   20   0   18772   2140   1580 R   1.0   0.0   0:00.10 top
    1 root      20   0    8936    316    272 S   0.0   0.0   0:00.25 init
    7 root      20   0    8936    224    176 S   0.0   0.0   0:00.01 init
    8 tasneem   20   0   18212   3832   3704 S   0.0   0.1   0:01.29 bash
  123 tasneem   20   0   17260   3052   1592 T   0.0   0.0   0:00.13 nano
  168 tasneem   20   0   18904   2064   1604 T   0.0   0.0   0:00.23 top
  219 tasneem   20   0   16748   2568   1560 T   0.0   0.0   0:00.30 nano

top - 03:18:46 up  3:01,  0 users,  load average: 0.52, 0.58, 0.59
Tasks:   8 total,   1 running,   4 sleeping,   3 stopped,   0 zombie
%Cpu(s): 17.1 us,  5.0 sy,  0.0 ni, 77.8 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
MiB Mem :   7129.1 total,    511.2 free,   6394.0 used,    224.0 buff/cache
MiB Swap:  21504.0 total,  20616.0 free,    888.0 used.    604.5 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
    1 root      20   0    8936    316    272 S   0.0   0.0   0:00.25 init
    7 root      20   0    8936    224    176 S   0.0   0.0   0:00.01 init
    8 tasneem   20   0   18212   3832   3704 S   0.0   0.1   0:01.29 bash
  123 tasneem   20   0   17260   3052   1592 T   0.0   0.0   0:00.13 nano
  168 tasneem   20   0   18904   2064   1604 T   0.0   0.0   0:00.23 top
  219 tasneem   20   0   16748   2568   1560 T   0.0   0.0   0:00.30 nano
  231 tasneem   20   0   13468   3444    384 S   0.0   0.0   0:00.03 ex2
  232 tasneem   20   0   18772   2140   1580 R   0.0   0.0   0:00.10 top

top - 03:18:47 up  3:01,  0 users,  load average: 0.52, 0.58, 0.59
Tasks:   8 total,   1 running,   4 sleeping,   3 stopped,   0 zombie
%Cpu(s): 13.2 us, 10.9 sy,  0.0 ni, 75.6 id,  0.0 wa,  0.2 hi,  0.0 si,  0.0 st
MiB Mem :   7129.1 total,    502.1 free,   6403.0 used,    224.0 buff/cache
MiB Swap:  21504.0 total,  20616.0 free,    888.0 used.    595.5 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
  231 tasneem   20   0   14444   4420    384 S   1.0   0.1   0:00.04 ex2
    1 root      20   0    8936    316    272 S   0.0   0.0   0:00.25 init
    7 root      20   0    8936    224    176 S   0.0   0.0   0:00.01 init
    8 tasneem   20   0   18212   3832   3704 S   0.0   0.1   0:01.29 bash
  123 tasneem   20   0   17260   3052   1592 T   0.0   0.0   0:00.13 nano
  168 tasneem   20   0   18904   2064   1604 T   0.0   0.0   0:00.23 top
  219 tasneem   20   0   16748   2568   1560 T   0.0   0.0   0:00.30 nano
  232 tasneem   20   0   18772   2140   1580 R   0.0   0.0   0:00.10 top

top - 03:18:48 up  3:01,  0 users,  load average: 0.52, 0.58, 0.59
Tasks:   8 total,   1 running,   4 sleeping,   3 stopped,   0 zombie
%Cpu(s): 27.4 us, 20.5 sy,  0.0 ni, 51.3 id,  0.0 wa,  0.7 hi,  0.0 si,  0.0 st
MiB Mem :   7129.1 total,    502.1 free,   6403.0 used,    224.0 buff/cache
MiB Swap:  21504.0 total,  20616.0 free,    888.0 used.    595.5 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
    1 root      20   0    8936    316    272 S   0.0   0.0   0:00.25 init
    7 root      20   0    8936    224    176 S   0.0   0.0   0:00.01 init
    8 tasneem   20   0   18212   3832   3704 S   0.0   0.1   0:01.29 bash
  123 tasneem   20   0   17260   3052   1592 T   0.0   0.0   0:00.13 nano
  168 tasneem   20   0   18904   2064   1604 T   0.0   0.0   0:00.23 top
  219 tasneem   20   0   16748   2568   1560 T   0.0   0.0   0:00.30 nano
  231 tasneem   20   0   15420   5396    384 S   0.0   0.1   0:00.04 ex2
  232 tasneem   20   0   18772   2140   1580 R   0.0   0.0   0:00.10 top

top - 03:18:49 up  3:01,  0 users,  load average: 0.52, 0.58, 0.59
Tasks:   8 total,   1 running,   4 sleeping,   3 stopped,   0 zombie
%Cpu(s): 16.3 us, 17.1 sy,  0.0 ni, 66.1 id,  0.0 wa,  0.5 hi,  0.0 si,  0.0 st
MiB Mem :   7129.1 total,    502.1 free,   6403.0 used,    224.0 buff/cache
MiB Swap:  21504.0 total,  20616.0 free,    888.0 used.    595.5 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
  232 tasneem   20   0   18772   2140   1580 R   2.0   0.0   0:00.12 top
    1 root      20   0    8936    316    272 S   0.0   0.0   0:00.25 init
    7 root      20   0    8936    224    176 S   0.0   0.0   0:00.01 init
    8 tasneem   20   0   18212   3832   3704 S   0.0   0.1   0:01.29 bash
  123 tasneem   20   0   17260   3052   1592 T   0.0   0.0   0:00.13 nano
  168 tasneem   20   0   18904   2064   1604 T   0.0   0.0   0:00.23 top
  219 tasneem   20   0   16748   2568   1560 T   0.0   0.0   0:00.30 nano
  231 tasneem   20   0   16396   6372    384 S   0.0   0.1   0:00.04 ex2

top - 03:18:50 up  3:01,  0 users,  load average: 0.52, 0.58, 0.59
Tasks:   8 total,   1 running,   4 sleeping,   3 stopped,   0 zombie
%Cpu(s): 17.3 us, 13.8 sy,  0.0 ni, 68.6 id,  0.0 wa,  0.2 hi,  0.0 si,  0.0 st
MiB Mem :   7129.1 total,    477.5 free,   6427.6 used,    224.0 buff/cache
MiB Swap:  21504.0 total,  20616.0 free,    888.0 used.    570.9 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
  231 tasneem   20   0   17372   7348    384 S   2.0   0.1   0:00.06 ex2
    1 root      20   0    8936    316    272 S   0.0   0.0   0:00.25 init
    7 root      20   0    8936    224    176 S   0.0   0.0   0:00.01 init
    8 tasneem   20   0   18212   3832   3704 S   0.0   0.1   0:01.29 bash
  123 tasneem   20   0   17260   3052   1592 T   0.0   0.0   0:00.13 nano
  168 tasneem   20   0   18904   2064   1604 T   0.0   0.0   0:00.23 top
  219 tasneem   20   0   16748   2568   1560 T   0.0   0.0   0:00.30 nano
  232 tasneem   20   0   18772   2140   1580 R   0.0   0.0   0:00.12 top

top - 03:18:51 up  3:01,  0 users,  load average: 0.52, 0.58, 0.59
Tasks:   8 total,   1 running,   4 sleeping,   3 stopped,   0 zombie
%Cpu(s): 14.2 us, 15.0 sy,  0.0 ni, 70.3 id,  0.0 wa,  0.5 hi,  0.0 si,  0.0 st
MiB Mem :   7129.1 total,    477.5 free,   6427.6 used,    224.0 buff/cache
MiB Swap:  21504.0 total,  20616.0 free,    888.0 used.    570.9 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
  231 tasneem   20   0   18352   8328    384 S   1.0   0.1   0:00.07 ex2
    1 root      20   0    8936    316    272 S   0.0   0.0   0:00.25 init
    7 root      20   0    8936    224    176 S   0.0   0.0   0:00.01 init
    8 tasneem   20   0   18212   3832   3704 S   0.0   0.1   0:01.29 bash
  123 tasneem   20   0   17260   3052   1592 T   0.0   0.0   0:00.13 nano
  168 tasneem   20   0   18904   2064   1604 T   0.0   0.0   0:00.23 top
  219 tasneem   20   0   16748   2568   1560 T   0.0   0.0   0:00.30 nano
  232 tasneem   20   0   18772   2140   1580 R   0.0   0.0   0:00.12 top

top - 03:18:53 up  3:01,  0 users,  load average: 0.52, 0.58, 0.59
Tasks:   8 total,   1 running,   4 sleeping,   3 stopped,   0 zombie
%Cpu(s): 20.0 us, 16.4 sy,  0.0 ni, 62.9 id,  0.0 wa,  0.7 hi,  0.0 si,  0.0 st
MiB Mem :   7129.1 total,    476.0 free,   6429.1 used,    224.0 buff/cache
MiB Swap:  21504.0 total,  20616.0 free,    888.0 used.    569.4 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
  231 tasneem   20   0   19328   9304    384 S   1.0   0.1   0:00.08 ex2
    1 root      20   0    8936    316    272 S   0.0   0.0   0:00.25 init
    7 root      20   0    8936    224    176 S   0.0   0.0   0:00.01 init
    8 tasneem   20   0   18212   3832   3704 S   0.0   0.1   0:01.29 bash
  123 tasneem   20   0   17260   3052   1592 T   0.0   0.0   0:00.13 nano
  168 tasneem   20   0   18904   2064   1604 T   0.0   0.0   0:00.23 top
  219 tasneem   20   0   16748   2568   1560 T   0.0   0.0   0:00.30 nano
  232 tasneem   20   0   18772   2140   1580 R   0.0   0.0   0:00.12 top

top - 03:18:54 up  3:01,  0 users,  load average: 0.52, 0.58, 0.59
Tasks:   8 total,   1 running,   4 sleeping,   3 stopped,   0 zombie
%Cpu(s): 38.6 us, 16.1 sy,  0.0 ni, 45.2 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
MiB Mem :   7129.1 total,    476.0 free,   6429.1 used,    224.0 buff/cache
MiB Swap:  21504.0 total,  20616.0 free,    888.0 used.    569.4 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
    1 root      20   0    8936    316    272 S   0.0   0.0   0:00.25 init
    7 root      20   0    8936    224    176 S   0.0   0.0   0:00.01 init
    8 tasneem   20   0   18212   3832   3704 S   0.0   0.1   0:01.29 bash
  123 tasneem   20   0   17260   3052   1592 T   0.0   0.0   0:00.13 nano
  168 tasneem   20   0   18904   2064   1604 T   0.0   0.0   0:00.23 top
  219 tasneem   20   0   16748   2568   1560 T   0.0   0.0   0:00.30 nano
  231 tasneem   20   0   20304  10280    384 S   0.0   0.1   0:00.08 ex2
  232 tasneem   20   0   18772   2140   1580 R   0.0   0.0   0:00.12 top

*/
