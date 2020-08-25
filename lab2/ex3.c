#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int n,i,k = 0, space;
  //n=3;
  sscanf (argv[1],"%d", &n);

  for (i = 1; i <= n; ++i, k = 0) {
      for (space = 1; space <= n - i; ++space) {
         printf("  ");
      }
      while (k != 2 * i - 1) {
         printf("* ");
         ++k;
      }
      printf("\n");
   }
}
