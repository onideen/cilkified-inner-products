#include "functions.h"

int rec_cilkified(int *a,int *b,unsigned int n)
{
	
	return 1;
}

int loop_cilkified(int *a,int *b,unsigned int n)
{
	int i, sum;
	for(i = 0; i <n; i++){
		//printf("%s\n", );
		sum = sum + a[n]*b[n];
	}
	printf("Sum %i\n", sum);
	return sum;
}

int hyperobject_cilkified(int *a,int *b,unsigned int n)
{
	return 1;
}

