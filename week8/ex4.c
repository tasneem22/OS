#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>


#define MB (1000*1000)

int main()
{
    int *arr = NULL; // I initialized it with NULL inorder to be able to always use realloc
    int  i;
    size_t sz = 0;
    struct rusage usage;



    printf("| User CPU time (usec) | System CPU time (usec) | Page faults (w/o I/O) | Page faults (w/ I/O) | Context switches |\n");
    for( i =0;i < 10;++i){
        sz+=MB;
        arr = (int *)realloc(arr , sz);// I use realloc to reallocate memory after adding 10MB at each iteration
        if(arr == NULL) // in order to segmentation fault (core dumped)
		{
			printf("Error occured!\n");
			exit(1);
		}

        memset(arr , 0 , sz);

        getrusage(RUSAGE_SELF, &usage);
        printf("| %20ld | %22ld | %21ld | %20ld | %16ld |\n",
			usage.ru_utime.tv_usec,
			usage.ru_stime.tv_usec,
			usage.ru_minflt,
			usage.ru_majflt,
			usage.ru_nvcsw + usage.ru_nivcsw
		);


        sleep(1);
    }
    free(arr);
    return 0;
}
