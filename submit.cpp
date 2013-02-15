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
#include <math.h>

#include "functions.h"

#define COARSENESS 1000

int rec_cilkified(int *a,int *b,unsigned int n)
{


	if ( n == 1) return a[0]*b[0];
	else {

		int *leftA = a;
		int *rightA = a + (int)ceil(n/2);
		
		int *leftB = b;
		int *rightB = b + (int)ceil(n/2);
		
		int sumLeft, sumRight;
		
		sumLeft = cilk_spawn rec_cilkified(leftA, leftB, ceil(n/2)); 
		sumRight = cilk_spawn rec_cilkified(rightA, rightB, n-ceil(n/2));

		cilk_sync;
		return sumRight+sumLeft;
	}
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

