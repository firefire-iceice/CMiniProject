#include<stdlib.h>
#include<stdio.h>
#include<math.h>


Matrix floorMat(Matrix mat)
{
    Matrix fmat;
    initialiseZero(&fmat, mat.r, mat.c);
    for(int i=0;i<mat.r;i++)
    {
        for(int j=0;j<mat.c;j++)
        {
            fmat.MatPtr[i][j] = floorf(mat.MatPtr[i][j]);
        }
    }
    return fmat;
}


Matrix powMat(Matrix mat, float p)
{
    Matrix pmat;
    initialiseZero(&pmat, mat.r, mat.c);
    for(int i=0;i<mat.r;i++)
    {
        for(int j=0;j<mat.c;j++)
        {
            pmat.MatPtr[i][j] = powf(mat.MatPtr[i][j], p);
        }
    }
    return pmat;
}


Matrix absMat(Matrix mat)
{
    Matrix amat;
    initialiseZero(&amat, mat.r, mat.c);
    for(int i=0;i<mat.r;i++)
    {
        for(int j=0;j<mat.c;j++)
        {
            amat.MatPtr[i][j] = fabs(mat.MatPtr[i][j]);
        }
    }
    return amat;
}

Matrix logMat(Matrix mat)
{
	Matrix logmat;
	initialiseZero(&logmat,mat.r,mat.c);
	int flag=0;
	for (int i=0;i<mat.r;i++)
	{
		for(int j=0;j<mat.c;j++)
		{
			if(mat.MatPtr[i][j]<=0)
            {
				flag=1;
            }
		}
	}
	
    if (flag!=1)
	{
		for (int i=0;i<mat.r;i++)
		{
			for(int j=0;j<mat.c;j++)
			{
                logmat.MatPtr[i][j]=logf(mat.MatPtr[i][j]);
			}
		}
	}
	else
	{
		printf("zero or negative number found in the matrix, INVALID OPERATION");
	}
	return logmat;
}


Matrix ceilMat(Matrix mat)
{
    Matrix cmat;
    initialiseZero(&cmat, mat.r, mat.c);
    for(int i=0;i<mat.r;i++)
    {
        for(int j=0;j<mat.c;j++)
        {
            cmat.MatPtr[i][j] = ceilf(mat.MatPtr[i][j]);
        }
    }
    return cmat;
}


Matrix sinMat(Matrix mat)
{
    Matrix cmat;
    initialiseZero(&cmat, mat.r, mat.c);
    for(int i=0;i<mat.r;i++)
    {
        for(int j=0;j<mat.c;j++)
        {
            cmat.MatPtr[i][j] = sinf(mat.MatPtr[i][j]);
        }
    }
    return cmat;
}


Matrix cosMat(Matrix mat)
{
    Matrix cmat;
    initialiseZero(&cmat, mat.r, mat.c);
    for(int i=0;i<mat.r;i++)
    {
        for(int j=0;j<mat.c;j++)
        {
            cmat.MatPtr[i][j] = cosf(mat.MatPtr[i][j]);
        }
    }
    return cmat;
}


Matrix tanMat(Matrix mat)
{
    Matrix cmat;
    initialiseZero(&cmat, mat.r, mat.c);
    for(int i=0;i<mat.r;i++)
    {
        for(int j=0;j<mat.c;j++)
        {
            cmat.MatPtr[i][j] = tanf(mat.MatPtr[i][j]);
        }
    }
    return cmat;
}


Matrix alogMat(Matrix mat)
{
    Matrix cmat;
    initialiseZero(&cmat, mat.r, mat.c);
    for(int i=0;i<mat.r;i++)
    {
        for(int j=0;j<mat.c;j++)
        {
            cmat.MatPtr[i][j] = pow(mat.MatPtr[i][j],10);
        }
    }
    return cmat;
}

