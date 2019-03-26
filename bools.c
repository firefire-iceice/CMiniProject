#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "MatrixLibrary.h"


bool isSymmetric(Matrix a)
{
	if (compareMatrices(a, transpose(a)))
	{
		return true;
	} else {
		return false;
	}
}

bool isAntisymmetric(Matrix a)
{
	if (compareMatrices(a, scalarMultiply(transpose(a), -1)))
	{
		return true;
	} return false;
}

bool isInvolutary(Matrix a)
{
	if (compareMatrices(mulMatrices(a, a), identity(a.r)))
	{
		return true;
	} return false;
}
bool compareMatrices(Matrix a, Matrix b)
{
	if (a.r == b.r && a.c == b.c)
	{
		for (int i = 0; i < a.r; i++)
		{
			for (int j = 0; j < a.c; j++)
			{
				if (a.MatPtr[i][j] != b.MatPtr[i][j])
				{
					return false;
				}
			}
		}
		return true;
	} else return false;
}

bool isIdempotent(Matrix a)
{
	if (compareMatrices(matMul(a,a), a))
	{
		return true;
	} else return false;
}