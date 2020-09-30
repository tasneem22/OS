#include <stdio.h>
#include <stdlib.h>
#include <string.h>			// for memcpy()

#define min(a, b) ( ((a) < (b)) ? (a) : (b) )

/**
  * The extra parameter (old_sz) does not exist in the standard realloc,
  *  but the standard realloc uses platform-dependent functionality.
  * This parameter was introduced to make the function as general and platform-independent as possible
  */
void* my_realloc(void *ptr, size_t new_sz, size_t old_sz)
{
    // size = 0 means calling free()
    if(new_sz == 0)
    {
        free(ptr);
        return NULL;
    }

    // given NULL, means same behavior as malloc()
    if(ptr == NULL)
        return malloc(new_sz);

    void *new_ptr = malloc(new_sz);
    if(new_ptr == NULL)
        return NULL;

    // copy the data
    size_t min_sz = min(old_sz, new_sz);
    memcpy(new_ptr, ptr, min_sz);

    // free initial pointer
    free(ptr);

    return new_ptr;
}

void print_array(int *arr, int sz)
{
    if(arr == NULL)
        return;
    int i=0;
    for(i=0; i<sz-1; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int sz = 10, old_sz , i;
    // Allocating space for for 10 integers
    int *arr = (int*)my_realloc(NULL, sz*sizeof(int), 0);
    for(i=0; i<sz; i++)
        arr[i] = i;
    printf("the Array values are:\n");
    print_array(arr, sz);

    //in order to Increase size
    old_sz = sz;
    sz = 10;
    //Resizing the array to make its size 10 (without initialization)
    arr = (int*)my_realloc(arr, sz*sizeof(int), old_sz*sizeof(int));
    printf("the new Array values are:\n");
    print_array(arr, sz);

    //in order to Decrease size
    old_sz = sz;
    sz = 2;
    //Resizing the array to make its size 2 (without initialization)
    arr = (int*)my_realloc(arr, sz*sizeof(int), old_sz*sizeof(int));
    printf("the new Array values are:\n");
    print_array(arr, sz);

    // Free the array
    printf("Pointer before freeing: %p\n", arr);
    //Freeing the array
    arr = (int*)my_realloc(arr, 0, 0);
    printf("Pointer after freeing: %p\n", arr);

    return 0;
}
