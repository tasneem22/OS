#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N,i;
	scanf("%d",&N);

	int *arr = (int*)malloc(N * sizeof(int));

	for(i=0; i<N; i++)
		arr[i] = i;

	printf("The Array values are:\n");

	for(i=0; i<N; i++)
		printf("%d ", arr[i]);

	free(arr);

	return 0;
}
