#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "MatrixLibrary.h"
#define Rand_upper 20

void initialiseZero(Matrix *a, int row, int column)
{
	a->r = row;																
	a->c = column;
	//First making the rows (basically an arrray of float pointers)
	a->MatPtr = calloc(a->r, sizeof(float *));
	//Adding elements to each row (0) 
	for (int i = 0; i < a->r; i++) a->MatPtr[i] = calloc(a->c, sizeof(float));

}

void initialiseOne(Matrix *a, int row, int column)
{
	a->r = row;
	a->c = column;
	//First making the rows (basically an arrray of float pointers)
	a->MatPtr = calloc(a->r, sizeof(float *));
	for (int i = 0; i < a->r; i++) {
		//Adding elements to each row (0) 
		a->MatPtr[i] = calloc(a->c, sizeof(float));
		//Making the elements 1.
		for (int j = 0; j < a->c; j++) a->MatPtr[i][j] = 1;
	}

}

void initialiseRandom(Matrix *a, int row, int column)
{
	a->r = row;
	a->c = column;
	//First making the rows (basically an arrray of float pointers)
	a->MatPtr = calloc(a->r, sizeof(float *));
	for (int i = 0; i < a->r; i++) {
		//Adding elements to each row (0) 
		a->MatPtr[i] = calloc(a->c, sizeof(float));
		//Assigning random numbers 
		for (int j = 0; j < a->c; j++) a->MatPtr[i][j] = rand()%Rand_upper;
	}
	//Include #include <time.h>
//		  #define Random_upper ()
//		  srand(time(NULL)) //In in the main function before calling the init_random function.
}

void printMatrix(Matrix n)
{
	for (int i = 0; i < n.r; i++)												
	{
		for (int j = 0; j < n.c; j++)												
		{
			printf("%.3f ", n.MatPtr[i][j]);
		}
		printf("\n");	
	}
}				



void readMatrix(Matrix a)
{
	for (int i = 0; i < a.r; i++)
	{
		for (int j = 0; j < a.c; j++)
		{
			scanf("%f", &a.MatPtr[i][j]);
		}
	}
}

Matrix identity(int n)
{
    Matrix iden;
    initialiseZero(&iden, n, n);
    for(int i=0;i<n;i++)
    {
        iden.MatPtr[i][i] = 1;
    }
	return iden;
}


Matrix vector(float a, float b, float c)
{
	Matrix mat;
	initialiseZero(&mat, 3, 1);
	mat.MatPtr[0][0] = a;
	mat.MatPtr[1][0] = b;
	mat.MatPtr[2][0] = c;
	return mat;
}


void delMatrix(Matrix A)
{
	for(int i = 0; i < A.r; i++)
		free(A.MatPtr[i]);

	free(A.MatPtr);
}

