#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

#define SIZE 19

int main()
{
	int file = open("ex1.txt", O_RDWR | O_CREAT, (mode_t)0600);
	
	
	char text[SIZE] = "test";
	
	printf("Writing the string \"%s\" to file ex1.txt\n", text);
	
	// stretch the file to the size of the string
	if(lseek(file, SIZE-1, SEEK_SET) == -1)
	{
		close(file);
		printf("Error calling lseek\n");
		return 2;
	}
	
	// need to write anything to actually get the file to the new size
	if(write(file, "", 1) == -1)
	{
		close(file);
		printf("Error writing last byte to file\n");
		return 3;
	}
	
	char *map = mmap(0, SIZE-1, PROT_READ | PROT_WRITE, MAP_SHARED, file, 0);
	if(map == MAP_FAILED)
	{
		close(file);
		printf("Error mapping the file\n");
		return 4;
	}
	
	// copy from string to the map
	memcpy(map, text, SIZE-1);
	
	// write to disk
	if(msync(map, SIZE-1, MS_SYNC) == -1)
	{
		close(file);
		printf("Error writing to file\n");
		return 5;
	}
	
	// Remove the mapping
	if(munmap(map, SIZE-1) == -1)
	{
		close(file);
		printf("Error unmapping the file\n");
		return 6;
	}
	
	printf("Writing succeeded!\n");
	close(file);
	return 0;
}
