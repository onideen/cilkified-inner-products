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

#define COARSENESS 1000

int rec_cilkified(int *a,int *b,unsigned int n)
{
	printf("A is %d long\n", sizeof a /sizeof(int));
	return 1;
}

int loop_cilkified(int *a,int *b,unsigned int n)
{
	int i,c = COARSENESS, sum = 0;
	int *temp, *k;
	temp = (int *)malloc(sizeof(int)*(n/c));
	k = (int *)malloc(sizeof(int)*(n/c));
	
	cilk_for(int j=0; j< n / c ;j++){
		for(k[j] = 0; k[j] < c; k[j]++){
			temp[j] += a[k[j] + j* c]*b[k[j] +j*c];
		}
	}

	for(i =0; i<n/c; i++){
		sum += temp[i];
	}
	return sum;
}

int hyperobject_cilkified(int *a,int *b,unsigned int n)
{
	return 1;
}

