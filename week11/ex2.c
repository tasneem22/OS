#include <stdio.h>
#include <unistd.h>

#define SIZE 12

int main()
{
	char text[SIZE+1] = "HELLO WORLD\n";
	
	setvbuf(stdout, NULL, _IOLBF, BUFSIZ);
	
	for(int i=0; i<SIZE; i++)
	{
		printf("%c", text[i]);
		sleep(1);
	}
	return 0;
}
