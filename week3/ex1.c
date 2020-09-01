#include <stdio.h>
int main(){
    int* pc;
    int c;
    c=22;
    printf("Address of c:%p\n",&c);///there were an error here
    printf("Value of c:%d\n\n",c);
    pc=&c;
    printf("Address of pointer pc:%p\n",pc);///there were an error here
    printf("Content of pointer pc:%d\n\n",*pc);
    c=11;
    printf("Address of pointer pc:%p\n",pc);///there were an error here
    printf("Content of pointer pc:%d\n\n",*pc);
    *pc=2;
    printf("Address of c:%p\n",&c);///there were an error here
    printf("Value of c:%d\n\n",c);
return 0;
}
