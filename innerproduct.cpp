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
#include <time.h>

#include "functions.h"
#include <sys/time.h>

// Function declarations
void fill_arrays(int *a, int *b, int n);
long long elapsed_nseconds();
double elapsed_seconds();

using namespace std;

// String to display results
char result[][15] = {"matched","did not match"};

int cilk_main(int argc, char **argv)
{
	unsigned int n, i;
	int iterations;

	//struct timespec res;
	double start, end;
	double rec_time, loop_time, hyper_time;
	//clock_getres(CLOCK_MONOTONIC, &res);

	// Size calculation
	if(argc >1){
		n = (unsigned int)atoi(argv[1]);
	}else{
		n = 1000000;
	}

	if(argc > 2){
		iterations = atoi(argv[2]);
	}else {
		iterations = 1000;
	}

	// Array allocation	
	int *a,*b;
	a = (int *)malloc(sizeof(int)*n);
	b = (int *)malloc(sizeof(int)*n);

	int loop_result, rec_result, hyper_result, ref_result; 

	fill_arrays(a,b,n);
	
	// Compute inner product for each method\
	start = elapsed_seconds();
	start = elapsed_seconds();

	for (i = 0; i < iterations; ++i) {
		rec_result = rec_cilkified(a,b,n);
	}
	end = elapsed_seconds();

	rec_time = end-start;

	start = elapsed_seconds();
	for (i = 0; i < iterations; ++i) {
		loop_result = loop_cilkified(a,b,n);
	}
	end = elapsed_seconds();

	loop_time = end-start;

	start = elapsed_seconds();

	for (i = 0; i < iterations; ++i) {
		hyper_result = hyperobject_cilkified(a,b,n);
	}
	end = elapsed_seconds();

	hyper_time = end-start;

	printf("%f, %f, %f\n", rec_time, loop_time, hyper_time);

	// Compute inner product using library function	
	//ref_result = std::inner_product(a,a+n,b,0);

	//printf("Result from standard library function : %d\n",ref_result);
	//printf("Recursive result %s\n",result[rec_result != ref_result]);
	//printf("Loop result %s\n",result[loop_result != ref_result]);
	//printf("Hyperobject result %s\n",result[hyper_result != ref_result]);

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


long long elapsed_nseconds() {
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	long long time1 = ts.tv_sec * 1000000000 + ts.tv_nsec;

	return time1;
}

double elapsed_seconds()
{
  struct timeval tv;
  struct timezone tz;
  gettimeofday(&tv, &tz);
  return (double)tv.tv_sec + (double)tv.tv_usec/1000000.0;
}

