#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swaap(int *a ,int *b){
    int temp = *a;
   *a = *b;
    *b = temp;
    return ;
}
int main()
{
  int a ,b;
  scanf("%d%d",&a,&b);
  swaap(&a,&b);
  printf("%d %d",a,b);
}
