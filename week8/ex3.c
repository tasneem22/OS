#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MB (1024*1024)

int main()
{
    int *arr = NULL; // I initialized it with NULL inorder to be able to always use realloc
    int  i;
    size_t sz = 0;

    for( i =0; i < 10; ++i)
    {
        sz+=10*MB;
        arr = realloc(arr , sz);// I use realloc to reallocate memory after adding 10MB at each iteration
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
top - 04:08:55 up  3:51,  0 users,  load average: 0.52, 0.58, 0.59
Tasks:   9 total,   1 running,   4 sleeping,   4 stopped,   0 zombie
%Cpu(s):  8.5 us, 18.6 sy,  0.0 ni, 72.9 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
MiB Mem :   7129.1 total,    819.3 free,   6085.8 used,    224.0 buff/cache
MiB Swap:  21504.0 total,  20441.9 free,   1062.1 used.    912.7 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
    1 root      20   0    8936    316    272 S   0.0   0.0   0:00.25 init
    7 root      20   0    8936    224    176 S   0.0   0.0   0:00.01 init
    8 tasneem   20   0   18212   3832   3708 S   0.0   0.1   0:01.49 bash
  123 tasneem   20   0   17260   3052   1748 T   0.0   0.0   0:00.13 nano
  168 tasneem   20   0   18904   2064   1604 T   0.0   0.0   0:00.23 top
  219 tasneem   20   0   16748   2508   1716 T   0.0   0.0   0:00.30 nano
  247 tasneem   20   0   17404   3120   1752 T   0.0   0.0   0:00.13 nano
  313 tasneem   20   0   20780  10852    480 S   0.0   0.1   0:00.06 ex2
  314 tasneem   20   0   18772   2064   1504 R   0.0   0.0   0:00.04 top

top - 04:08:56 up  3:51,  0 users,  load average: 0.52, 0.58, 0.59
Tasks:   9 total,   1 running,   4 sleeping,   4 stopped,   0 zombie
%Cpu(s): 27.9 us, 20.1 sy,  0.0 ni, 50.7 id,  0.0 wa,  1.2 hi,  0.0 si,  0.0 st
MiB Mem :   7129.1 total,    819.3 free,   6085.8 used,    224.0 buff/cache
MiB Swap:  21504.0 total,  20441.9 free,   1062.1 used.    912.7 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
  313 tasneem   20   0   31020  21100    488 S   6.0   0.3   0:00.12 ex2
    1 root      20   0    8936    316    272 S   0.0   0.0   0:00.25 init
    7 root      20   0    8936    224    176 S   0.0   0.0   0:00.01 init
    8 tasneem   20   0   18212   3832   3708 S   0.0   0.1   0:01.49 bash
  123 tasneem   20   0   17260   3052   1748 T   0.0   0.0   0:00.13 nano
  168 tasneem   20   0   18904   2064   1604 T   0.0   0.0   0:00.23 top
  219 tasneem   20   0   16748   2508   1716 T   0.0   0.0   0:00.30 nano
  247 tasneem   20   0   17404   3120   1752 T   0.0   0.0   0:00.13 nano
  314 tasneem   20   0   18772   2140   1580 R   0.0   0.0   0:00.04 top

top - 04:08:57 up  3:51,  0 users,  load average: 0.52, 0.58, 0.59
Tasks:   9 total,   1 running,   4 sleeping,   4 stopped,   0 zombie
%Cpu(s): 16.4 us, 15.6 sy,  0.0 ni, 67.2 id,  0.0 wa,  0.7 hi,  0.0 si,  0.0 st
MiB Mem :   7129.1 total,    819.3 free,   6085.8 used,    224.0 buff/cache
MiB Swap:  21504.0 total,  20441.9 free,   1062.1 used.    912.7 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
  313 tasneem   20   0   41260  31340    488 S   5.9   0.4   0:00.18 ex2
    1 root      20   0    8936    316    272 S   0.0   0.0   0:00.25 init
    7 root      20   0    8936    224    176 S   0.0   0.0   0:00.01 init
    8 tasneem   20   0   18212   3832   3708 S   0.0   0.1   0:01.49 bash
  123 tasneem   20   0   17260   3052   1748 T   0.0   0.0   0:00.13 nano
  168 tasneem   20   0   18904   2064   1604 T   0.0   0.0   0:00.23 top
  219 tasneem   20   0   16748   2508   1716 T   0.0   0.0   0:00.30 nano
  247 tasneem   20   0   17404   3120   1752 T   0.0   0.0   0:00.13 nano
  314 tasneem   20   0   18772   2140   1580 R   0.0   0.0   0:00.04 top

top - 04:08:58 up  3:51,  0 users,  load average: 0.52, 0.58, 0.59
Tasks:   9 total,   2 running,   3 sleeping,   4 stopped,   0 zombie
%Cpu(s): 15.1 us, 10.3 sy,  0.0 ni, 74.0 id,  0.0 wa,  0.5 hi,  0.0 si,  0.0 st
MiB Mem :   7129.1 total,    775.8 free,   6129.3 used,    224.0 buff/cache
MiB Swap:  21504.0 total,  20441.9 free,   1062.1 used.    869.2 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
  313 tasneem   20   0   51500  31340    488 R   3.0   0.4   0:00.21 ex2
    1 root      20   0    8936    316    272 S   0.0   0.0   0:00.25 init
    7 root      20   0    8936    224    176 S   0.0   0.0   0:00.01 init
    8 tasneem   20   0   18212   3832   3708 S   0.0   0.1   0:01.49 bash
  123 tasneem   20   0   17260   3052   1748 T   0.0   0.0   0:00.13 nano
  168 tasneem   20   0   18904   2064   1604 T   0.0   0.0   0:00.23 top
  219 tasneem   20   0   16748   2508   1716 T   0.0   0.0   0:00.30 nano
  247 tasneem   20   0   17404   3120   1752 T   0.0   0.0   0:00.13 nano
  314 tasneem   20   0   18772   2140   1580 R   0.0   0.0   0:00.04 top

top - 04:08:59 up  3:51,  0 users,  load average: 0.52, 0.58, 0.59
Tasks:   9 total,   1 running,   4 sleeping,   4 stopped,   0 zombie
%Cpu(s): 11.7 us, 14.6 sy,  0.0 ni, 73.0 id,  0.0 wa,  0.7 hi,  0.0 si,  0.0 st
MiB Mem :   7129.1 total,    775.8 free,   6129.3 used,    224.0 buff/cache
MiB Swap:  21504.0 total,  20441.9 free,   1062.1 used.    869.2 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
  313 tasneem   20   0   51500  41580    488 S   8.0   0.6   0:00.29 ex2
    1 root      20   0    8936    316    272 S   0.0   0.0   0:00.25 init
    7 root      20   0    8936    224    176 S   0.0   0.0   0:00.01 init
    8 tasneem   20   0   18212   3832   3708 S   0.0   0.1   0:01.49 bash
  123 tasneem   20   0   17260   3052   1748 T   0.0   0.0   0:00.13 nano
  168 tasneem   20   0   18904   2064   1604 T   0.0   0.0   0:00.23 top
  219 tasneem   20   0   16748   2508   1716 T   0.0   0.0   0:00.30 nano
  247 tasneem   20   0   17404   3120   1752 T   0.0   0.0   0:00.13 nano
  314 tasneem   20   0   18772   2140   1580 R   0.0   0.0   0:00.04 top

top - 04:09:00 up  3:51,  0 users,  load average: 0.52, 0.58, 0.59
Tasks:   9 total,   1 running,   4 sleeping,   4 stopped,   0 zombie
%Cpu(s): 13.5 us,  5.7 sy,  0.0 ni, 80.3 id,  0.0 wa,  0.5 hi,  0.0 si,  0.0 st
MiB Mem :   7129.1 total,    775.8 free,   6129.3 used,    224.0 buff/cache
MiB Swap:  21504.0 total,  20441.9 free,   1062.1 used.    869.2 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
  313 tasneem   20   0   61740  51820    488 S   6.0   0.7   0:00.35 ex2
    1 root      20   0    8936    316    272 S   0.0   0.0   0:00.25 init
    7 root      20   0    8936    224    176 S   0.0   0.0   0:00.01 init
    8 tasneem   20   0   18212   3832   3708 S   0.0   0.1   0:01.49 bash
  123 tasneem   20   0   17260   3052   1748 T   0.0   0.0   0:00.13 nano
  168 tasneem   20   0   18904   2064   1604 T   0.0   0.0   0:00.23 top
  219 tasneem   20   0   16748   2508   1716 T   0.0   0.0   0:00.30 nano
  247 tasneem   20   0   17404   3120   1752 T   0.0   0.0   0:00.13 nano
  314 tasneem   20   0   18772   2140   1580 R   0.0   0.0   0:00.04 top

top - 04:09:01 up  3:51,  0 users,  load average: 0.52, 0.58, 0.59
Tasks:   9 total,   1 running,   4 sleeping,   4 stopped,   0 zombie
%Cpu(s): 15.2 us, 13.2 sy,  0.0 ni, 71.4 id,  0.0 wa,  0.2 hi,  0.0 si,  0.0 st
MiB Mem :   7129.1 total,    774.2 free,   6130.9 used,    224.0 buff/cache
MiB Swap:  21504.0 total,  20441.9 free,   1062.1 used.    867.6 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
  313 tasneem   20   0   71980  62060    488 S   6.0   0.9   0:00.41 ex2
    1 root      20   0    8936    316    272 S   0.0   0.0   0:00.25 init
    7 root      20   0    8936    224    176 S   0.0   0.0   0:00.01 init
    8 tasneem   20   0   18212   3832   3708 S   0.0   0.1   0:01.49 bash
  123 tasneem   20   0   17260   3052   1748 T   0.0   0.0   0:00.13 nano
  168 tasneem   20   0   18904   2064   1604 T   0.0   0.0   0:00.23 top
  219 tasneem   20   0   16748   2508   1716 T   0.0   0.0   0:00.30 nano
  247 tasneem   20   0   17404   3120   1752 T   0.0   0.0   0:00.13 nano
  314 tasneem   20   0   18772   2140   1580 R   0.0   0.0   0:00.04 top

top - 04:09:02 up  3:51,  0 users,  load average: 0.52, 0.58, 0.59
Tasks:   9 total,   1 running,   4 sleeping,   4 stopped,   0 zombie
%Cpu(s): 18.0 us, 10.8 sy,  0.0 ni, 70.4 id,  0.0 wa,  0.7 hi,  0.0 si,  0.0 st
MiB Mem :   7129.1 total,    774.2 free,   6130.9 used,    224.0 buff/cache
MiB Swap:  21504.0 total,  20441.9 free,   1062.1 used.    867.6 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
  313 tasneem   20   0   82220  72300    488 S  10.0   1.0   0:00.51 ex2
    1 root      20   0    8936    316    272 S   0.0   0.0   0:00.25 init
    7 root      20   0    8936    224    176 S   0.0   0.0   0:00.01 init
    8 tasneem   20   0   18212   3832   3708 S   0.0   0.1   0:01.49 bash
  123 tasneem   20   0   17260   3052   1748 T   0.0   0.0   0:00.13 nano
  168 tasneem   20   0   18904   2064   1604 T   0.0   0.0   0:00.23 top
  219 tasneem   20   0   16748   2508   1716 T   0.0   0.0   0:00.30 nano
  247 tasneem   20   0   17404   3120   1752 T   0.0   0.0   0:00.13 nano
  314 tasneem   20   0   18772   2140   1580 R   0.0   0.0   0:00.04 top

top - 04:09:03 up  3:51,  0 users,  load average: 0.52, 0.58, 0.59
Tasks:   9 total,   1 running,   4 sleeping,   4 stopped,   0 zombie
%Cpu(s): 17.5 us, 18.8 sy,  0.0 ni, 63.2 id,  0.0 wa,  0.5 hi,  0.0 si,  0.0 st
MiB Mem :   7129.1 total,    774.2 free,   6130.9 used,    224.0 buff/cache
MiB Swap:  21504.0 total,  20441.9 free,   1062.1 used.    867.6 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
  313 tasneem   20   0   92460  82540    488 S  24.0   1.1   0:00.75 ex2
  314 tasneem   20   0   18772   2140   1580 R   2.0   0.0   0:00.06 top
    1 root      20   0    8936    316    272 S   0.0   0.0   0:00.25 init
    7 root      20   0    8936    224    176 S   0.0   0.0   0:00.01 init
    8 tasneem   20   0   18212   3832   3708 S   0.0   0.1   0:01.49 bash
  123 tasneem   20   0   17260   3052   1748 T   0.0   0.0   0:00.13 nano
  168 tasneem   20   0   18904   2064   1604 T   0.0   0.0   0:00.23 top
  219 tasneem   20   0   16748   2508   1716 T   0.0   0.0   0:00.30 nano
  247 tasneem   20   0   17404   3120   1752 T   0.0   0.0   0:00.13 nano

top - 04:09:04 up  3:51,  0 users,  load average: 0.52, 0.58, 0.59
Tasks:   9 total,   1 running,   4 sleeping,   4 stopped,   0 zombie
%Cpu(s): 17.4 us,  9.8 sy,  0.0 ni, 72.5 id,  0.0 wa,  0.2 hi,  0.0 si,  0.0 st
MiB Mem :   7129.1 total,    737.2 free,   6168.0 used,    224.0 buff/cache
MiB Swap:  21504.0 total,  20441.9 free,   1062.1 used.    830.6 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
  313 tasneem   20   0  102700  92780    488 S  10.0   1.3   0:00.85 ex2
    1 root      20   0    8936    316    272 S   0.0   0.0   0:00.25 init
    7 root      20   0    8936    224    176 S   0.0   0.0   0:00.01 init
    8 tasneem   20   0   18212   3832   3708 S   0.0   0.1   0:01.49 bash
  123 tasneem   20   0   17260   3052   1748 T   0.0   0.0   0:00.13 nano
  168 tasneem   20   0   18904   2064   1604 T   0.0   0.0   0:00.23 top
  219 tasneem   20   0   16748   2508   1716 T   0.0   0.0   0:00.30 nano
  247 tasneem   20   0   17404   3120   1752 T   0.0   0.0   0:00.13 nano
  314 tasneem   20   0   18772   2140   1580 R   0.0   0.0   0:00.06 top

top - 04:09:05 up  3:51,  0 users,  load average: 0.52, 0.58, 0.59
Tasks:   9 total,   1 running,   4 sleeping,   4 stopped,   0 zombie
%Cpu(s): 12.8 us,  9.3 sy,  0.0 ni, 77.9 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
MiB Mem :   7129.1 total,    737.2 free,   6168.0 used,    224.0 buff/cache
MiB Swap:  21504.0 total,  20441.9 free,   1062.1 used.    830.6 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
  313 tasneem   20   0  112940 103020    488 S  10.0   1.4   0:00.95 ex2
    1 root      20   0    8936    316    272 S   0.0   0.0   0:00.25 init
    7 root      20   0    8936    224    176 S   0.0   0.0   0:00.01 init
    8 tasneem   20   0   18212   3832   3708 S   0.0   0.1   0:01.49 bash
  123 tasneem   20   0   17260   3052   1748 T   0.0   0.0   0:00.13 nano
  168 tasneem   20   0   18904   2064   1604 T   0.0   0.0   0:00.23 top
  219 tasneem   20   0   16748   2508   1716 T   0.0   0.0   0:00.30 nano
  247 tasneem   20   0   17404   3120   1752 T   0.0   0.0   0:00.13 nano
  314 tasneem   20   0   18772   2140   1580 R   0.0   0.0   0:00.06 top

top - 04:09:06 up  3:51,  0 users,  load average: 0.52, 0.58, 0.59
Tasks:   8 total,   1 running,   3 sleeping,   4 stopped,   0 zombie
%Cpu(s): 14.1 us, 16.1 sy,  0.0 ni, 68.9 id,  0.0 wa,  1.0 hi,  0.0 si,  0.0 st
MiB Mem :   7129.1 total,    737.2 free,   6168.0 used,    224.0 buff/cache
MiB Swap:  21504.0 total,  20441.9 free,   1062.1 used.    830.6 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
  314 tasneem   20   0   18772   2140   1580 R   1.0   0.0   0:00.07 top
    1 root      20   0    8936    316    272 S   0.0   0.0   0:00.25 init
    7 root      20   0    8936    224    176 S   0.0   0.0   0:00.01 init
    8 tasneem   20   0   18212   3832   3700 S   0.0   0.1   0:01.49 bash
  123 tasneem   20   0   17260   3052   1748 T   0.0   0.0   0:00.13 nano
  168 tasneem   20   0   18904   2064   1604 T   0.0   0.0   0:00.23 top
  219 tasneem   20   0   16748   2508   1716 T   0.0   0.0   0:00.30 nano
  247 tasneem   20   0   17404   3120   1752 T   0.0   0.0   0:00.13 nano

*/
