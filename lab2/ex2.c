#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
  char* s;
  scanf("%s",s);

  size_t len = strlen(s);
  char r[len+1];
  r[len] = '\0';
  int i;
  for(i = 0; i < len; i++){
    r[i] = s[len - 1 - i];
  }
  printf("Reversed String: %s\n", r);
    return 0;
}
