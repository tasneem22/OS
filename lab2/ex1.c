#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>
int main()
{
   int integer = INT_MAX;
   float f = FLT_MAX;
   double d = DBL_MAX;
   printf("size of the integer is %lu , and it's Max value is %d\n" , sizeof(integer) , integer);

   printf("size of the integer is %lu , and it's Max value is %f\n" , sizeof(f) , f);

   printf("size of the integer is %lu , and it's Max value is %lf\n" , sizeof(d) , d);
    return 0;
}