Matrix asinMat(Matrix mat)
{
    Matrix cmat;
    initialiseZero(&cmat, mat.r, mat.c);
    for(int i=0;i<mat.r;i++)
    {
        for(int j=0;j<mat.c;j++)
        {
            cmat.MatPtr[i][j] = asinf(mat.MatPtr[i][j]);
        }
    }
    return cmat;
}


Matrix acosMat(Matrix mat)
{
    Matrix cmat;
    initialiseZero(&cmat, mat.r, mat.c);
    for(int i=0;i<mat.r;i++)
    {
        for(int j=0;j<mat.c;j++)
        {
            cmat.MatPtr[i][j] = acosf(mat.MatPtr[i][j]);
        }
    }
    return cmat;
}



Matrix atanMat(Matrix mat)
{
    Matrix cmat;
    initialiseZero(&cmat, mat.r, mat.c);
    for(int i=0;i<mat.r;i++)
    {
        for(int j=0;j<mat.c;j++)
        {
            cmat.MatPtr[i][j] = atanf(mat.MatPtr[i][j]);
        }
    }
    return cmat;
}


Matrix addMatrices(Matrix A, Matrix B)
{
	//Adds two matrices and returns result.
	Matrix C;
	initialiseZero(&C, A.r, A.c);

	if(!((A.r == B.r) && (A.c == B.c)))
		printf("Sizes don't match.\n");

	else
	{
		for (int i = 0; i< A.r; i++)
		{
			for (int j= 0; j< A.c; j++)
				C.MatPtr[i][j] = A.MatPtr[i][j] + B.MatPtr[i][j];
		}

	}
	return C;

}

Matrix subMatrices(Matrix A, Matrix B)
{
	//Subtracts two matrices and returns result.
	Matrix C;
	initialiseZero(&C, A.r, A.c);

	if(!((A.r == B.r) && (A.c == B.c)))
		printf("Sizes don't match.\n");

	else
	{
		for (int i = 0; i< A.r; i++)
		{
			for (int j= 0; j< A.c; j++)
				C.MatPtr[i][j] = A.MatPtr[i][j] - B.MatPtr[i][j];
		}

	}
	return C;

}

Matrix mulMatrices(Matrix A, Matrix B)
{
	//Multiplies two matrices and returns the result.
	Matrix C;
	initialiseZero(&C, A.r, A.c);

	if(!((A.r == B.r) && (A.c == B.c)))
		printf("Sizes don't match.\n");

	else
	{
		for (int i = 0; i< A.r; i++)
		{
			for (int j= 0; j< A.c; j++)
				C.MatPtr[i][j] = A.MatPtr[i][j] * B.MatPtr[i][j];
		}

	}
	return C;

}

Matrix divMatrices(Matrix A, Matrix B)
{
	//Divides two 
	Matrix C;
	initialiseZero(&C, A.r, A.c);

	if(!((A.r == B.r) && (A.c == B.c)))
		printf("Sizes don't match.\n");

	else
	{
		for (int i = 0; i< A.r; i++)
		{
			for (int j= 0; j< A.c; j++)
			{

				if(B.MatPtr[i][j] == 0)
				{	
					printf("Division by zero error. Returning garbage matrix.\n");
					break;
				}

				else
				{
					C.MatPtr[i][j] = A.MatPtr[i][j] / B.MatPtr[i][j];
				}
				
			}
		}

	}
	return C;

}

Matrix matMul(Matrix A, Matrix B)
{
	//Does the matrix multiplication of two matrices and returns it.
	Matrix C;
	initialiseZero(&C, A.r, B.c);

	if(A.c != B.r)
		printf("Matrices cannot be multiplied. Returning garbage matrix.\n");

	else
	{
		for (int i = 0; i < C.r; i++)
		{
			for(int j = 0; j < C.c; j++)
			{
				float sum = 0.0;

				for(int k = 0; k < B.r; k++)
					sum += A.MatPtr[i][k] * B.	MatPtr[k][j];

				C.MatPtr[i][j] = sum;

			}
		}
	}

	return C;
}
