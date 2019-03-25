#include <stdio.h>
#include <stdlib.h>


//The structure datatype to hold info of each matrix.
typedef struct Matrix
{
	int r,c;
	int** MatPtr;

}Matrix;


void initMatrix(Matrix* A)
{
	// A->r = r;
	// A->c = c;
	// A->MatPtr = NULL;

	printf("Enter no. of rows and columns: \n");
	scanf("%d %d", &A->r, &A->c);

	A->MatPtr = (int **) malloc (sizeof(int **)*(A->r));


	for (int i = 0; i < A->r; i++)
		A->MatPtr[i] = (int *) malloc(sizeof(int)*A->c);
}



void inputMatrix(Matrix* A)
{
	
	for (int i = 0; i < A->r; i++)
	{
		//printf("Enter row %d: \n", i + 1);

		for (int j = 0; j < A->c; j++)
		{
			scanf("%d", &A->MatPtr[i][j]);
		}
	}

	printf("Finished taking input for matrix. \n");

}

void printMatrix(Matrix A)
{

	for (int i = 0; i< A.r; i++)
	{
		for(int j = 0; j< A.c; j++)
			printf("%d ", A.MatPtr[i][j]);

		printf("\n");
	}
}


void delMatrix(Matrix A)
{
	for(int i = 0; i < A.r; i++)
		free(A.MatPtr[i]);

	free(A.MatPtr);
}



void addMatrices(Matrix* A, Matrix* B)
{

	if(!((A->r == B->r) && (A->c == B->c)))
		printf("Sizes don't match.\n");


	else
	{
		Matrix C;
		C.r = A->r;
		C.c = A->c;
		
		C.MatPtr = (int **) malloc (sizeof(int **)*(C.r));

		for (int i = 0; i < A->r; i++)
			C.MatPtr[i] = (int *) malloc(sizeof(int)*(C.c));


		for (int i = 0; i< A->r; i++)
		{
			for (int j= 0; j< A->c; j++)
				C.MatPtr[i][j] = A->MatPtr[i][j] + B->MatPtr[i][j];
		}

		printMatrix(C);
		delMatrix(C);

	}

}


void multiplyMatrices(Matrix* A, Matrix* B)
{

}


int main()
{
	Matrix a1, b1;

	initMatrix(&a1);
	initMatrix(&b1);
	//initMatrix(&c1);

	//printMatrix(c1);

	printf("Enter mat 1: \n");
	inputMatrix(&a1);
	printf("Enter mat 2: \n");
	inputMatrix(&b1);


	addMatrices(&a1, &b1);


	delMatrix(a1);
	delMatrix(b1);


	//printMatrix(a1);
	//printMatrix(b1);

	//printMatrix(c1);
	//printMatrix(a1);

	return 0;
}