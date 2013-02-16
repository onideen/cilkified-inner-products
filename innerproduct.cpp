/*
Homework 4 : Cilkified Inner Products.
Team member 1 : Arne Bjune
Team member 2 : Vegar Engen
*/

#include <cilk.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <numeric>

#include "functions.h"

// Function declarations
void fill_arrays(int *a, int *b, int n);

using namespace std;

// String to display results
char result[][15] = {"matched","did not match"};

int cilk_main(int argc, char **argv)
{
	unsigned int n;

	// Size calculation
	if(argc >1){
		n = (unsigned int)atoi(argv[1]);
	}else{
		n = 1000000;
	}

	// Array allocation	
	int *a,*b;
	a = (int *)malloc(sizeof(int)*n);
	b = (int *)malloc(sizeof(int)*n);

	int loop_result, rec_result, hyper_result, ref_result; 
//	int time1,time2,time3,time4;
	struct timezone zone;
	struct time1, time2;
	// Initialize arrays
	fill_arrays(a,b,n);
	
	// Compute inner product for each method\
	gettimeofday(&time1,&zone);
	rec_result = rec_cilkified(a,b,n);
	gettimeofday(&time2,&zone);
	printf("Time :%i \n", time2.tv_usec - time1.tv_usec);
	loop_result = loop_cilkified(a,b,n);
	hyper_result = hyperobject_cilkified(a,b,n);
	
	// Compute inner product using library function	
	ref_result = std::inner_product(a,a+n,b,0);

	printf("Result from standard library function : %d\n",ref_result);
	printf("Recursive result %s\n",result[rec_result != ref_result]);
	printf("Loop result %s\n",result[loop_result != ref_result]);
	printf("Hyperobject result %s\n",result[hyper_result != ref_result]);

	return 0;

}

void fill_arrays(int *a, int *b, int n)
{
	int i;
	for(i = 0 ; i < n; i++)
	{
		a[i] = 1;	
		b[i] = 3;
	}
}

