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

// CAN'T RUN vmstat 1 COMMAND because I use Windows
